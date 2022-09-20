#ifndef DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_APPLICATION_H
#define DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_APPLICATION_H

#include <iostream>
#include <string>
#include <fstream>

#include "VectorDeque.h"
#include "ArrayDeque.h"
#include "NodeListDeque.h"
#include "Timer.h"

class Application
{
    public:
    static short choice(const char* criteria, short choice_amount, const char* variant, ...);
    static void DemoMode();
    static void InteractiveMode();
    static void BenchmarkMode();
};

int binpow(int, int);

#endif //DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_APPLICATION_H
