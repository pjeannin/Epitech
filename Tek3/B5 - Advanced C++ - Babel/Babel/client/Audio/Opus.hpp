/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Opus.hpp
*/

#ifndef BABEL_OPUS_HPP
#define BABEL_OPUS_HPP

#include <opus/opus.h>
#include <exception>
#include <string>
#include <vector>
#include <iostream>

namespace Babel::Client::Audio {
    class OpusException : std::exception {
        public:
            explicit OpusException(std::string const &msg);

            virtual const char *what() const throw();

        private:
            std::string const _msg;
    };

    class Opus {
        public:
            explicit Opus(uint32_t const sampleRate, uint32_t const channel);

            ~Opus();

            std::vector<uint16_t> decode(std::vector<uint16_t> encoded) const;

            std::vector<uint16_t> encode(std::vector<uint16_t> sample) const;

        private:
            OpusEncoder *_encoder;
            OpusDecoder *_decoder;
    };
}


#endif //BABEL_OPUS_HPP
