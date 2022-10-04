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

TEST(TimeStructure, Arithmetics2)
{
    datetime::Time A, B;

    A.day = 10; B.day = 10;
    A.month = 1; B.month = 1;
    A.year = 10; B.year = 200;
    A.isNegative = false; B.isNegative = false;

    EXPECT_EQ(A-B+B,A);
}

TEST(TimeStructure, Arithmetics3)
{
    datetime::Time A, B;

    A.day = 10; B.day = 10;
    A.month = 11; B.month = 1;
    A.year = 10; B.year = 50;
    A.isNegative = false; B.isNegative = false;

    EXPECT_EQ(A-B+B,A);
}

TEST(TimeStructure, Arithmetics4)
{
    datetime::Time A, B;

    A.day = 20; B.day = 10;
    A.month = 0; B.month = 11;
    A.year = 61; B.year = 10;
    A.isNegative = false; B.isNegative = false;

    EXPECT_EQ(B-A+A,B);
}

TEST(LeapYearTest, LeapTest1)
{
    EXPECT_TRUE(datetime::isYearLeap(2000));
}

TEST(LeapYearTest, LeapTest2)
{
    EXPECT_FALSE(datetime::isYearLeap(1999));
}

TEST(LeapYearTest, LeapTest3)
{
    EXPECT_FALSE(datetime::isYearLeap(1900));
}

TEST(LeapYearTest, LeapTest4)
{
    EXPECT_TRUE(datetime::isYearLeap(2012));
}

TEST(DayNumInYear, DayNum1)
{
    datetime::Time A;

    A.day = 8;
    A.month = 0;
    A.year = 2018;

    EXPECT_EQ(datetime::getDayNumInYear(A.day + 1, A.month + 1, A.year + 1), 9);
}

TEST(DayNumInYear, DayNum2)
{
    datetime::Time A;

    A.day = 0;
    A.month = 2;
    A.year = 2002;

    EXPECT_EQ(datetime::getDayNumInYear(A.day + 1, A.month + 1, A.year + 1), 60);
}

TEST(WeekNumInYear, WeekNum1)
{
    datetime::Time A;

    A.day = 0;
    A.month = 0;
    A.year = 2002;

    EXPECT_EQ(datetime::getWeekNumInYear(A.day,A.month, A.year), 1);
}

TEST(WeekNumInYear, WeekNum2)
{
    datetime::Time A;

    A.day = 0;
    A.month = 1;
    A.year = 2002;

    EXPECT_EQ(datetime::getWeekNumInYear(A.day,A.month, A.year), 5);
}