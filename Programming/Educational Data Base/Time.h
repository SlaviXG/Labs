//
// Created by SlaviX on 17.02.2022.
//
#pragma once

#ifndef EDUCATIONAL_DATA_BASE_TIME_H
#define EDUCATIONAL_DATA_BASE_TIME_H

struct Time {
    unsigned long year = 0;
    unsigned long month = 0;
    unsigned long day = 0;
    unsigned long hour = 0;
    unsigned long minute = 0;
    unsigned long second = 0;

    bool IsMoreOrEqualsTo(Time);
};

Time* SetTime();
void PrintTime(Time*);
bool IsTimeValid(Time*);

bool operator >= (Time, Time);
bool operator > (Time, Time);
bool operator == (Time, Time);


#endif //EDUCATIONAL_DATA_BASE_TIME_H
