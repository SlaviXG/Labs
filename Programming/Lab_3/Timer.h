#ifndef A__TIMER_H
#define A__TIMER_H

#include <chrono>

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> beg;

public:
    Timer() : beg(clock_t::now()){};
    void reset();
    double elapsed() const;
};


#endif