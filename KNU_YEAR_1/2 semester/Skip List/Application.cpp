#include "Application.h"

using std::cin;
using std::cout;
using std::endl;

void Application::DemoMode()
{
    SkipList skipList;

    std::cerr << "Starting Demonstration...\n"
                 "every time press enter to continue.\n" << std::endl;
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "2" << std::endl;
    getchar();
    skipList.print();
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "1" << std::endl;
    getchar();
    std::cout << "Enter a value :" << std::endl;
    getchar();
    std::cout << "123" << std::endl;
    skipList.insert(123);
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "2" << std::endl;
    getchar();
    skipList.print();
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "1" << std::endl;
    getchar();
    std::cout << "Enter a value :" << std::endl;
    getchar();
    std::cout << "2307" << std::endl;
    skipList.insert(2307);
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "1" << std::endl;
    getchar();
    std::cout << "Enter a value :" << std::endl;
    getchar();
    std::cout << "-19" << std::endl;
    skipList.insert(-19);
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "2" << std::endl;
    getchar();
    skipList.print();
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "3" << std::endl;
    getchar();
    std::cout << "Enter a value :" << std::endl;
    getchar();
    std::cout << "-19" << std::endl;
    getchar();
    std::cout << "Found" << std::endl;
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "3" << std::endl;
    getchar();
    std::cout << "Enter a value :" << std::endl;
    getchar();
    std::cout << "500" << std::endl;
    getchar();
    std::cout << "Not found" << std::endl;
    getchar();
    std::cout << "Action : \n"
                 "1 - Insert integer\n"
                 "2 - Print\n"
                 "3 - Find integer\n"
                 "Or type anything else to exit." << std::endl;
    getchar();
    std::cout << "abacaba" << std::endl;
    getchar();
    std::cerr << "Demonstration ended." << std:: endl;
}

void Application::InteractiveMode()
{
    SkipList skipList;

    bool go_ahead = true;

    while(go_ahead)
    {
        switch(choice("Action", 3, "Insert integer", "Print", "Find integer"))
        {
            case 1:
            {
                std::cout << "Enter a value :" << std::endl;
                int x;
                std::cin >> x;
                if(std::cin.fail())
                {
                    std::cin.clear();
                    break;
                }
                skipList.insert(x);
                std::cout << std::endl;
                break;
            }
            case 2:
            {
                skipList.print();
                std::cout << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Enter a value :" << std::endl;
                int x;
                std::cin >> x;
                if(std::cin.fail())
                {
                    std::cin.clear();
                    break;
                }
                if(skipList.findNode(x))
                    std::cout << "Found" << std::endl;
                else
                    std::cout << "Not found" << std::endl;
                std::cout << std::endl;
                break;
            }
            default:
            {
                go_ahead = false;
            }
        }
    }
}

void Application::BenchmarkMode()
{
    SkipList skipList;
    Timer timer;
    int cnt;
    double result [50][2];

    std::cout << "Starting ..." << std::endl;

    cnt = 0;

    for(int i = 5; i <= 500; i+=10)
    {
        timer.reset();
        skipList.insert(i);
        result[cnt][0] = timer.elapsed();
        cnt++;
    }

    cnt = 0;

    for(int i = 5; i <= 250; i+=5)
    {
        timer.reset();
        skipList.findNode(i);
        result[cnt][1] = timer.elapsed();
        cnt++;
    }

    std::ofstream fout;
    fout.open("benchmark.txt");
    if(fout.is_open())
    {
        int i;
        fout << "Insertion : \n"
                "--------------------------------------------------------------------------\n";
        for(i = 0; i < 50; i++)
        {
            fout << result[i][0] << " ms;\n";
        }
        fout << "--------------------------------------------------------------------------\n";
        fout << "Searching : \n"
                "--------------------------------------------------------------------------\n";
        for(i = 0; i < 50; i++)
        {
            fout << result[i][1] << " ms;\n";
        }
        fout << "--------------------------------------------------------------------------\n";
    }
    else
    {
        std::cout << "Benchmark file can't be opened." << std::endl;
    }
    fout.close();
    std::cout << "OK." << std::endl;
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