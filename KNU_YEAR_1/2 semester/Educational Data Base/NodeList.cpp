#include <iostream>
#include <fstream>
#include "NodeList.h"

namespace database
{
    NodeList::Node::Node(Message* message)
    {
        this->message = message;
    }

    void writeStringToBinaryFile(std::string& input_string, std::ofstream& of)
    {
        size_t len = input_string.size() + 1;
        of.write((char*)& len, sizeof(size_t));
        of.write(input_string.data(), len);
    }

    void readStringFromBinaryFile(std::string& output_string, std::fstream& in)
    {
        size_t len;
        in.read((char*)& len, sizeof(size_t));
        char* buffer = new char[len];
        in.read(buffer, len);
        output_string = std::string(buffer);
        delete [] buffer;
    }

    void NodeList::appendMessage(Message* message)
    {
        Node* node = new Node(message);

        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {

            node->prev = tail;
            tail->next = node;
            tail = node;
        }

    }

    void NodeList::printList()
    {
        unsigned int cnt = 0;
        Node* p = head;

        std::cout << "Messages : " << std::endl;

        while(p != nullptr)
        {
            Message* mes = p->message;
            mes->printMessage();

            cnt++;
            p = p->next;
        }

        printf("In in the amount of %u", cnt);
        std::cout << std::endl;
    }

    void NodeList::emptyList()
    {
        Node* p = head;
        Node* t;

        while(p!= nullptr)
        {
            t = p;
            p = p->next;
            delete t->message->GetTimePtr();
            delete t->message;
            delete t;
        }

        head = nullptr;
        tail = nullptr;

        Message::cnt = 0;
    }

    Message* NodeList::findMessageByID(unsigned int ID)
    {
        Node* t = head;

        while(t != nullptr)
        {
            if(t->message->GetID() == ID) return t->message;
            t=t->next;
        }

        return nullptr;
    }

    void NodeList::printMessagesInTimeInterval(Time minTime, Time maxTime)
    {
        Node* t = head;

        unsigned int cnt = 0;

        while(t != nullptr)
        {
            Time time = t->message->GetTime();

            if(bool(time >= minTime) and bool(maxTime >= time))
            {
                t->message->printMessage();
                cnt++;
            }

            t=t->next;
        }

        if(!cnt) std::cout << "Not found." << std::endl;
    }

    void NodeList::printMessWithTypeNotBiggerSetCapacity(unsigned short type, double capacity)
    {
        Node* t = head;

        unsigned int cnt = 0;

        while(t != nullptr)
        {
            if(t->message->GetType() == type and t->message->GetCapacity() <= capacity)
            {
                t->message->printMessage();
                cnt++;
            }

            t=t->next;
        }

        if(!cnt) std::cout << "Not found." << std::endl;
    }

    void NodeList::printMessThatStartWithText(const std::string& text)
    {
        Node* t = head;

        unsigned int cnt = 0;

        while(t != nullptr)
        {
            std::string message_text = t->message->GetText();
            int len = text.length();
            int real_len = std::min(text.length(), message_text.length());

            for(int i = 0; i < real_len; i++)
            {
                if(text[i]!=message_text[i]) break;
                if(i == len - 1)
                {
                    t->message->printMessage();
                    cnt++;
                    break;
                }
            }

            t=t->next;
        }

        if(!cnt) std::cout << "Not found." << std::endl;
    }

    void NodeList::saveListToText(bool logging)
    {
        std::ofstream fout;
        fout.open(path.text);

        if(!fout.is_open())
        {
            std::cout << "Error. File can't be opened." << std::endl;
        }
        else
        {
            Node* p = head;

            Time* time_p;

            while(p != nullptr)
            {
                Message* mes = p->message;
                fout << "---------------------------------------------------------------\n";
                fout << "ID : "<< mes->GetID() << '\n';
                fout << "Text : \n" << mes->GetText() << '\n';
                fout << "Type : " << mes->GetType() << '\n';
                fout << "Priority : " << mes->GetPriority() << '\n';
                fout << "System capacity : " << mes->GetCapacity() << '\n';
                time_p = mes->GetTimePtr();
                fout << time_p->day << '.' << time_p->month << '.' << time_p->year << "  ";
                fout << time_p->hour << ':' << time_p->minute << ':' << time_p->second << '\n';
                fout << "---------------------------------------------------------------\n";
                p = p->next;
            }

            if(logging) std::cout << "Successfully saved to the text file." << std::endl;
        }

        fout.close();
    }

    void NodeList::saveListToBin(bool logging)
    {
        std::ofstream ftypeout;
        std::ofstream ftextout;
        std::ofstream fpriorityout;
        std::ofstream fcapacityout;
        std::ofstream ftimeout;

        ftypeout.open(path.bin.type);
        ftextout.open(path.bin.text);
        fpriorityout.open(path.bin.priority);
        fcapacityout.open(path.bin.capacity);
        ftimeout.open(path.bin.time);

        if(!ftypeout.is_open() or !ftextout.is_open() or !fpriorityout.is_open() or !fcapacityout.is_open() or !ftimeout.is_open())
        {
            std::cout << "Error. File can't be opened." << std::endl;
        }
        else
        {
            Node* t = head;

            while(t != nullptr)
            {
                Message* msg = t->message;

                unsigned short type = msg->GetType();
                std::string text = msg->GetText();
                unsigned short priority = msg->GetPriority();
                double capacity = msg->GetCapacity();
                Time time = msg->GetTime();

                writeStringToBinaryFile(text, ftextout);
                ftypeout.write((char*)&type, sizeof(unsigned short));
                fpriorityout.write((char*)&priority, sizeof(unsigned short));
                fcapacityout.write((char*)&capacity, sizeof(double));
                ftimeout.write((char*)&time, sizeof(Time));

                t=t->next;
            }

            if(logging) std::cout << "Successfully saved to binary representation." << std::endl;
        }

        ftypeout.close();
        ftextout.close();
        fpriorityout.close();
        fcapacityout.close();
        ftimeout.close();
    }

    void NodeList::readListFromBin(bool logging)
    {
        std::fstream ftypein;
        std::fstream ftextin;
        std::fstream fpriorityin;
        std::fstream fcapacityin;
        std::fstream ftimein;

        ftypein.open(path.bin.type);
        ftextin.open(path.bin.text);
        fpriorityin.open(path.bin.priority);
        fcapacityin.open(path.bin.capacity);
        ftimein.open(path.bin.time);

        if(!ftypein.is_open() or !ftextin.is_open() or !fpriorityin.is_open() or !fcapacityin.is_open() or !ftimein.is_open())
        {
            std::cout << "Error. File can't be opened." << std::endl;
        }
        else
        {
            emptyList();

            std::string text;
            unsigned short priority;
            unsigned short type;
            double capacity;

            while(ftypein.read((char*)&type, sizeof(unsigned short)))
            {
                Time* time = new Time;

                readStringFromBinaryFile(text, ftextin);
                if(!fpriorityin.read((char*)&priority, sizeof(unsigned short))) break;
                if(!fcapacityin.read((char*)&capacity, sizeof(double))) break;
                if(!ftimein.read((char*)&(*time), sizeof(Time))) break;

                Message* msg_p = new Message (text, time, type, priority, capacity);
                appendMessage(msg_p);
            }

            if(logging) std::cout << "Successfully read." << std::endl;
        }

        ftypein.close();
        ftextin.close();
        fpriorityin.close();
        fcapacityin.close();
        ftimein.close();
    }

    NodeList::Path NodeList::getFilePath() {
        return NodeList::path;
    }

    void NodeList::mono_field_sort()
    {
        short cr = choice("Choose", 6,
                       "sort by ID",
                       "sort in alphabetical order",
                       "sort by type",
                       "sort by time",
                       "sort by priority",
                       "sort by capacity");

        if(cr < 1 or cr > 6)
        {
            std::cout << "Incorrect input." << std::endl;
            return;
        }

        SortingField* fields = new SortingField[1];

        if(cr == 3)
        {
            fields[0] = type;
            this->countingSort();
        }
        else if (cr == 5)
        {
            fields[0] = priority;
            this->radixSort();
        }
        else
        {
            if(cr == 1) fields[0] = ID;
            else if(cr == 2) fields[0] = text;
            else if(cr == 4) fields[0] = time;
            else if(cr == 6) fields[0] = capacity;

            this->quickSort(nullptr, nullptr, fields, 1);
        }

        std::cout << "Sorted." << std::endl;
    }

    void NodeList::multiple_field_sort()
    {
        std::cout << "Enter the fields in the priority order, for example \"1->2->3\"\n"
                     "1 - ID, 2 - Text, 3 - Time, 4 - Capacity :\n" << std::endl;

        std::string inp, b="";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, inp);

        bool sel [5] = {false, false, false, false, false};

        int i_size = inp.size();
        for(int i = 0; i < i_size; i++)
        {
            char ch = inp[i];
            if(ch > '0' and ch < '5')
            {
                if(!sel[ch-'0'])
                {
                    b+=ch;
                    sel[ch-'0'] = true;
                }
            }
        }

        SortingField* fields = new SortingField[b.size()];

        for(int i = 0; i < b.size(); i++)
        {
            if(b[i]-'0' == 1)
            {
                fields[i] = ID;
                continue;
            }
            if(b[i]-'0' == 2)
            {
                fields[i] = text;
                continue;
            }
            if(b[i]-'0' == 3)
            {
                fields[i] = time;
                continue;
            }
            if(b[i]-'0' == 4)
            {
                fields[i] = capacity;
                continue;
            }
        }

        this->quickSort(nullptr, nullptr, fields, b.size());

        std::cout << "Sorted." << std::endl;
    }

    NodeList::Node *NodeList::findMaxType()
    {
        Node* iter = head;
        Node* maxType = head;
        while (iter) {
            if (iter->message->GetType() > maxType->message->GetType())
                maxType = iter;
            iter = iter->next;
        }
        return maxType;
    }

    NodeList::Node *NodeList::findMaxPriority()
    {
        Node* iter = head;
        Node* maxId = head;
        while (iter) {
            if (iter->message->GetID() > maxId->message->GetID())
                maxId = iter;
            iter = iter->next;
        }
        return maxId;
    }

    size_t NodeList::numDigits(int n)
    {
        if (n < 10)
            return 1;

        size_t i = 1;
        while (n > pow(10, i)) i++;
        return i;
    }

    bool NodeList::compare(Message* mes1, Message* mes2, SortingField* fields, int max_field_num, int current)
    {
        if (current == max_field_num) return false;

        // enum SortingField {ID, text, type, time, priority, capacity};

        switch (*(fields + current)) {
            case ID:
                if (mes1->GetID() > mes2->GetID())
                    return true;
                else if (mes1->GetID() == mes2->GetID())
                    return compare(mes1, mes2, fields, max_field_num, current + 1);
                else
                    return false;
                break;

            case text:
                if (mes1->GetText() > mes2->GetText())
                    return true;
                else if (mes1->GetText() == mes2->GetText())
                    return compare(mes1, mes2, fields, max_field_num, current + 1);
                else
                    return false;
                break;

            case type:
                if (mes1->GetType() > mes2->GetType())
                    return true;
                else if (mes1->GetType() == mes2->GetType())
                    return compare(mes1, mes2, fields, max_field_num, current + 1);
                else
                    return false;
                break;

            case time:
                if (mes1->GetTime() > mes2->GetTime())
                    return true;
                else if (mes1->GetType() == mes2->GetType())
                    return compare(mes1, mes2, fields, max_field_num, current + 1);
                else
                    return false;
                break;

            case priority:
                if (mes1->GetPriority() > mes2->GetPriority())
                    return true;
                else if (mes1->GetPriority() == mes2->GetPriority())
                    return compare(mes1, mes2, fields, max_field_num, current + 1);
                else
                    return false;
                break;

            case capacity:
                if (mes1->GetCapacity() > mes2->GetCapacity())
                    return true;
                else if (mes1->GetCapacity() == mes2->GetCapacity())
                    return compare(mes1, mes2, fields, max_field_num, current + 1);
                else
                    return false;
                break;

            default:
                return false;
                break;
        }
    }

    NodeList::Node* NodeList::partition(NodeList::Node *start,
                             NodeList::Node *end,
                             SortingField *sortingFields,
                             int max_field_num,
                             int current)
    {
        Node* pivot = start;
        Node* front = start;
        while (front and front != end)
        {
            if (compare(end->message, front->message, sortingFields, max_field_num, current))
            {
                pivot = start;
                std::swap(start->message, front->message);
                start = start->next;
            }
            front = front->next;
        }
        //Change last node value to current node
        std::swap(start->message, end->message);
        return pivot;
    }

    //Sorting functions
    void NodeList::quickSort(NodeList::Node *start, NodeList::Node *end, SortingField *sortingFields, int max_field_num, int current)
    {
        if (start == nullptr or end == nullptr)
        {
            start = head;
            end = tail;
        }
        if (start == end) return;

        Node* pivot = partition(start, end, sortingFields, max_field_num, current);

        if (pivot and pivot->next)
            quickSort(pivot->next, end, sortingFields, max_field_num, current);
        if (pivot and start != pivot)
            quickSort(start, pivot, sortingFields, max_field_num, current);
    }

    void NodeList::countingSort()
    {
        size_t maxType = findMaxType()->message->GetType();
        NodeList* counts = new NodeList[maxType + 1];

        Node* iter = head;
        while (iter)
        {
            counts[iter->message->GetType()].appendMessage(iter->message);
            iter = iter->next;
        }

        //Cleaning the list :
        {
            Node* p = head;
            Node* t;

            while(p!= nullptr)
            {
                t = p;
                p = p->next;
                delete t;
            }

            head = nullptr;
            tail = nullptr;

            Message::cnt = 0;
        }
        //

        for (size_t i = 0; i < maxType + 1; i++)
        {
            iter = counts[i].head;
            while (iter) {
                this->appendMessage(iter->message);
                iter = iter->next;
            }
        }
        delete[] counts;
    }

    void NodeList::radixSort()
    {
        int maxPr = this->findMaxPriority()->message->GetPriority();
        size_t maxDigits = numDigits(maxPr);

        NodeList* bins = new NodeList[10];

        for (size_t i = 0; i < maxDigits; i++)
        {
            Node* iter = head;
            while (iter)
            {
                bins[(iter->message->GetPriority() / (int)pow(10, i)) % 10].appendMessage(iter->message);
                iter = iter->next;
            }
        }

        //Cleaning the list :
        {
            Node* p = head;
            Node* t;

            while(p!= nullptr)
            {
                t = p;
                p = p->next;
                delete t;
            }

            head = nullptr;
            tail = nullptr;

            Message::cnt = 0;
        }
        //

        for (size_t i = 0; i < 10; i++)
        {
            Node* iter = bins[i].head;
            while (iter)
            {
                this->appendMessage(iter->message);
                iter = iter->next;
            }
        }
        delete [] bins;
    }

    //Choice-function
    short choice(const char* criteria, short choice_amount, const char* variant, ...)
    {
        const char** ptr = &variant;
        // Printing variants :
        std::cout << criteria << " : \n";
        for (short i = 1; i<=choice_amount; i++)
        {
            std::cout << i << " - " << *(ptr++) << '\n';
        }
        std::cout << "or type anything else to exit." << std::endl;
        // Entering choice :
        short chs = 0;
        std::cin>>chs;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Processing input :
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            chs = 0;
        }
        std::cout << std::endl;
        // Returning result :
        return chs;
    }

};

