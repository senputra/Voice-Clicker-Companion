// StreamBuffer.cpp : Defines the exported functions for the DLL application.
//

#include "StreamBuffer.h" 

StreamBuffer::StreamBuffer(uint32_t cs, uint32_t noc)
{
	writerCounter = 0;
	readerCounter = 0;

	chunkSize = cs;
	chunkSizeInBytes = chunkSize * sizeof(int16_t);
	numberOfChunk = noc;
	totalCapacity = chunkSize * numberOfChunk; // Number of int16_t  that can be stored
	totalChunk = numberOfChunk * 2; // Added exta chunk for overflow.

	buffer = new int16_t*[totalChunk];
	for (size_t i = 0; i < totalChunk; ++i) {
		buffer[i] = new int16_t[chunkSize];
		memset(buffer[i], 0, chunkSizeInBytes);
	}

	/* Stall buffer */
	stallBuffer = new int16_t[chunkSize];
	memset(stallBuffer, 0, chunkSizeInBytes);

	printf("number of Chunk %d", numberOfChunk);
}

StreamBuffer::~StreamBuffer()
{
	// Swap the assigned memory with nothing.
	// Dumping the data
	for (size_t i = 0; i < totalChunk; ++i) {
		delete buffer[i];
	}
	delete buffer;
	delete stallBuffer;
}

int16_t* StreamBuffer::getWriterPointer() {
	if (writerCounter == numberOfChunk) {
		writerCounter = 0;
		//printf(" \n");
	}
	//printf(" writer %d ", writerCounter);
	return buffer[writerCounter++];
}

int16_t* StreamBuffer::getReaderPointer() {
	/*if (writerCounter == readerCounter){
		printf("stall\n");
		return stallBuffer;
	}*/
	if (readerCounter == numberOfChunk) {
		readerCounter = 0;
		//printf(" \n");
	}
	//printf("listener %d ", readerCounter); 
	return buffer[readerCounter++];
}

