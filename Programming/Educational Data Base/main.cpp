#include <iostream>
#include <fstream>
#include <ctime>
#include "Time.h"
#include "NodeList.h"

using namespace database;

void print_operation_menu();

int main()
{
    NodeList nodeList;

    int mode = 0;

    std::cout << "Type : \n"
                 "1 to choose an interactive mode \n"
                 "2 to choose a demo mode \n"
                 "3 to choose a benchmark mode" << std::endl;

    std::cout << "Choose the mode of operation for the program : " << std::endl;

    do
    {
        std::cin >> mode;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while(mode < 1 or mode > 3);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (mode)
    {
        case 1 :
        {
            int op = 0;

            do
            {
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                print_operation_menu();

                std::cin >> op;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                switch (op)
                {
                    case 1 : // adding
                    {
                        std::string message_text;
                        unsigned short message_type; // 0 - debug, 1 - info, 2 - warning, 3 - error, 4 - fatal
                        unsigned short message_priority; // 0 - 100
                        double message_capacity;

                        std::cout << "Enter message text :" << std::endl;
                        //std::cin >> message_text;
                        std::getline(std::cin, message_text, '\n');

                        std::cout << "Enter message type (0 - debug, 1 - info, 2 - warning, 3 - error, 4 - fatal)\n"
                                     "or type anything else to exit to menu." << std::endl;
                        std::cin >> message_type;

                        if (std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }

                        if(message_type < 0 or message_type > 4) break;

                        std::cout << "Enter message priority (0 - 100)\n"
                                     "or type anything else to exit to menu." << std::endl;
                        std::cin >> message_priority;

                        if (std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }

                        if(message_priority < 0 or message_priority > 100) break;

                        std::cout << "Enter a capacity of the system (0.0 - 1.0)\n"
                                     "or type anything else to exit to menu." << std::endl;
                        std::cin >> message_capacity;

                        if (std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }

                        if(message_capacity < 0.0 or message_capacity > 1.0) break;

                        Message* message= new Message(message_text, SetTime(), message_type, message_priority, message_capacity);

                        nodeList.appendMessage(message);

                        break;
                    }
                    case 2 : // reading
                    {
                        nodeList.readListFromBin();
                        std::cout << std::endl;
                        break;
                    }
                    case 3 : // saving
                    {
                        nodeList.saveListToBin();
                        nodeList.saveListToText();
                        std::cout << std::endl;
                        break;
                    }
                    case 4 : // modifying
                    {

                        std::cout << "Type ID of the message that has to be modified :" << std::endl;

                        unsigned int id;

                        std::cin >> id;

                        if (std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Incorrect input. Exiting." << std::endl;
                            break;
                        }

                        Message* mes_p = nodeList.findMessageByID(id);

                        if(mes_p!= nullptr)
                        {
                            short ch = 0;

                            do
                            {
                                std::cout << "Select the field that you want to modify :\n"
                                             "1 - Text\n"
                                             "2 - Type\n"
                                             "3 - Priority\n"
                                             "4 - Capacity of the system\n"
                                             "5 - Date/Time\n"
                                             "or type anything else to exit to menu." << std::endl;

                                std::cin >> ch;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                if (std::cin.fail())
                                {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    break;
                                }

                                switch (ch)
                                {
                                    case 1 : // Text
                                    {
                                        std::string new_txt;
                                        std::cout << "Enter new text :" << std::endl;
                                        std::getline(std::cin, new_txt, '\n');
                                        mes_p->SetText(new_txt);
                                        std::cout << "Edited." << std::endl;
                                        break;
                                    }
                                    case 2 : // Type
                                    {
                                        unsigned short new_type = 0;
                                        std::cout << "Type a new type (0 - 4) :" << std::endl;
                                        std::cin >> new_type;
                                        if(new_type < 0 or new_type > 4) break;
                                        if (std::cin.fail())
                                        {
                                            std::cin.clear();
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                            break;
                                        }

                                        mes_p->SetType(new_type);
                                        std::cout << "Edited." << std::endl;
                                        break;
                                    }
                                    case 3 : // Priority
                                    {
                                        unsigned short new_priority = 0;
                                        std::cout << "Enter a new priority (0 - 100) :" << std::endl;
                                        std::cin >> new_priority;
                                        if (std::cin.fail())
                                        {
                                            std::cin.clear();
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                            break;
                                        }
                                        if(new_priority < 0 or new_priority > 100) break;
                                        mes_p->SetPriority(new_priority);
                                        std::cout << "Edited." << std::endl;
                                        break;
                                    }
                                    case 4 : // Capacity
                                    {
                                        double new_capacity = 0;
                                        std::cout << "Enter a new capacity (0.0 - 1.0) :" << std::endl;
                                        std::cin >> new_capacity;
                                        if (std::cin.fail())
                                        {
                                            std::cin.clear();
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                            break;
                                        }
                                        if(new_capacity < 0.0 or new_capacity > 1.0) break;
                                        mes_p->SetCapacity(new_capacity);
                                        std::cout << "Edited." << std::endl;
                                        break;
                                    }
                                    case 5 : // Date
                                    {
                                        std::cout << "Enter a Date/time :" << std::endl;
                                        mes_p->SetTime(SetTime());
                                        std::cout << "Edited." << std::endl;
                                        break;
                                    }
                                }

                            }
                            while(ch > 0 and ch < 6);

                        }
                        else
                        {
                            std::cout << "Message with such ID was not found." << std::endl;
                        }

                        std::cout << std::endl;
                        break;
                    }
                    case 5 : // printing
                    {
                        nodeList.printList();
                        std::cout << std::endl;
                        break;
                    }
                    case 6 : // searching
                    {
                        short search_mode = 0;

                        do
                        {
                            std::cout << "Select searching mode : \n"
                                         "1 - Messages in the time interval\n"
                                         "2 - Messages with specified type with the capacity level not bigger than given one\n"
                                         "3 - Messages that start with the specified text\n"
                                         "or type anything else to exit to menu." << std::endl;

                            std::cin >> search_mode;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                break;
                            }

                            switch (search_mode)
                            {
                                case 1 :
                                {
                                    std::cout << "Specify the interval (Date/Time) - (Date/Time)" << std::endl;
                                    Time* A = SetTime();
                                    Time* B = SetTime();
                                    nodeList.printMessagesInTimeInterval(*A, *B);
                                    delete A, B;
                                    std::cout << std::endl;
                                    break;
                                }
                                case 2 :
                                {

                                    unsigned short type;
                                    double capacity;

                                    std::cout << "Specify the type (0 - debug, 1 - info, 2 - warning, 3 - error, 4 - fatal)\n"
                                                 "or type anything else to escape." << std::endl;

                                    std::cin >> type;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                    if (std::cin.fail())
                                    {
                                        std::cin.clear();
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        break;
                                    }

                                    if(type < 0 or type > 4) break;

                                    std::cout << "Insert capacity level (0.0 - 1.0)\n"
                                                 "or type anything else to escape." << std::endl;

                                    std::cin >> capacity;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                    if (std::cin.fail())
                                    {
                                        std::cin.clear();
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        break;
                                    }

                                    if(capacity < 0.0 or capacity > 1.0) break;

                                    nodeList.printMessWithTypeNotBiggerSetCapacity(type, capacity);

                                    std::cout << std::endl;
                                    break;
                                }
                                case 3 :
                                {
                                    std::string text;
                                    std::cout << "Input text : " << std:: endl;
                                    std::getline(std::cin, text, '\n');

                                    nodeList.printMessThatStartWithText(text);

                                    std::cout << std::endl;
                                    break;
                                }

                            }
                        }
                        while(search_mode > 0 and search_mode < 4);

                        std::cout << std::endl;
                        break;
                    }
                    case 7: //sorting
                    {
                        std::cout << std::endl;
                        std::cout << "How do you want to sort the messages?\n" << std::endl;

                        std::cout << "1 - mono-field sorting\n";
                        std::cout << "2 - multiple-field sorting\n" << std::endl;

                        int sort_mode = 0;

                        std::cin >> sort_mode;

                        if (std::cin.fail())
                        {
                            std::cout << "Incorrect input." << std::endl;
                            std::cout << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        else if (sort_mode < 1 or sort_mode > 2)
                        {
                            std::cout << "Incorrect input." << std::endl;
                            std::cout << std::endl;
                            break;
                        }

                        if(sort_mode==1)
                            nodeList.mono_field_sort();
                        else
                            nodeList.multiple_field_sort();

                        std::cout << std::endl;

                        break;
                    }
                    default :
                    {
                        exit(0);
                    }
                }

            }
            while (op);

            break;
        }
        case 2 :
        {
            std::cerr << "Starting Demonstration...\n"
                         "every time press enter to continue." << std::endl;
            getchar();
            print_operation_menu();
            getchar();
            std::cout << "5" << std::endl;
            getchar();
            nodeList.printList();
            getchar();
            print_operation_menu();
            getchar();
            std::cout << "2" << std::endl;
            getchar();
            nodeList.readListFromBin();
            getchar();
            print_operation_menu();
            std::cout << "5" << std::endl;
            nodeList.printList();
            getchar();
            print_operation_menu();
            getchar();
            std::cout << "1" << std::endl;
            getchar();
            std::cout << "Enter message text :" << std::endl;
            getchar();
            std::cout << "abacaba" << std::endl;
            getchar();
            std::cout << "Enter message type (0 - debug, 1 - info, 2 - warning, 3 - error, 4 - fatal)\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "0" << std::endl;
            getchar();
            std::cout << "Enter message priority (0 - 100)\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "25" << std::endl;
            getchar();
            std::cout << "Enter a capacity of the system (0.0 - 1.0)\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "0.3" << std::endl;
            getchar();
            std::cout << "Enter a date (dd.mm.yyyy) : " << std::endl;
            getchar();
            std::cout << "24.08.2006" << std::endl;
            getchar();
            std::cout << "Time (hh:mm:ss) : " << std::endl;
            getchar();
            std::cout << "3:26:47" << std::endl;
            Time* time = new Time;
            time->day = 24; time->month = 8; time->year = 2006;
            time->hour = 3; time->minute = 26; time->second = 47;
            Message* mes = new Message("abacaba", time, 0, 25, 0.3);
            nodeList.appendMessage(mes);
            getchar();
            print_operation_menu();
            getchar();
            std::cout << "5" << std::endl;
            nodeList.printList();
            getchar();
            print_operation_menu();
            getchar();
            std::cout << "4" << std::endl;
            getchar();
            std::cout << "Type ID of the message that has to be modified :" << std::endl;
            std::cout << Message::cnt << std::endl;
            Message* mes_p = nodeList.findMessageByID(Message::cnt);
            getchar();
            std::cout << "Select the field that you want to modify :\n"
                         "1 - Text\n"
                         "2 - Type\n"
                         "3 - Priority\n"
                         "4 - Capacity of the system\n"
                         "5 - Date/Time\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "1" << std::endl;
            getchar();
            std::cout << "Enter new text :" << std::endl;
            getchar();
            std::cout << "ahahahahah" << std::endl;
            getchar();
            mes_p->SetText("ahahahahah");
            std::cout << "Edited." << std::endl << std::endl;
            std::cout << "Select the field that you want to modify :\n"
                         "1 - Text\n"
                         "2 - Type\n"
                         "3 - Priority\n"
                         "4 - Capacity of the system\n"
                         "5 - Date/Time\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "oaoaoo" << std::endl;
            getchar();
            print_operation_menu();
            getchar();
            std::cout << "5" << std::endl;
            nodeList.printList();
            getchar();
            std::cout << "3" << std::endl;
            nodeList.saveListToText();
            nodeList.saveListToBin();
            print_operation_menu();
            getchar();
            std::cout << "6" << std::endl;
            getchar();
            std::cout << "Select searching mode : \n"
                         "1 - Messages in the time interval\n"
                         "2 - Messages with specified type with the capacity level not bigger than given one\n"
                         "3 - Messages that start with the specified text\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "3" << std::endl;
            getchar();
            std::cout << "Input text : " << std:: endl;
            getchar();
            std::cout << "ahah" << std:: endl;
            getchar();
            nodeList.printMessThatStartWithText("ahah");
            std::cout << "Select searching mode : \n"
                         "1 - Messages in the time interval\n"
                         "2 - Messages with specified type with the capacity level not bigger than given one\n"
                         "3 - Messages that start with the specified text\n"
                         "or type anything else to exit to menu." << std::endl;
            getchar();
            std::cout << "something" << std:: endl;
            getchar();
            print_operation_menu();
            getchar();
            std::cerr << "Demonstration mode ended." << std:: endl;
            break;
        }
        case 3 :
        {
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Timer timer;
            unsigned int N;
            std::cout << "Enter N :" << std::endl;
            std::cin>>N;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Processing input :
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Incorrect input." << std::endl;
                break;
            }

            Message test_message_set[N];
            NodeList test_3 [4];
            long double result[4]; //counting, radix, quick - 1 field, quick - 2 - fields

            for(int i = 0; i < N; i++)
            {
                test_message_set[i].generateRandomContent();
            }

            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    Message* msg = new Message;
                    *msg = test_message_set[j];
                    test_3[i].appendMessage(msg);
                }
            }

            timer.reset();
            test_3[0].countingSort();
            result[0] = timer.elapsed();

            timer.reset();
            test_3[1].radixSort();
            result[1] = timer.elapsed();

            SortingField* fields = new SortingField[1];
            fields[0] = capacity;
            timer.reset();
            test_3[2].quickSort(nullptr, nullptr, fields, 1);
            result[2] = timer.elapsed();
            delete [] fields;

            fields = new SortingField[2];
            fields[0] = capacity;
            fields[1] = text;
            timer.reset();
            test_3[3].quickSort(nullptr, nullptr, fields, 2);
            result[3] = timer.elapsed();
            delete [] fields;

            std::ofstream fout;
            fout.open("benchmark.txt");

            if(fout.is_open())
            {
                fout << "N = " << N << "\n\n";

                fout << "Counting sort : \n"
                        "--------------------------------------------------------------------------\n";
                fout << result[0] << " ms\n";
                fout << "--------------------------------------------------------------------------\n";
                fout << "Radix sort : \n"
                        "--------------------------------------------------------------------------\n";
                fout << result[1] << " ms\n";
                fout << "--------------------------------------------------------------------------\n";
                fout << "Quick sort mono-field : \n"
                        "--------------------------------------------------------------------------\n";
                fout << result[2] << " ms\n";
                fout << "--------------------------------------------------------------------------\n";
                fout << "Quick sort multi-field : \n"
                        "--------------------------------------------------------------------------\n";
                fout << result[3] << " ms\n";
                fout << "--------------------------------------------------------------------------\n";
            }
            else
            {
                std::cout << "Benchmark file can't be opened." << std::endl;
            }
            fout.close();
            std::cout << "OK." << std::endl;

            std::cerr << "End ot the test." << std::endl;

            break;
        }
        default :
        {
            std::cout << "Mode was not found" << std::endl;
        }
    }
    return 0;
}

void print_operation_menu()
{
    std::cout << "Choose : \n"
                 "1 to add a new message\n"
                 "2 to read the database\n"
                 "3 to save the database\n"
                 "4 to modify an element\n"
                 "5 to print the data\n"
                 "6 to search messages\n"
                 "7 to sort messages\n"
                 "Or type anything else to exit." << std::endl;
}