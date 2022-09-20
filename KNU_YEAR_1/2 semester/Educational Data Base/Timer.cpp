#include "Timer.h"

void Timer::reset()
{
    beg = clock_t::now();
}

double Timer::elapsed() const
{
    return std::chrono::duration_cast<second_t>(clock_t::now() - beg).count();
}