#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include <stdint.h>
#include <thread>
#include <iostream>
using namespace std;
//TODO:: Change the interface type to event type
class InterfaceInputSocketListener {
public:
	virtual void OnDataReceived(uint8_t* data) = 0;
};

using boost::asio::ip::udp;
class SocketHelper {
public:
	SocketHelper(boost::asio::io_context& io_context, InterfaceInputSocketListener* listener);
	int getLocalPort();
	~SocketHelper();

private:
	void start_receiving();
	void handle_receive(const boost::system::error_code& error,
		std::size_t /*bytes_transferred*/);

	int _localPort = 0;

	const int _dataSizeInBytes = 8;
	uint8_t* _receivedData;

	udp::socket socket_;
	udp::endpoint remote_endpoint_;
	InterfaceInputSocketListener* _listener = nullptr;

};