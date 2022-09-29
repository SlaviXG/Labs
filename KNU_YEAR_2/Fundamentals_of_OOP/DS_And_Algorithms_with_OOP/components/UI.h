#ifndef DS_AND_ALGORITHMS_WITH_OOP_UI_H
#define DS_AND_ALGORITHMS_WITH_OOP_UI_H

#include <iostream>

#include "SkipList.h"

class UI {
public:
    //Constructors / Destructors
    UI();
    virtual ~UI();

    //Starting and maintaining the menu
    void interact();

private:
    //Generates the choice and returns the number of appropriate variant
    short choice(const char* criteria, short choice_amount, const char* variants, ...);
    //Safe input
    template<class T> void input (T& value);
};


#endif //DS_AND_ALGORITHMS_WITH_OOP_UI_H
