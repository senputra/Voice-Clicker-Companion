// ZeroConfigModule.cpp : Defines the exported functions for the DLL application.
//
#include "ServiceDiscovery_API.h"

void onError(const void* sender, const DNSSDResponder::ErrorEventArgs& args)
{
	std::cerr
		<< "Service registration failed: "
		<< args.error.message()
		<< " (" << args.error.code() << ")"
		<< std::endl;
}

ServiceDiscoveryAPI::ServiceDiscoveryAPI(ServiceDiscoveryParams params)
{
	initializeDNSSD();
	dnssdResponder = new DNSSDResponder;
	dnssdResponder->start(); // Starting the service discovery service

	_serviceName = params.serviceName;
	_port = params.port;
	_numOfProps = params.numOfProps;
	_serviceProtocol = params.serviceProtocol;
	_props = new Service::Properties;

	for (int i = 0; i < _numOfProps * 2; ++i, ++i) {
		_props->add(params.props[i], params.props[i + 1]);
	}

}
ServiceDiscoveryAPI::~ServiceDiscoveryAPI()
{
	if (dnssdResponder != nullptr) {
		delete dnssdResponder;
		dnssdResponder = nullptr;
	}

	if (_props != nullptr) {
		delete _props;
		_props = nullptr;
	}
}

void ServiceDiscoveryAPI::advertise()
{
	try {
		//Service service(SERVICE_TYPE, port, *props);
		printf("Service Name: %s. Port: %d", _serviceName.c_str(), _port);
		Service service(0, _serviceName, "", _serviceProtocol, "", "", _port, *_props);
		_serviceHandler = dnssdResponder->registerService(service);
		dnssdResponder->serviceRegistrationFailed += Poco::delegate(onError);
		return;
	}
	catch (Poco::Exception & e) {
		std::cout << e.what();
	}

}

void ServiceDiscoveryAPI::discardAdvertise()
{
	dnssdResponder->unregisterService(_serviceHandler);
}

void ServiceDiscoveryAPI::discardAdvertise(ServiceHandle serviceHandle)
{
	dnssdResponder->unregisterService(serviceHandle);
}

void ServiceDiscoveryAPI::addProps(std::string key, std::string value) {
	_props->add(key, value);
}

