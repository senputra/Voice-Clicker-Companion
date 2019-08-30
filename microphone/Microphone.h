#pragma once
#ifndef MICROPHONE_H
#define MICROPHONE_H


#include "StreamBuffer.h"
#include "NetworkStream.h"
#include "PlaybackStream.h"

class Microphone {
public:
	struct MicrophoneParams {
		size_t bufferFrames; // Number of pieces in a buffer / chunk
		size_t sampleRate;

		uint32_t numberOfChunk;
	};

public:
	Microphone(MicrophoneParams params);

	bool isReady();
	int getLocalport();
	void startMicrophone();
	void stopMicrophone();

private:
	NetworkStream* _networkStream = nullptr;
	PlaybackEngine* _playbackEngine = nullptr;
	StreamBuffer* _buffer = nullptr;

	size_t _bufferFrames = 0;
	size_t _sampleRate = 0;

	uint32_t _numberOfChunk = 0;

	boost::asio::io_context _io_context;

	mutex audioEngineMutex;
	condition_variable cv;

private:
	void startNetworkThread();
	void startPlaybackThread();
};

#endif