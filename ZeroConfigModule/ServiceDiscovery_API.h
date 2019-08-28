#pragma once 

#ifndef __SERVICE_DISCOVERY__
#define __SERVICE_DISCOVERY__

// reference additional headers your program requires here

#include "Poco/DNSSD/DNSSDResponder.h"
#if POCO_OS == POCO_OS_LINUX && !defined(POCO_DNSSD_USE_BONJOUR)
#include "Poco/DNSSD/Avahi/Avahi.h"
#else
#include "Poco/DNSSD/Bonjour/Bonjour.h"
#endif
#include "Poco/Delegate.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace Poco::DNSSD;
using namespace std;
class ServiceDiscoveryAPI {
public:
	struct ServiceDiscoveryParams {
		int port;
		string serviceName; // Voice CLicker
		string serviceProtocol; // "_voiceClicker._udp"
		vector<string> props;
		int numOfProps;
	};
public:
	ServiceDiscoveryAPI(ServiceDiscoveryParams params);
	~ServiceDiscoveryAPI();
	void advertise();
	void addProps(std::string key, std::string value);
	void discardAdvertise();
	void discardAdvertise(Poco::DNSSD::ServiceHandle serviceHandle);

private:
	DNSSDResponder* dnssdResponder;
	Service::Properties *_props;

	ServiceHandle _serviceHandler;

	string _serviceName;
	string _serviceProtocol;
	int _port = 0;
	int _numOfProps = 0;
};

#endif