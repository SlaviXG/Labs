#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <time.h>

#include "Naive.h"
#include "Horspool.h"
#include "Rabin_Karp.h"

#include <iostream>

TEST_CASE("General algorithm correctness")
{
    SUBCASE("Naive")
    {
        CHECK(Naive::findPattern("2", "123")[0] == 1);
        CHECK(Naive::findPattern("123", "2").size() == 0);
        CHECK(Naive::findPattern("2", "abacaba").size() == 0);
        CHECK(Naive::findPattern("ca", "abacaba")[0] == 3);
        CHECK(Naive::findPattern("XDr", "Zn&S7)K3kW*XDrW%X8KHWRwFEnI(8ZGjH%(#yL9dk6%2)P4Cq&")[0] == 11);
    }

    SUBCASE("Horspool")
    {
        CHECK(Horspool::findPattern("2", "123")[0] == 1);
        CHECK(Horspool::findPattern("123", "2").size() == 0);
        CHECK(Horspool::findPattern("2", "abacaba").size() == 0);
        CHECK(Horspool::findPattern("ca", "abacaba")[0] == 3);
        CHECK(Horspool::findPattern("XDr", "Zn&S7)K3kW*XDrW%X8KHWRwFEnI(8ZGjH%(#yL9dk6%2)P4Cq&")[0] == 11);
    }

    SUBCASE("Rabin_Karp")
    {
        int primeNum = 97;

        CHECK(Rabin_Karp::findPattern("2", "123", primeNum)[0] == 1);
        CHECK(Rabin_Karp::findPattern("123", "2", primeNum).size() == 0);
        CHECK(Rabin_Karp::findPattern("2", "abacaba", primeNum).size() == 0);
        CHECK(Rabin_Karp::findPattern("ca", "abacaba", primeNum)[0] == 3);
        CHECK(Rabin_Karp::findPattern("XDr", "Zn&S7)K3kW*XDrW%X8KHWRwFEnI(8ZGjH%(#yL9dk6%2)P4Cq&", primeNum)[0] == 11);
    }
}
