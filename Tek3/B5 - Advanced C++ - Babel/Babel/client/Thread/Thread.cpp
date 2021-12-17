/*
** EPITECH PROJECT, 2021
** B4 - Concurrent Programming
** File description:
** Thread
*/

#include "Thread.hpp"

Babel::Client::Thread::Thread() : _status(NOT_STARTED)
{
}

void Babel::Client::Thread::start(void *(*startRoutine)(void *), void *arg)
{
    if (_status == NOT_STARTED) {
        _myThread = new std::thread(startRoutine, arg);
        if (!_myThread)
            throw Exception("[PThread] Fail to run 'pthread_create'.");
        _status = RUNNING;
        return;
    }
    throw Exception("[Thread] Try to run a running or dead Thread.");
}

void Babel::Client::Thread::join()
{
    if (_status != RUNNING)
        throw Exception("[Thread] Try to join with a non running thread.");
    _myThread->join();
    _status = ENDED;
}

void Babel::Client::Thread::exit(void *status)
{
    if (_status != RUNNING)
        throw Exception("[Thread] Try to exit a non running thread.");
    delete _myThread;
    _status = ENDED;
}

Babel::Client::Thread::Status Babel::Client::Thread::getStatus() const { return _status; }

void *Babel::Client::Thread::routineRead(void *args) {
    auto *portAudio = (Babel::Client::Audio::PortAudio *)((*(std::vector<void *> *)args)[0]);
    auto *opus = (Babel::Client::Audio::Opus *)((*(std::vector<void *> *)args)[1]);
    bool *isRunning = (bool *)((*(std::vector<void *> *)args)[2]);
    Network::LoopUdp udp(*(short *)((*(std::vector<void *> *)args)[3]));

    udp.bind();
    while(*isRunning) {
        udp.readDatas();
        while ( Network::LoopUdp::Datas *datas = udp.getDatas()) {
            std::vector<uint16_t> vec = *new std::vector<uint16_t>();
            Babel::Client::Network::IUdp::Packet p{};
            memcpy(&p, datas->datas, sizeof(p));
            for (unsigned short &dat: p.datas)
                vec.push_back(dat);
            std::vector<uint16_t> tmp = opus->decode(vec);
            portAudio->playRecord(tmp);
        }
    }
    return nullptr;
}

void *Babel::Client::Thread::routineWrite(void *args) {
    auto *portAudio = (Babel::Client::Audio::PortAudio *)((*(std::vector<void *> *)args)[0]);
    auto *opus = (Babel::Client::Audio::Opus *)((*(std::vector<void *> *)args)[1]);
    bool *isRunning = (bool *)((*(std::vector<void *> *)args)[2]);
    Network::LoopUdp udp(*(short *)((*(std::vector<void *> *)args)[3]));

    try {
        portAudio->startStream();
        portAudio->startRecording();
        while (*isRunning) {
            std::vector<uint16_t> tmp = opus->encode(portAudio->getRecord());
            Babel::Client::Network::IUdp::Packet p{.magicCode = MAGIC_CODE, .timestamp = time(nullptr)};
            char bff[sizeof(Babel::Client::Network::IUdp::Packet)];
            for (int i = 0; i < tmp.size(); ++i)
                p.datas[i] = tmp[i];
            memcpy(bff, &p, sizeof(p));
            QByteArray baTemp = QByteArray::fromRawData(bff,sizeof(p));
            udp.sendDatas(baTemp, *(short *)((*(std::vector<void *> *)args)[4]), *(std::string *)((*(std::vector<void *> *)args)[5]));
            std::this_thread::sleep_for(std::chrono::milliseconds(7));
        }
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    delete portAudio;
    delete opus;
    return nullptr;
}
