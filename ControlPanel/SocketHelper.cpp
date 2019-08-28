#include "SocketHelper.h"


void SocketHelper::handle_receive(const boost::system::error_code& error,
	std::size_t /*bytes_transferred*/)
{
	//std::cout << "received commmand" << std::endl;
	if (!error)
	{
		//printf("Receiveed command 2\n");
		_listener->OnDataReceived(_receivedData);
		start_receiving();
	}
}
SocketHelper::SocketHelper(boost::asio::io_context& io_context, InterfaceInputSocketListener* listener)
	: socket_(io_context, udp::endpoint(udp::v4(), 0)) {
	_listener = listener;
	_localPort = socket_.local_endpoint().port();
	_receivedData = new uint8_t[_dataSizeInBytes];
	memset(_receivedData, 0, _dataSizeInBytes);
	start_receiving();
}

void SocketHelper::start_receiving()
{
	//printf("Receiveed command 1\n");
	socket_.async_receive_from(
		boost::asio::buffer(_receivedData, _dataSizeInBytes), remote_endpoint_,
		boost::bind(&SocketHelper::handle_receive, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

int SocketHelper::getLocalPort()
{
	return _localPort;
}

SocketHelper::~SocketHelper() {
	delete(_receivedData);
	_receivedData = nullptr;
}
