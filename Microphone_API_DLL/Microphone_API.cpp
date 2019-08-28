// All the functions needed to use the microphone is put here
#include "Microphone_API.h"

MicrophoneAPI::MicrophoneAPI(MicrophoneAPIParams params)
{
	_bufferFrames = params.bufferFrames;
	_sampleRate = params.sampleRate;
	_numberOfChunk = params.numberOfChunk;
}

bool MicrophoneAPI::isReady()
{
	if ((_bufferFrames == 0) || (_sampleRate == 0) || (_buffer == nullptr) || (_networkStream == nullptr) || (_playbackEngine == nullptr) || (_numberOfChunk == 0)) {
		return false;
	}
	return true;
}

int MicrophoneAPI::getLocalport() {
	if (isReady()) {
		return _networkStream->getLocalPort();
	}
	return 0;
}
void MicrophoneAPI::startMicrophone()
{ 
	boost::asio::io_context _io_context;
	_buffer = new StreamBuffer(_bufferFrames, _numberOfChunk);

	startNetworkThread();
	startPlaybackThread();
}
void MicrophoneAPI::stopMicrophone()
{
	if (isReady()) {
		lock_guard<mutex> lk(audioEngineMutex);
		cv.notify_one();
		printf("Audio thread stopped;");

		_io_context.stop();
	}
}

void MicrophoneAPI::startNetworkThread()
{

	thread([this] {
		try {
			_networkStream = new NetworkStream(_io_context, _buffer, _bufferFrames * sizeof(short), 0);
			printf("\nAudio Stream server is up at port: %d\n", _networkStream->getLocalPort());
			_io_context.run();
			printf("io_context is running\n");
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		}).detach();
}

void MicrophoneAPI::startPlaybackThread() 
{
	thread([this] {
		// Check if the audio stream is ready

		PlaybackEngine::PlaybackEnginePreset presets;
		presets.buffer = _buffer;
		presets.bufferFrames = _bufferFrames;
		presets.sampleRate = _sampleRate;
		_playbackEngine = new PlaybackEngine(presets);

		if (_playbackEngine->isStreamOpen())
		{
			printf("Stream is open\nStarting audio Stream");
			_playbackEngine->startStreaming();
		}
		else
		{
			return;
		}

		// wait until the lk(m) is released
		unique_lock<mutex> lk(audioEngineMutex);
		cv.wait(lk);

		// Lock is unlocked. Time to Stop the audio stream
		printf("Stream is open\nStarting audio Stream");
		_playbackEngine->stopStreaming();
		return;
		exit(0);
		}).detach();

}