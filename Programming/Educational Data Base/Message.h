#pragma once
#ifndef EDUCATIONAL_DATA_BASE_MESSAGE_H
#define EDUCATIONAL_DATA_BASE_MESSAGE_H

#include <string>
#include <iostream>

#include "Time.h"

namespace database
{
    /**
        Message class:

        - unique ID
        - message text
        - type (0 - debug, 1 - info, 2 - warning, 3 - error, 4 -fatal)
        - priority (0 - 100)
        - capacity (0.0 - 1.0)
        - time

        ---------------------------------------------------------------
        ID : ...
        Text :
        ...
        Type : ... , priority : ... , system capacity : ... ,
        Exact time : ...
        ---------------------------------------------------------------
    */

    class Message{
    private:

        unsigned int ID; // unique

        std::string text;
        Time *time = new Time;
        unsigned short type; // 0 - debug, 1 - info, 2 - warning, 3 - error, 4 -fatal
        unsigned short priority; // 0 - 100
        double capacity;

    public:

        static unsigned int cnt;

        Message();
        Message(std::string txt, Time *sending_time, unsigned short message_type, unsigned short pr, double cp);

        void generateRandomContent();

        void printMessage();

        unsigned int GetID();
        std::string GetText();
        Time GetTime();
        Time* GetTimePtr();
        unsigned short GetType();
        unsigned short GetPriority();
        double GetCapacity();

        void SetText(std::string);
        void SetTime(Time*);
        void SetType(unsigned short);
        void SetPriority(unsigned short);
        void SetCapacity(double);
    };

}

#endif //EDUCATIONAL_DATA_BASE_MESSAGE_H
