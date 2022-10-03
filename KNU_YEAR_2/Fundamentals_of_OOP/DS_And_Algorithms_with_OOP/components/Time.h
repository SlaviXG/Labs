#ifndef DS_AND_ALGORITHMS_WITH_OOP_TIME_H
#define DS_AND_ALGORITHMS_WITH_OOP_TIME_H

#include <iostream>
#include <string>
#include <numeric>
#include <exception>

namespace datetime
{
    struct Time
    {
    public:
        //Constructor
        Time();

        //Measurements
        long long year;
        short month;
        short day;
        short hour;
        short minute;
        short second;

        //Negative flag
        bool isNegative;
    };

    bool isTimeValid(Time);
    Time inputTime();
    void printTime(Time);
    void normalizeTime(Time&);

    bool isYearLeap(long long year);
    short getDayAmountInMonth(short monthNum, long long year);

//Comparison operators
    bool operator >= (Time, Time);
    bool operator > (Time, Time);
    bool operator == (Time, Time);
    bool operator < (Time, Time);
    bool operator <= (Time, Time);
    bool operator != (Time, Time);

//Arithmetical operators
    Time operator + (Time, Time);
    Time operator - (Time, Time);

}


#endif //DS_AND_ALGORITHMS_WITH_OOP_TIME_H
