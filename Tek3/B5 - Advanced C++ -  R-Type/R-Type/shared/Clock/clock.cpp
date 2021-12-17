#include "shared/Clock/clock.hpp"

Clock::Clock(int nb) noexcept {
    for (int i = 0; i < nb; ++i)
        _prevMoment.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

void Clock::setNextMoment(std::vector<int> nextMomentIn) noexcept { //
    _nextMomentIn = nextMomentIn;
}

int Clock::numberOfRep(int object) noexcept {
    std::clock_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    int i = 0;

    if (object >= (int)(_prevMoment.size()))
        return -1;
    for (i = 0; _prevMoment[object] + _nextMomentIn[object] < (long)now; ++i)
        _prevMoment[object] += _nextMomentIn[object];
    return i;
}

void Clock::addElem(int nb) noexcept {
    _prevMoment.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    _nextMomentIn.push_back(nb);
}

void Clock::deleteElem(int nb) noexcept {
    _prevMoment.erase(_prevMoment.begin() + nb);
    _nextMomentIn.erase(_nextMomentIn.begin() + nb);
}