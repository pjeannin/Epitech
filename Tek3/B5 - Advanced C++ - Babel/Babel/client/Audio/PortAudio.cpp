/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** PortAudio.cpp
*/

#include "PortAudio.hpp"

Babel::Client::Audio::PortAudioException::PortAudioException(std::string const &msg) : _msg(std::string("PortAudioError: ") + msg)
{
    std::cout << _msg << std::endl;
}

const char *Babel::Client::Audio::PortAudioException::what() const throw()
{
    return _msg.c_str();
}

Babel::Client::Audio::PortAudio::PortAudio() :
        _recording(false), _streaming(false), _channel(1),
        _bufferSize(480), _sampleRate(48000), _stream(nullptr)
{
    if (Pa_Initialize() != paNoError)
        throw PortAudioException("Failed to initialize");
}

Babel::Client::Audio::PortAudio::~PortAudio()
{
    closeStream();
    Pa_Terminate();
}

std::vector<uint16_t> Babel::Client::Audio::PortAudio::getRecord()
{
    long streamReadAvailable = Pa_GetStreamReadAvailable(_stream);
    std::vector<uint16_t> record(_bufferSize);

    if (Pa_ReadStream(_stream, record.data(), streamReadAvailable < (long)_bufferSize ? (unsigned long)streamReadAvailable : _bufferSize) != paNoError)
        restartStream();
    return record;
}

void Babel::Client::Audio::PortAudio::playRecord(std::vector<uint16_t> record)
{
    while (Pa_GetStreamWriteAvailable(_stream) < (long)record.size());
    if (Pa_WriteStream(_stream, record.data(), (unsigned long)record.size()) != paNoError) {
        //restartStream();
        ;
    }
}

void Babel::Client::Audio::PortAudio::restartStream()
{
    closeStream();
    startStream();
    startRecording();
}

void Babel::Client::Audio::PortAudio::startStream()
{
    PaError paErr = Pa_OpenDefaultStream(
            &_stream, _channel, _channel, paInt16, _sampleRate,
            _bufferSize, nullptr, nullptr);
    if (paErr != paNoError)
        throwPortAudioError(paErr);
    _streaming = true;
}

void Babel::Client::Audio::PortAudio::stopStream()
{
    PaError paErr = Pa_CloseStream(_stream);
    if (paErr != paNoError)
        throwPortAudioError(paErr);
    _streaming = false;
}

void Babel::Client::Audio::PortAudio::startRecording()
{
    PaError paErr = Pa_StartStream(_stream);
    if (paErr != paNoError)
        throwPortAudioError(paErr);
    _recording = true;
}

void Babel::Client::Audio::PortAudio::stopRecording()
{
    PaError paErr = Pa_StopStream(_stream);
    if (paErr != paNoError)
        throwPortAudioError(paErr);
    _recording = false;
}

void Babel::Client::Audio::PortAudio::closeStream()
{
    if (_recording)
        stopRecording();
    if (_streaming)
        stopStream();
}

uint32_t Babel::Client::Audio::PortAudio::getChannel() const
{
    return _channel;
}

void Babel::Client::Audio::PortAudio::setChannel(uint32_t channel)
{
    _channel = channel;
}

uint32_t Babel::Client::Audio::PortAudio::getBufferSize() const
{
    return _bufferSize;
}

void Babel::Client::Audio::PortAudio::setBufferSize(uint32_t bufferSize)
{
    _bufferSize = bufferSize;
}

uint32_t Babel::Client::Audio::PortAudio::getSampleRate() const
{
    return _sampleRate;
}

void Babel::Client::Audio::PortAudio::setSampleRate(uint32_t sampleRate)
{
    _sampleRate = sampleRate;
}

void Babel::Client::Audio::PortAudio::throwPortAudioError(PaError paErr) const
{}