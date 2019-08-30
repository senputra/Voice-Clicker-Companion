#pragma once


#ifndef STREAMBUFFER_H
#define STREAMBUFFER_H

#include <stdint.h>
#include <iostream>

using namespace std;
// TODO :: for current time, I will export the whole class
class StreamBuffer {
public:
	StreamBuffer(uint32_t chunkSize, uint32_t numberOfChunk); // Create a buffer of a chunkSize times the numberOfChunks
	~StreamBuffer();

	int16_t* getReaderPointer();
	int16_t* getWriterPointer();

private:
	uint32_t chunkSize, chunkSizeInBytes, numberOfChunk, totalCapacity, totalChunk;

	int16_t **buffer;
	int16_t *stallBuffer;
	uint16_t readerCounter = 0;
	uint16_t writerCounter = 0;

};

#endif // STREAMBUFFER_H
