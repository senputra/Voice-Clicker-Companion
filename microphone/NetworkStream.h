#ifndef NETWORKSTREAM_H
#define NETWORKSTREAM_H


#include "StreamBuffer.h"
#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include <iostream>
#include <stdint.h>

using boost::asio::ip::udp;

class NetworkStream
{
public:
	NetworkStream(boost::asio::io_context& io_context, StreamBuffer* buffer, uint32_t sizeOfChunkInBytes, int port);
	~NetworkStream();

	int getLocalPort();

private:
	void start_receive();

	void handle_receive(const boost::system::error_code& error,
		std::size_t /*bytes_transferred*/);

	void handle_send(boost::shared_ptr<std::string> /*message*/,
		const boost::system::error_code& /*error*/,
		std::size_t /*bytes_transferred*/);

	udp::socket socket_;
	udp::endpoint remote_endpoint_;
	StreamBuffer* buffer_;

	size_t bufferSizeInBytes = 0;
	
	bool _isReady = false;
};

#endif // !AUDIOSTREAMINGSERVERMODULE_H
