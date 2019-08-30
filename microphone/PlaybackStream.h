#pragma once

#ifndef AUDIOSTREAMINGMODULE_H
#define AUDIOSTREAMINGMODULE_H

// Platform-dependent sleep routines.
#if defined( __WINDOWS_ASIO__ ) || defined( __WINDOWS_DS__ ) || defined( __WINDOWS_WASAPI__ )
#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants
#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

#include "StreamBuffer.h"
#include "./rtaudio/RtAudio.h"

class PlaybackEngine {
public:
	struct PlaybackEnginePreset {
		size_t bufferFrames;
		size_t sampleRate;
		StreamBuffer *buffer;
	};
public:
	PlaybackEngine (PlaybackEnginePreset ap);
	int getUDPData(void *outputBuffer, unsigned int nBufferFrames, RtAudioStreamStatus status);
	bool isStreamOpen();
	bool startStreaming();
	bool stopStreaming();

private:
	uint32_t bufferFrames = 256;
	size_t sampleRate = 48000;
	StreamBuffer *buffer = nullptr;

	RtAudio dac;

	double RC = 1.0 / (22000 * 2 * 3.14);
	double dt = 1.0 / 48000;
	double alpha = dt / (RC + dt);

	int outputBufferPreviousI = 0;

	void postProcessing(int16_t * outputBuffer, int16_t* udpBuffer, size_t nBufferFrames);
	void setupPlaybackStream();
};

#endif // !AUDIOSTREAMINGMODULE_H