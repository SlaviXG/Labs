#include <iostream>
#include <gtest/gtest.h>

#include "components/UI.h"

int main()
{
    UI ui;
    ui.interact();

    datetime::Time A, B;
    A.day = 10; B.day = 10;
    A.month = 1; B.month = 1;
    A.year = 10; B.year = 200;
    A.isNegative = true; B.isNegative = false;

    datetime::printTime(A);
    datetime::printTime(B);
    datetime::printTime(A+B);
    datetime::printTime(A-B);

    return 0;
}
