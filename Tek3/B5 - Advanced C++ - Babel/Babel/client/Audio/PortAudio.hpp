/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** PortAudio.hpp
*/


#ifndef BABEL_PORTAUDIO_HPP
#define BABEL_PORTAUDIO_HPP

#include <portaudio.h>
#include <exception>
#include <string>
#include <vector>
#include <iostream>

namespace Babel::Client::Audio {
    class PortAudioException : std::exception {
        public:
            explicit PortAudioException(std::string const &msg);

            virtual const char *what() const throw();

        private:
            std::string const _msg;
    };

    class PortAudio {
        public:
            explicit PortAudio();

            ~PortAudio();

            std::vector<uint16_t> getRecord();

            void playRecord(
                    std::vector<uint16_t> record);

            void restartStream();

            void startStream();

            void stopStream();

            void startRecording();

            void stopRecording();

            void closeStream();

            uint32_t getChannel() const;

            void setChannel(uint32_t channel);

            uint32_t getBufferSize() const;

            void setBufferSize(uint32_t bufferSize);

            uint32_t getSampleRate() const;

            void setSampleRate(uint32_t sampleRate);

            void throwPortAudioError(PaError paErr) const;

        private:
            bool _recording;
            bool _streaming;
            uint32_t _channel;
            uint32_t _bufferSize;
            uint32_t _sampleRate;
            PaStream *_stream;
    };
}


#endif //BABEL_PORTAUDIO_HPP