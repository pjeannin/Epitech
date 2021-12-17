/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Opus.cpp
*/

#include "Opus.hpp"

Babel::Client::Audio::OpusException::OpusException(std::string const &msg) : _msg(std::string("OpusError: ") + msg)
{
    std::cout << _msg << std::endl;
}

const char *Babel::Client::Audio::OpusException::what() const throw()
{
    return _msg.c_str();
}

Babel::Client::Audio::Opus::Opus(uint32_t const sampleRate, uint32_t const channel) : _encoder(nullptr), _decoder(nullptr)
{
    int opusErr = 0;

    _encoder = opus_encoder_create(sampleRate, channel, OPUS_APPLICATION_VOIP, &opusErr);
    if (opusErr != OPUS_OK)
        throw OpusException("failed to create encoder");
    _decoder = opus_decoder_create(sampleRate, channel, &opusErr);
    if (opusErr != OPUS_OK)
        throw OpusException("failed to create decoder");
}

Babel::Client::Audio::Opus::~Opus()
{
    if (_encoder)
        opus_encoder_destroy(_encoder);
    if (_decoder)
        opus_decoder_destroy(_decoder);
}

std::vector<uint16_t> Babel::Client::Audio::Opus::decode(std::vector<uint16_t> encoded) const
{
    std::vector<uint16_t> decoded(encoded.size());

    if (opus_decode(_decoder, (unsigned char *)encoded.data(), (int)encoded.size(), (opus_int16 *)decoded.data(), (int)encoded.size(), 0) < 0)
        throw OpusException("failed to decode");
    return decoded;
}

std::vector<uint16_t> Babel::Client::Audio::Opus::encode(std::vector<uint16_t> sample) const
{
    std::vector<uint16_t> encoded(sample.size());

    if (opus_encode(_encoder, (opus_int16 const *)sample.data(), sample.size(), (unsigned char *)(encoded.data()), (int)encoded.size()) < 0)
        throw OpusException("failed to encode");
    return encoded;
}