//
// Created by SlaviX on 17.02.2022.
//
#include <iostream>
#include <string>

#include "Time.h"

bool Time::IsMoreOrEqualsTo(Time B)
{
    if(year > B.year) return true;
    else if(year == B.year)
    {
        if(month > B.month) return true;
        else if(month == B.month)
        {
            if(day > B.day) return true;
            else if(day == B.day)
            {
                if(hour > B.hour) return true;
                else if(hour == B.hour)
                {
                    if(minute > B.minute) return true;
                    else if(minute == B.minute)
                    {
                        if(second >= B.second) return true;
                    }
                }
            }
        }
    }

    return false;
}

bool IsTimeValid(Time* time)
{

    //std::cout << std::endl << "Checking out!" << std::endl;
    if(time->year < 1) return false;
    if(time->month < 1 or time->month > 12) return false;
    if(time->day < 1) return false;

    // February
    if(time->month == 2)
    {
        if(!(time->year % 4))
        {
            if(time->day < 1 or time->day > 29) return false;
        }
        else
        {
            if(time->day < 1 or time->day > 28) return false;
        }
    }
    // other months
    else
    {
        if(time->month < 8) // January - July
        {
            if(time->month % 2) // 31
            {
                if(time->day > 31) return false;
            }
            else // 30
            {
                if(time->day > 30) return false;
            }
        }
        else // August - December
        {
            if(time->month % 2)
            {
                if(time->day > 30) return false;
            }
            else
            {
                if(time->day > 31) return false;
            }
        }
    }

    if(time->hour > 23) return false;
    if(time->minute > 59) return false;
    if(time->second > 59) return false;

    return true;
}

Time* SetTime()
{
    Time* time = new Time;

    std::string input;

    bool validness = true;
    do
    {
        //std::cout << validness << std::endl;
        if(!validness)
        {
            std::cerr << "Error. Incorrect input." << std::endl;
            validness = true;
        }
        try
        {

            std::cout << "Enter a date (dd.mm.yyyy) : " << std::endl;

            std::getline(std::cin, input, '.');

            time->day = std::stoul(input);

            std::getline(std::cin, input, '.');

            time->month = std::stoul(input);

            std::getline(std::cin, input,'\n');

            time->year = std::stoul(input);

            std::cout << "Time (hh:mm:ss) : " << std::endl;

            std::getline(std::cin, input, ':');

            time->hour = std::stoul(input);

            std::getline(std::cin, input, ':');

            time->minute = std::stoul(input);

            std::getline(std::cin, input,'\n');

            time->second = std::stoul(input);

        }
        catch (std::exception)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            validness = false;
        }

        if(validness) validness = IsTimeValid(time);
    }
    while(!validness);

    std::cout << std::endl;

    return time;

}

//"Date (dd.mm.yyyy) :"
//"Time (hh:mm:ss) :"
void PrintTime(Time* time)
{
    std::cout.flush();
    printf("Exact time : %i.%i.%i", time->day, time->month, time->year);
    printf(" %i:%i:%i", time->hour, time->minute, time->second);
    std::cout << std::endl;
}

bool operator >= (Time A, Time B)
{
    return A.IsMoreOrEqualsTo(B);
}

bool operator > (Time A, Time B)
{
    if(A.year > B.year) return true;
    else if (A.year == B.year)
    {
        if(A.month > B.month) return true;
        else if (A.month == B.month)
        {
            if(A.day > B.day) return true;
            else if (A.day == B.day)
            {
                if(A.hour > B.hour) return true;
                else if (A.hour == B.hour)
                {
                    if(A.minute > B.minute) return true;
                    else if (A.minute == B.minute)
                    {
                        if(A.second > B.second) return true;
                    }
                }
            }
        }
    }

    return false;
}

bool operator == (Time A, Time B)
{
    return
    (A.day == B.day and
        A.month == B.month and
        A.year == B.year and
        A.hour == B.hour and
        A.minute == B.minute and
        A.second == B.second);
}