#include <iostream>

#include "components/UI.h"

/**
    The purpose of this project is to implement
    the model of relational database management system.

    Relation description :
    Band =- [writes] -- Composition

    Attributes:
    Band(ID, name, year)
    Composition(name, band, year, genre)
*/

int main()
{
    UI ui;
    ui.interact();

    return 0;
}
