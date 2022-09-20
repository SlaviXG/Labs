#include "Application.h"

using std::cin;
using std::cout;
using std::endl;

void Application::DemoMode()
{
    VectorDeque vectorDeque;
    ArrayDeque arrayDeque;
    NodeListDeque nodeListDeque;

    bool d_sc = true;
    while (d_sc)
    {
        switch(choice("Select the deque scenario",
                      3,
                      "Array deque", "Vector deque", "Node List deque"))
        {
            case 1 :
            {
                std::cerr << "Starting Demonstration...\n"
                             "every time press enter to continue.\n" << std::endl;
                getchar();

                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                arrayDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "1" << std::endl;
                getchar();
                std::cout << "Enter the size of deque :" << std::endl;
                getchar();
                std::cout << "3" << std::endl;
                getchar();
                arrayDeque.create_empty(3);
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                arrayDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "4" << std::endl;
                getchar();
                std::cout << "Input point : X Y Z" << std::endl;
                getchar();
                std::cout << "0.25 73 -89" << std::endl;
                arrayDeque.append(Point(0.25, 73, -89));
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                arrayDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "3" << std::endl;
                getchar();
                std::cout << "Input point : X Y Z" << std::endl;
                getchar();
                std::cout << "3 9 1.1" << std::endl;
                arrayDeque.append_left(Point(3, 9, 1.1));
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                arrayDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "11" << std::endl;
                getchar();
                std::cout << "Deque is " << (arrayDeque.is_empty() ? "empty." : "not empty.") << std::endl;
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "5" << std::endl;
                arrayDeque.pop_left();
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                arrayDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cerr << "Demonstration ended." << std:: endl;
                break;
            }
            case 2 :
            {
                std::cerr << "Starting Demonstration...\n"
                             "every time press enter to continue.\n" << std::endl;
                getchar();

                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                vectorDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "1" << std::endl;
                getchar();
                vectorDeque.create_empty();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                vectorDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "4" << std::endl;
                getchar();
                std::cout << "Input point : X Y Z" << std::endl;
                getchar();
                std::cout << "0.25 73 -89" << std::endl;
                vectorDeque.append(Point(0.25, 73, -89));
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                vectorDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "3" << std::endl;
                getchar();
                std::cout << "Input point : X Y Z" << std::endl;
                getchar();
                std::cout << "3 9 1.1" << std::endl;
                vectorDeque.append_left(Point(3, 9, 1.1));
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                vectorDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "11" << std::endl;
                getchar();
                std::cout << "Deque is " << (vectorDeque.is_empty() ? "empty." : "not empty.") << std::endl;
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "5" << std::endl;
                vectorDeque.pop_left();
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                vectorDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cerr << "Demonstration ended." << std:: endl;
                break;
            }
            case 3 :
            {
                std::cerr << "Starting Demonstration...\n"
                             "every time press enter to continue.\n" << std::endl;
                getchar();

                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                nodeListDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "1" << std::endl;
                getchar();
                nodeListDeque.create_empty();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                nodeListDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "4" << std::endl;
                getchar();
                std::cout << "Input point : X Y Z" << std::endl;
                getchar();
                std::cout << "0.25 73 -89" << std::endl;
                nodeListDeque.append(Point(0.25, 73, -89));
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                nodeListDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "3" << std::endl;
                getchar();
                std::cout << "Input point : X Y Z" << std::endl;
                getchar();
                std::cout << "3 9 1.1" << std::endl;
                nodeListDeque.append_left(Point(3, 9, 1.1));
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                nodeListDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "11" << std::endl;
                getchar();
                std::cout << "Deque is " << (nodeListDeque.is_empty() ? "empty." : "not empty.") << std::endl;
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cout << "5" << std::endl;
                nodeListDeque.pop_left();
                getchar();
                std::cout << "2" << std::endl;
                getchar();
                nodeListDeque.print();
                getchar();
                std::cout << "Action : \n"
                             "1 - Create empty\n"
                             "2 - Print\n"
                             "3 - Append left\n"
                             "4 - Append\n"
                             "5 - Pop left\n"
                             "6 - Pop\n"
                             "7 - Size\n"
                             "8 - Clear\n"
                             "9 - Front\n"
                             "10 - Back\n"
                             "11 - Is empty\n"
                             "Or type anything else to exit." << std::endl;
                getchar();
                std::cerr << "Demonstration ended." << std:: endl;
                break;
            }
            default :
            {
                d_sc = false;
                break;
            }
        }
    }
}

void Application::InteractiveMode()
{
    VectorDeque vectorDeque;
    ArrayDeque arrayDeque;
    NodeListDeque nodeListDeque;

    bool go_ahead = true;
    while (go_ahead)
    {
        switch(choice("Select the deque to interact with",
                      3,
                      "Array deque", "Vector deque", "Node List deque"))
        {
            case 1 : // Array deque
            {
                bool act_wit_cur = true;
                while(act_wit_cur)
                {
                    switch (choice("Action",
                                   11,
                                   "Create empty",
                                   "Print",
                                   "Append left",
                                   "Append",
                                   "Pop left",
                                   "Pop",
                                   "Size",
                                   "Clear",
                                   "Front",
                                   "Back",
                                   "Is empty"))
                    {
                        case 1 :
                        {
                            std::cout << "Enter the size of deque :" << std::endl;
                            size_t sz;
                            std::cin>>sz;
                            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            arrayDeque.create_empty(sz);
                            break;
                        }
                        case 2 :
                        {
                            arrayDeque.print();
                            break;
                        }
                        case 3 :
                        {
                            std::cout << "Input point : X Y Z" << std::endl;
                            Point pnt;
                            std::cin>>pnt;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            arrayDeque.append_left(pnt);
                            break;
                        }
                        case 4 :
                        {
                            std::cout << "Input point : X Y Z" << std::endl;
                            Point pnt;
                            std::cin>>pnt;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            arrayDeque.append(pnt);
                            break;
                        }
                        case 5 :
                        {
                            arrayDeque.pop_left();
                            break;
                        }
                        case 6 :
                        {
                            arrayDeque.pop();
                            break;
                        }
                        case 7 :
                        {
                            std::cout << "Size : " << arrayDeque.size() << std::endl;
                            break;
                        }
                        case 8 :
                        {
                            arrayDeque.clear();
                            break;
                        }
                        case 9 :
                        {
                            std::cout << "Front : " << arrayDeque.front();
                            break;
                        }
                        case 10 :
                        {
                            std::cout << "Back : " << arrayDeque.back();
                            break;
                        }
                        case 11 :
                        {
                            std::cout << "Deque is " << (arrayDeque.is_empty() ? "empty." : "not empty.") << std::endl;
                            break;
                        }
                        default:
                        {
                            act_wit_cur = false;
                        }
                    }
                    std::cout<<std::endl;
                }
                break;
            }
            case 2 : // Vector deque
            {
                bool act_wit_cur = true;
                while(act_wit_cur)
                {
                    switch (choice("Action",
                                   11,
                                   "Create empty",
                                   "Print",
                                   "Append left",
                                   "Append",
                                   "Pop left",
                                   "Pop",
                                   "Size",
                                   "Clear",
                                   "Front",
                                   "Back",
                                   "Is empty"
                    ))
                    {
                        case 1 :
                        {
                            vectorDeque.create_empty();
                            break;
                        }
                        case 2 :
                        {
                            vectorDeque.print();
                            break;
                        }
                        case 3 :
                        {
                            std::cout << "Input point : X Y Z" << std::endl;
                            Point pnt;
                            std::cin>>pnt;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            vectorDeque.append_left(pnt);
                            break;
                        }
                        case 4 :
                        {
                            std::cout << "Input point : X Y Z" << std::endl;
                            Point pnt;
                            std::cin>>pnt;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            vectorDeque.append(pnt);
                            break;
                        }
                        case 5 :
                        {
                            vectorDeque.pop_left();
                            break;
                        }
                        case 6 :
                        {
                            vectorDeque.pop();
                            break;
                        }
                        case 7 :
                        {
                            std::cout << "Size : " << vectorDeque.size() << std::endl;
                            break;
                        }
                        case 8 :
                        {
                            vectorDeque.clear();
                            break;
                        }
                        case 9 :
                        {
                            std::cout << "Front : " << vectorDeque.front();
                            break;
                        }
                        case 10 :
                        {
                            std::cout << "Back : " << vectorDeque.back();
                            break;
                        }
                        case 11 :
                        {
                            std::cout << "Deque is " << (vectorDeque.is_empty() ? "empty." : "not empty.") << std::endl;
                            break;
                        }
                        default:
                        {
                            act_wit_cur = false;
                        }
                    }
                    std::cout<<std::endl;
                }
                break;
            }
            case 3 : // Node List deque
            {
                bool act_wit_cur = true;
                while(act_wit_cur)
                {
                    switch (choice("Action",
                                   11,
                                   "Create empty",
                                   "Print",
                                   "Append left",
                                   "Append",
                                   "Pop left",
                                   "Pop",
                                   "Size",
                                   "Clear",
                                   "Front",
                                   "Back",
                                   "Is empty"
                    ))
                    {
                        case 1 :
                        {
                            nodeListDeque.create_empty();
                            break;
                        }
                        case 2 :
                        {
                            nodeListDeque.print();
                            break;
                        }
                        case 3 :
                        {
                            std::cout << "Input point : X Y Z" << std::endl;
                            Point pnt;
                            std::cin>>pnt;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            nodeListDeque.append_left(pnt);
                            break;
                        }
                        case 4 :
                        {
                            std::cout << "Input point : X Y Z" << std::endl;
                            Point pnt;
                            std::cin>>pnt;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if(std::cin.fail())
                            {
                                std::cin.clear();
                                break;
                            }
                            nodeListDeque.append(pnt);
                            break;
                        }
                        case 5 :
                        {
                            nodeListDeque.pop_left();
                            break;
                        }
                        case 6 :
                        {
                            nodeListDeque.pop();
                            break;
                        }
                        case 7 :
                        {
                            std::cout << "Size : " << nodeListDeque.size() << std::endl;
                            break;
                        }
                        case 8 :
                        {
                            nodeListDeque.clear();
                            break;
                        }
                        case 9 :
                        {
                            std::cout << "Front : " << nodeListDeque.front();
                            break;
                        }
                        case 10 :
                        {
                            std::cout << "Back : " << nodeListDeque.back();
                            break;
                        }
                        case 11 :
                        {
                            std::cout << "Deque is " << (nodeListDeque.is_empty() ? "empty." : "not empty.") << std::endl;
                            break;
                        }
                        default:
                        {
                            act_wit_cur = false;
                        }
                    }
                    std::cout<<std::endl;
                }
                break;
            }
            default :
            {
                go_ahead = false;
                break;
            }
        }
    }
}

void Application::BenchmarkMode()
{
    ArrayDeque arrayDeque [5];
    VectorDeque vectorDeque [5];
    NodeListDeque nodeListDeque [5];

    struct Result
    {
        double operation_time;
        long long mem;
    } result[3][11][5]; // 3 types of deque, 11 operations, 5 size types;

    int sizes [5]; sizes[0] = 15; // degree[i] = 15^(i + 1)
    for(int i = 1; i < 5 ; i++) sizes[i] = sizes[i - 1] * 15; //Sizes : 15 225 3375 50625 759375

    // Testing :

    Timer timer;

    std::cout << "Filling the deques ..." << std::endl;

    for (int i = 0; i < 5; i++) // create empty
    {
        timer.reset();
        arrayDeque[i].create_empty(sizes[i], false);
        result[0][0][i].operation_time = timer.elapsed();
        result[0][0][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        vectorDeque[i].create_empty(false);
        result[1][0][i].operation_time = timer.elapsed();
        result[1][0][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        nodeListDeque[i].create_empty(false);
        result[2][0][i].operation_time = timer.elapsed();
        result[2][0][i].mem = sizeof(arrayDeque[i]);

        for(int k = 1; k <= sizes[i]; k++)
        {
            arrayDeque[i].append(Point());
            vectorDeque[i].append(Point());
            nodeListDeque[i].append(Point());
        }
    }
    std::cout << "OK.\n" << endl;

    std::cout << "Testing methods ..." << std::endl;
    for(int i = 0; i < 5; i++) // pop left
    {
        timer.reset();
        arrayDeque[i].pop_left();
        result[0][3][i].operation_time = timer.elapsed();
        result[0][3][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        arrayDeque[i].pop_left();
        result[1][3][i].operation_time = timer.elapsed();
        result[1][3][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        arrayDeque[i].pop_left();
        result[2][3][i].operation_time = timer.elapsed();
        result[2][3][i].mem = sizeof(arrayDeque[i]);
    }

    for(int i = 0; i < 5; i++) // append left
    {
        timer.reset();
        arrayDeque[i].append_left(Point());
        result[0][1][i].operation_time = timer.elapsed();
        result[0][1][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        vectorDeque[i].append_left(Point());
        result[1][1][i].operation_time = timer.elapsed();
        result[1][1][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        nodeListDeque[i].append_left(Point());
        result[2][1][i].operation_time = timer.elapsed();
        result[2][1][i].mem = sizeof(arrayDeque[i]);
    }

    for(int i = 0; i < 5; i++) // pop
    {
        timer.reset();
        arrayDeque[i].pop();
        result[0][4][i].operation_time = timer.elapsed();
        result[0][4][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        arrayDeque[i].pop();
        result[1][4][i].operation_time = timer.elapsed();
        result[1][4][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        arrayDeque[i].pop();
        result[2][4][i].operation_time = timer.elapsed();
        result[2][4][i].mem = sizeof(arrayDeque[i]);
    }

    for(int i = 0; i < 5; i++) // append
    {
        timer.reset();
        arrayDeque[i].append(Point());
        result[0][2][i].operation_time = timer.elapsed();
        result[0][2][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        vectorDeque[i].append(Point());
        result[1][2][i].operation_time = timer.elapsed();
        result[1][2][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        nodeListDeque[i].append(Point());
        result[2][2][i].operation_time = timer.elapsed();
        result[2][2][i].mem = sizeof(arrayDeque[i]);
    }

    for(int i = 0; i < 5; i++) // is_empty
    {
        timer.reset();
        arrayDeque[i].is_empty();
        result[0][5][i].operation_time = timer.elapsed();
        result[0][5][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        arrayDeque[i].is_empty();
        result[1][5][i].operation_time = timer.elapsed();
        result[1][5][i].mem = sizeof(arrayDeque[i]);
        timer.reset();
        arrayDeque[i].is_empty();
        result[2][5][i].operation_time = timer.elapsed();
        result[2][5][i].mem = sizeof(arrayDeque[i]);
    }
    std::cout << "OK.\n" << endl;

    // Saving results :

    std::cout << "Saving results ..." << std::endl;

    std::ofstream fout;
    fout.open("benchmark.txt");
    if(fout.is_open())
    {
        fout << "Array deque : \n";
        fout << "---------------------------------------------------------------\n";
        for(int i = 0; i < 6; i++)
        {
            fout << '\n';
            switch (i)
            {
                case 0 :
                {
                    fout<<"create_empty : \n";
                    break;
                }
                case 1 :
                {
                    fout<<"append_left : \n";
                    break;
                }
                case 2 :
                {
                    fout<<"append : \n";
                    break;
                }
                case 3 :
                {
                    fout<<"pop_left : \n";
                    break;
                }
                case 4 :
                {
                    fout<<"pop : \n";
                    break;
                }
                case 5 :
                {
                    fout<<"is_empty : \n";
                    break;
                }
            }
            for(int j = 0; j < 5; j++)
            {
                fout << "Size " << sizes[j] << " : ";
                fout << '[' << result[0][i][j].operation_time << "ms, " << result[0][i][j].mem << " b];\t";
            }
            fout << '\n';
        }
        fout << "---------------------------------------------------------------\n\n\n";
        fout << "Vector deque : \n";
        fout << "---------------------------------------------------------------\n";
        for(int i = 0; i < 6; i++)
        {
            fout << '\n';
            switch (i)
            {
                case 0 :
                {
                    fout<<"create_empty : \n";
                    break;
                }
                case 1 :
                {
                    fout<<"append_left : \n";
                    break;
                }
                case 2 :
                {
                    fout<<"append : \n";
                    break;
                }
                case 3 :
                {
                    fout<<"pop_left : \n";
                    break;
                }
                case 4 :
                {
                    fout<<"pop : \n";
                    break;
                }
                case 5 :
                {
                    fout<<"is_empty : \n";
                    break;
                }
            }
            for(int j = 0; j < 5; j++)
            {
                fout << "Size " << sizes[j] << " : ";
                fout << '[' << result[1][i][j].operation_time << "ms, " << result[1][i][j].mem << " b];\t";
            }
            fout << '\n';
        }
        fout << "---------------------------------------------------------------\n\n\n";
        fout << "Node List deque : \n";
        fout << "---------------------------------------------------------------\n";
        for(int i = 0; i < 6; i++)
        {
            fout << '\n';
            switch (i)
            {
                case 0 :
                {
                    fout<<"create_empty : \n";
                    break;
                }
                case 1 :
                {
                    fout<<"append_left : \n";
                    break;
                }
                case 2 :
                {
                    fout<<"append : \n";
                    break;
                }
                case 3 :
                {
                    fout<<"pop_left : \n";
                    break;
                }
                case 4 :
                {
                    fout<<"pop : \n";
                    break;
                }
                case 5 :
                {
                    fout<<"is_empty : \n";
                    break;
                }
            }
            for(int j = 0; j < 5; j++)
            {
                fout << "Size " << sizes[j] << " : ";
                fout << '[' << result[2][i][j].operation_time << "ms, " << result[2][i][j].mem << " b];\t";
            }
            fout << '\n';
        }
        fout << "---------------------------------------------------------------\n\n";
        std::cout << "OK.\n" << endl;
    }
    else
    {
        std::cout << "Benchmark file can't be opened." << std::endl;
    }
    fout.close();
    exit(0);
}

short Application::choice(const char* criteria, short choice_amount, const char* variant, ...)
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

int binpow(int x, int y)
{
    if(x == 0) return 0;
    if(y == 0) return 1;

    if(y%2) return x * binpow(x, y - 1);
    else
    {
        int b = binpow(x, y/2);
        return b*b;
    }
}