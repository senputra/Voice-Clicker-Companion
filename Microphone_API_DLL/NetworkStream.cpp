// AudioStreamingServerModule.cpp : Defines the exported functions for the DLL application.
//
#include "NetworkStream.h"

NetworkStream::NetworkStream(boost::asio::io_context& io_context, StreamBuffer* buffer, uint32_t sizeOfAChunkInBytes, int port)
	: socket_(io_context, udp::endpoint(udp::v4(), port)) {

	bufferSizeInBytes = sizeOfAChunkInBytes;
	buffer_ = buffer;
	_isReady = true;
	start_receive();
}

NetworkStream::~NetworkStream()
{
}

int NetworkStream::getLocalPort()
{
	if (_isReady) return socket_.local_endpoint().port();
	return 0;
}

void NetworkStream::start_receive()
{
	//printf("Start receiving at port");
	socket_.async_receive_from(
		boost::asio::buffer(reinterpret_cast<char*>(buffer_->getWriterPointer()), bufferSizeInBytes), remote_endpoint_,
		boost::bind(&NetworkStream::handle_receive, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void NetworkStream::handle_receive(const boost::system::error_code& error,
	std::size_t /*bytes_transferred*/)
{
	if (!error)
	{
		start_receive();
	}
	else {
		printf("%d", error.value());
	}
}

void NetworkStream::handle_send(boost::shared_ptr<std::string> /*message*/,
	const boost::system::error_code& /*error*/,
	std::size_t /*bytes_transferred*/)
{
}