// AudioStreamingModule.cpp : Defines the exported functions for the DLL application.
//

#include "PlaybackStream.h"

/*
* This module uses StreamBuffer module to function.
*
* This consists of 1. Audio Playback and 2. UDP receiving server.
*/

PlaybackEngine::PlaybackEngine(PlaybackEnginePreset ap)
{
	this->buffer = ap.buffer;
	this->bufferFrames = ap.bufferFrames;
	this->sampleRate = ap.sampleRate;

	this->setupPlaybackStream();
}

int udp(void* outputBuffer, void* /*inputBuffer*/, unsigned int nBufferFrames,
	double /*streamTime*/, RtAudioStreamStatus status, void* userData) {

	return reinterpret_cast<PlaybackEngine*>(userData)->getUDPData(outputBuffer, nBufferFrames, status);
}

void errorCallback(RtAudioError::Type type, const std::string& errorText)
{
	// This example error handling function does exactly the same thing
	// as the embedded RtAudio::error() function.
	std::cout << "in errorCallback" << std::endl;
	if (type == RtAudioError::WARNING)
		std::cerr << '\n' << errorText << "\n\n";
	else if (type != RtAudioError::WARNING)
		throw(RtAudioError(errorText, type));
}
int PlaybackEngine::getUDPData(void* outputBuffer, unsigned int nBufferFrames, RtAudioStreamStatus status) {

	postProcessing(reinterpret_cast<short*>(outputBuffer), buffer->getReaderPointer(), nBufferFrames);

	return 0;
}

void PlaybackEngine::postProcessing(int16_t * outputBuffer, int16_t * udpBuffer, size_t nBufferFrames)
{
	for (size_t i = 0; i < nBufferFrames * 2; i += 2) {
		outputBufferPreviousI = (int)(outputBufferPreviousI + (alpha * (udpBuffer[i / 2] - outputBufferPreviousI)));
		int temp = outputBufferPreviousI << 2;
		//temp = udpBuffer[i/2];
		//printf("%d ", temp);
		if (temp > SHRT_MAX) {
			outputBuffer[i] = SHRT_MAX;
			outputBuffer[i + 1] = SHRT_MAX;
		}
		else if (temp < SHRT_MIN) {
			outputBuffer[i] = SHRT_MIN;
			outputBuffer[i + 1] = SHRT_MIN;
		}
		else {
			outputBuffer[i] = temp;
			outputBuffer[i + 1] = temp;
		}
	}
}
void PlaybackEngine::setupPlaybackStream()
{
	RtAudio::StreamOptions sOptions;
	sOptions.flags = RTAUDIO_MINIMIZE_LATENCY;

	RtAudio::StreamParameters oParams;
	oParams.deviceId = dac.getDefaultOutputDevice();
	oParams.nChannels = 2;
	oParams.firstChannel = 0;

	dac.showWarnings(true);

	try {
		dac.openStream(&oParams, NULL, RTAUDIO_SINT16, sampleRate, &bufferFrames, &udp, this, &sOptions, &errorCallback);
	}
	catch (RtAudioError * e) {
		e->printMessage();
		std::cout << "Stream is wrong" << std::endl;
	}
}

bool PlaybackEngine::isStreamOpen()
{
	return dac.isStreamOpen();
}
bool PlaybackEngine::startStreaming()
{
	if (this->isStreamOpen()) {
		try {
			dac.startStream();
		}
		catch (RtAudioError & e) {
			e.printMessage();
			return false;
		}
		return true;
	}
	return false;
}
bool PlaybackEngine::stopStreaming()
{
	if (dac.isStreamRunning()) {
		try {
			dac.stopStream();
		}
		catch (RtAudioError & r) {
			r.printMessage();
			return false;
		}
		return true;
	}
	return false;
}
