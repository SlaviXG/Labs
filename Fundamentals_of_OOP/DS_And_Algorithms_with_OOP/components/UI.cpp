#include "UI.h"

//Constructors / Destructors
UI::UI()
{

}

UI::~UI()
{

}

//Starting and maintaining the menu
void UI::interact()
{
    // Simple demonstration of the methods

    std::cout << "Primitive type -- double :" << std::endl;
    SkipList <double> doubleList (-std::numeric_limits<double>::max());
    std::cout << "Insert 132.086 :" << std::endl;
    doubleList.insert(132.086);
    doubleList.print();
    std::cout << "Insert 175.052 :" << std::endl;
    doubleList.insert(175.052);
    doubleList.print();
    std::cout << "Insert 175.052 :" << std::endl;
    doubleList.insert(175.052);
    doubleList.print();


    std::cout << "Primitive type -- string :" << std::endl;

    std::cout << "Primitive type -- double :" << std::endl;
    SkipList <std::string> strList ("");
    std::cout << "Insert abc :" << std::endl;
    strList.insert("abc");
    strList.print();
    std::cout << "Insert lol :" << std::endl;
    strList.insert("lol");
    strList.print();
    std::cout << "Insert aaa :" << std::endl;
    strList.insert("aaa");
    strList.print();

    std::cout << "Advanced type -- Time :" << std::endl;
    SkipList <datetime::Time> timeList ((datetime::Time()));

    datetime::Time a;
    std::cout << "Insert " << a << " :" <<  std::endl;
    timeList.insert(a);

    a.year = 1993;
    std::cout << "Insert " << a << " :" <<  std::endl;
    timeList.insert(a);
    timeList.print();

    a.year = 1967;
    std::cout << "Insert " << a << " :" <<  std::endl;
    timeList.insert(a);
    timeList.print();
}

//Generates the choice and returns the number of appropriate variant
short UI::choice(const char *criteria, short choice_amount, const char *variants, ...) {
    const char** ptr = &variants;
    // Printing variants :
    std::cout << criteria << " : \n";
    for (short i = 1; i<=choice_amount; i++)
    {
        std::cout << i << "\t-\t" << *(ptr++) << '\n';
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

//Safe input
template<class T>
void UI::input(T &value) {
    bool incorrectInput = true;
    while (incorrectInput)
    {
        std::cin>>value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Processing input :
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input. Try again." << std::endl;
        }
        else
        {
            incorrectInput = false;
        }
    }
}