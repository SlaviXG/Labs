#include "UI.h"

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