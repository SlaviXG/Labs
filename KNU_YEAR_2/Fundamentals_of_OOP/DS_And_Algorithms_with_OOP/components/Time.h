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

    bool isDateValid(Time);
    Time inputTime();
    void printDate(Time);
    void normalizeTime(Time&);
    short getWeekDay(short day, short month, long long year); //Normal
    const char* nameWeekDay(short weekDayIDx);
    short getWeekNumInYear(short day, short month, long long year); //Decreased
    int getDayNumInYear(short day, short month, long long year); //Normal
    bool isYearLeap(long long year); //Normal
    short getDayAmountInMonth(short monthNum, long long year); //Normal

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

    std::ostream& operator << (std::ostream &cout, Time time);

    //Seasonal calendar
    void printSeasonalRepresentation(Time time);

    //Alternative format
    void printAlternativeFormat(Time time);

    //Statistics
    void printStatistics(Time time);
}


#endif //DS_AND_ALGORITHMS_WITH_OOP_TIME_H
