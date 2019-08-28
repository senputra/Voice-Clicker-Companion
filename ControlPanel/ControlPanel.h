#pragma once
#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

// #ifdef CONTROLPANEL_EXPORTS
// #define CONTROLPANEL_API __declspec(dllexport)
// #else 
// #define CONTROLPANEL_API __declspec(dllimport)
// #endif

#include "SocketHelper.h"
#include "../Microphone_API_DLL/Microphone_API.h"
#include "../ZeroConfigModule/ServiceDiscovery_API.h"
#include "../RemoteInput_API_DLL/RemoteInput_API.h"

class ControlPanel : InterfaceInputSocketListener {
public:
	ControlPanel();

	void startMicrophone();
	void stopMicrophone();

	void startServiceAdvertising();
	void stopServiceAdvertising();

	// a virtual function from InterfaceInputSocketListener
	void OnDataReceived(uint8_t* data);
private:
	void setupSocket();
	void setupServiceAdvertising();
	void setupMicrophone();
	void setupRemoteInput();

	MicrophoneAPI* microphone = nullptr;
	ServiceDiscoveryAPI* serviceDiscovery = nullptr;
	RemoteInputAPI* remoteInput = nullptr;

	boost::asio::io_context io_context;

	SocketHelper* socket = nullptr;

	int _audioPort = -1;
	int _socketPort = -1;

	void getPorts();

};
#endif