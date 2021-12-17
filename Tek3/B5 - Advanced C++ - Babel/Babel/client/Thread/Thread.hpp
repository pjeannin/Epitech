/*
** EPITECH PROJECT, 2021
** B4 - Concurrent Programming
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <iostream>
#include <chrono>
#include <thread>
#include "client/Audio/PortAudio.hpp"
#include "client/Audio/Opus.hpp"
#include "client/Network/LoopUdp.hpp"
#include "shared_include/include.hpp"
#include "client/Exception.hpp"

namespace Babel::Client {
    class Thread {
        public:
            enum Status {
                NOT_STARTED,
                RUNNING,
                ENDED
            };
            Thread();
            ~Thread() = default;
            void start(void *(*startRoutine)(void *), void *arg);
            void join();
            void exit(void *status);
            Status getStatus() const;

            static void *routineRead(void *args);
            static void *routineWrite(void *args);
        protected:
        private:
            std::thread *_myThread;
            Status _status;
    };
}

#endif /* !THREAD_HPP_ */