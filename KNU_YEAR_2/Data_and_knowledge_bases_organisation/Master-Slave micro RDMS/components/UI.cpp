//
// Created by SlaviX on 22.09.2022.
//

#include "UI.h"

//Interface functions

void UI::exit() {
    std::exit(0);
}

//Starting and maintaining the menu
void UI::interact() {

    bool maintainingMenu = true;

    while (maintainingMenu)
    {
        switch (choice("Choose an appropriate option", 11,
                       "Add music band",
                       "Update music band",
                       "Delete music band",
                       "Find the band by ID",
                       "Print all the bands",
                       "Add composition",
                       "Update composition",
                       "Delete composition",
                       "Print compositions of the band",
                       "Print all the compositions",
                       "Find the composition by ID")) {
            case 1:
            {
                addBand();
                break;
            }
            case 2:
            {
                updateBand();
                break;
            }
            case 3:
            {
                deleteBand();
                break;
            }
            case 4:
            {
                findBandByID();
                break;
            }
            case 5:
            {
                printBands();
                break;
            }
            case 6:
            {
                addComposition();
                break;
            }
            case 7:
            {
                updateComposition();
                break;
            }
            case 8:
            {
                deleteComposition();
                break;
            }
            case 9:
            {
                printCompositionsOfTheBand();
                break;
            }
            case 10:
            {
                printCompositions();
                break;
            }
            case 11:
            {
                findCompositionByID();
                break;
            }
            default:
            {
                maintainingMenu = false;
                exit();
            }
        }
    }
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
