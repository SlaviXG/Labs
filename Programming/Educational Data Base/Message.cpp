//
// Created by SlaviX on 17.02.2022.
//
#include <random>

#include "Message.h"

namespace database
{
    int generate_random_int(int max_value, int min_value = 1)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min_value, max_value);
        return dist(gen);
    }

    unsigned int Message::cnt = 0;

    unsigned int Message::GetID()
    {
        return ID;
    }

    void Message::generateRandomContent() // auto generation
    {
        text = "";
        int mes_len = generate_random_int(50);
        for(int i = 0; i < mes_len; i++)
            text+='a'+ generate_random_int(25, 0);

        time = new Time;
        time->second = generate_random_int(59, 0);
        time->minute = generate_random_int(59, 0);
        time->hour = generate_random_int(23, 0);
        time->year = generate_random_int(2022, 1970);
        time->month = generate_random_int(12, 1);
        time->day = generate_random_int((((time->year)%4) ? 29 : 28), 1);

        type = generate_random_int(4, 0);

        priority = generate_random_int(100, 0);

        capacity = generate_random_int(10000, 1) / 10000.0;

        cnt++;
        ID = cnt;
    }

    Message::Message()
    {
        this->text = "";
        this->type = 0;
        this->priority = 0;
        this->capacity = 0;

        time = new Time;

        cnt++;
        ID = cnt;
    }

    Message::Message(std::string txt, Time* sending_time, unsigned short message_type, unsigned short pr, double cp)
    {
        this->text = txt;
        this->time = sending_time;
        this->type = message_type;
        this->priority = pr;
        this->capacity = cp;

        cnt++;
        ID = cnt;
    }

    void Message::printMessage()
    {
        std::cout << "---------------------------------------------------------------" << std::endl;
        printf("ID : %u \n", this->ID);
        std::cout << "Text : \n" << this->text << "\n";
        printf("Type : %hu, priority : %hu, system capacity : %lf,\n", this->type, this->priority, this->capacity);
        PrintTime(this->time);
        std::cout << "---------------------------------------------------------------" << std::endl;
    }

    std::string Message::GetText()
    {
        return text;
    }

    Time Message::GetTime()
    {
        return *this->time;
    }

    Time* Message::GetTimePtr()
    {
        return this->time;
    }

    unsigned short Message::GetType() {
        return type;
    }

    unsigned short Message::GetPriority() {
        return priority;
    }

    double Message::GetCapacity() {
        return capacity;
    }

    void Message::SetText(std::string new_text)
    {
        this->text = new_text;
    }

    void Message::SetTime(Time* new_time)
    {
        this->time = new_time;
    }

    void Message::SetType(unsigned short new_type)
    {
        this->type = new_type;
    }

    void Message::SetPriority(unsigned short new_priority)
    {
        this->priority = new_priority;
    }

    void Message::SetCapacity(double new_capacity)
    {
        this->capacity = new_capacity;
    }
}


