#include <gtest/gtest.h>

#include "UI.h"

TEST(TimeStructure, Arithmetics1)
{
    datetime::Time A, B;

    A.day = 10; B.day = 10;
    A.month = 1; B.month = 1;
    A.year = 10; B.year = 200;
    A.isNegative = false; B.isNegative = true;

    EXPECT_EQ(A-B+B,A);

}