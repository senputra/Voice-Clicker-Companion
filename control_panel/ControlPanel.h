#pragma once
#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

// #ifdef CONTROLPANEL_EXPORTS
// #define CONTROLPANEL_API __declspec(dllexport)
// #else 
// #define CONTROLPANEL_API __declspec(dllimport)
// #endif

#include "SocketHelper.h"
#include "../microphone/Microphone.h"
#include "../zero_config/ServiceDiscovery.h"
#include "../remote_input/RemoteInput.h"

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

	Microphone* microphone = nullptr;
	ServiceDiscovery* serviceDiscovery = nullptr;
	RemoteInput* remoteInput = nullptr;

	boost::asio::io_context io_context;

	SocketHelper* socket = nullptr;

	int _audioPort = -1;
	int _socketPort = -1;

	void getPorts();

};
#endif