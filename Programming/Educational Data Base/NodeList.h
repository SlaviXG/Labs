#ifndef EDUCATIONAL_DATA_BASE_NODELIST_H
#define EDUCATIONAL_DATA_BASE_NODELIST_H

#include <cmath>
#include "Message.h"
#include "Timer.h"

namespace database
{

    enum SortingField {ID, text, type, time, priority, capacity};

    class NodeList
    {
    private:
        struct Node
        {
            Message* message;
            Node* next = nullptr;
            Node* prev = nullptr;

            // constructor
            Node(Message* message);

        };

        Node* head = nullptr;
        Node* tail = nullptr;

        struct Path
        {
            std::string text = "data.txt";
            std::string benchmark = "benchmark.txt";
            struct Bin
            {
                std::string type = "bindata/type.bin";
                std::string text = "bindata/text.bin";
                std::string priority = "bindata/priority.bin";
                std::string capacity = "bindata/capacity.bin";
                std::string time = "bindata/time.bin";
            } bin;
        } path;


    private:
        Node* findMaxType();
        Node* findMaxPriority();
        static size_t numDigits(int n);
        bool compare(Message* mes1, Message* mes2, SortingField* fields, int max_field_num, int current = 0);
        Node* partition(Node* start, Node* end, SortingField* sortingFields, int max_field_num, int current = 0);

    public:
        //List interactions
        void appendMessage (Message* message);
        void printList();
        void emptyList();
        Message* findMessageByID(unsigned int);
        void printMessagesInTimeInterval(Time, Time);
        void printMessWithTypeNotBiggerSetCapacity(unsigned short, double);
        void printMessThatStartWithText(const std::string&);

        //File interactions
        void saveListToText (bool logging = true);
        void saveListToBin (bool logging = true);
        void readListFromBin(bool logging = true);
        Path getFilePath();

        //Sorting functions
        void quickSort(Node* start, Node* end, SortingField* sortingFieds, int max_field_num, int current = 0);
        void countingSort(); // by type
        void radixSort(); // by priority

        //wrapper functions for sorting
        void mono_field_sort();
        void multiple_field_sort();
    };

    short choice(const char* criteria, short choice_amount, const char* variant, ...);
}

#endif //EDUCATIONAL_DATA_BASE_NODELIST_H
