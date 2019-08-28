// This class will provide functions to control all the feature of apps.
/*
	Type of Input:
	1. From network => the network gonna send a signal and it will trigger an input which controls the software (the app itself Voice Clicker) or the device (through voice clicker);
	2. From user => user gonna press buttons that will call a function in Control Panel
*/
#include "ControlPanel.h"

ControlPanel::ControlPanel()
{
	setupMicrophone();
	setupSocket();
	setupRemoteInput();
}


void ControlPanel::setupSocket()
{
	thread([this] {
		try {
			socket = new SocketHelper(io_context, this);
			_socketPort = socket->getLocalPort();
			printf("\nInput Stream server is up at port: %d\n", _socketPort);
			io_context.run();
			printf("io_context is running\n");

		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		}).detach();
}

void ControlPanel::setupServiceAdvertising()
{
	getPorts();
	if (_audioPort - _socketPort == 0) {
		printf("cant do DNSSD. Ports are not ready yet");
		return;
	}
	vector<string> propv = {};
	propv.push_back("vc_audio");
	propv.push_back(to_string(_audioPort));
	propv.push_back("vc_input");
	propv.push_back(to_string(_socketPort));

	ServiceDiscoveryAPI::ServiceDiscoveryParams params;
	params.numOfProps = 2;
	params.port = 8080;
	params.serviceName = "Voice Clicker";
	params.serviceProtocol = "_vcHello._udp";
	params.props = propv;

	serviceDiscovery = new ServiceDiscoveryAPI(params); return;
}

void ControlPanel::setupMicrophone() {
	MicrophoneAPI::MicrophoneAPIParams params;
	params.bufferFrames = 256;
	params.numberOfChunk = 4;
	params.sampleRate = 48000;

	microphone = new MicrophoneAPI(params);
	return;
}

void ControlPanel::setupRemoteInput()
{
	remoteInput = new RemoteInputAPI();
}

void ControlPanel::getPorts()
{
	_audioPort = microphone->getLocalport();
	_socketPort = socket->getLocalPort();
}

void ControlPanel::startMicrophone() {

	microphone->startMicrophone();

	return;
}

void ControlPanel::stopMicrophone()
{
	if (microphone->isReady()) {
		microphone->stopMicrophone();
	}
}

void ControlPanel::startServiceAdvertising()
{
	setupServiceAdvertising();
	serviceDiscovery->advertise();
}

void ControlPanel::stopServiceAdvertising()
{
	serviceDiscovery->discardAdvertise();
}


// Listener
void ControlPanel::OnDataReceived(uint8_t* data)
{
	remoteInput->execute(data);
}
