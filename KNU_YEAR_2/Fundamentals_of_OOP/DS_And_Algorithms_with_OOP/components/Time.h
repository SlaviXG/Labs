#ifndef DS_AND_ALGORITHMS_WITH_OOP_TIME_H
#define DS_AND_ALGORITHMS_WITH_OOP_TIME_H

#include <iostream>
#include <string>
#include <numeric>

struct Time
{
public:
    //Constructor
    Time();

    unsigned long year = 0;
    unsigned long month = 0;
    unsigned long day = 0;
    unsigned long hour = 0;
    unsigned long minute = 0;
    unsigned long second = 0;

    bool isMoreOrEqualsTo(Time);
};

Time setTime();
void printTime(Time);
bool isTimeValid(Time);

bool operator >= (Time, Time);
bool operator > (Time, Time);
bool operator == (Time, Time);
bool operator < (Time, Time);
bool operator <= (Time, Time);
bool operator != (Time, Time);

#endif //DS_AND_ALGORITHMS_WITH_OOP_TIME_H
