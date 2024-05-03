#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Naive.h"
#include "Horspool.h"
#include "Rabin_Karp.h"

#include "auxiliary.h"
#include "doctest.h"

#include <iostream>
#include <time.h>

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

TEST_CASE("Benchmarking algorithms")
{
    std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
    int MIN_LENGTH = 131072, MAX_LENGTH = 2097152;

    SUBCASE("Binary alphabet")
    {
        SUBCASE("Naive")
        {
            for(int N = MIN_LENGTH; N <= MAX_LENGTH; N*=2)
            {
                for(int M = 1; M <= N; M*=2)
                {
                    std::string randS = random_binary_string(N);
                    std::string randP = random_binary_string(random_int(N/2, 0));

                    startTime = std::chrono::system_clock::now();
                    Naive::findPattern(randP, randS);
                    endTime = std::chrono::system_clock::now();

                    std::cout <<  "Bin," << " Naive, TLen = " << N << " PLen = " << M << ",  "
                              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                              << " ms" << std::endl;
                }
            }
        }

        std::cout << std::endl;

        SUBCASE("Horspool")
        {
            for(int N = MIN_LENGTH; N <= MAX_LENGTH; N*=2)
            {
                for(int M = 1; M <= N; M*=2)
                {
                    std::string randS = random_binary_string(N);
                    std::string randP = random_binary_string(random_int(N/2, 0));

                    startTime = std::chrono::system_clock::now();
                    Horspool::findPattern(randP, randS);
                    endTime = std::chrono::system_clock::now();

                    std::cout <<  "Bin," << " Horspool, TLen = " << N << " PLen = " << M << ",  "
                              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                              << " ms" << std::endl;
                }
            }
        }

        std::cout << std::endl;

        SUBCASE("Rabin_Karp")
        {
            int primeNum = 89;

            for(int N = MIN_LENGTH; N <= MAX_LENGTH; N*=2)
            {
                for(int M = 1; M <= N; M*=2)
                {
                    std::string randS = random_binary_string(N);
                    std::string randP = random_binary_string(random_int(N/2, 0));

                    startTime = std::chrono::system_clock::now();
                    Rabin_Karp::findPattern(randP, randS, primeNum);
                    endTime = std::chrono::system_clock::now();

                    std::cout <<  "Bin," << " Rabin-Karp, TLen = " << N << " PLen = " << M << ",  "
                              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                              << " ms" << std::endl;
                }
            }
        }
    }

    SUBCASE("Natural alphabet")
    {
        SUBCASE("Naive") {
            for (int N = MIN_LENGTH; N <= MAX_LENGTH; N *= 2) {
                for (int M = 1; M <= N; M *= 2) {
                    std::string randS = random_string(N);
                    std::string randP = random_string(random_int(N / 2, 0));

                    startTime = std::chrono::system_clock::now();
                    Naive::findPattern(randP, randS);
                    endTime = std::chrono::system_clock::now();

                    std::cout << "Nat," << " Naive, TLen = " << N << " PLen = " << M << ",  "
                              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                              << " ms" << std::endl;
                }
            }
        }

        std::cout << std::endl;

        SUBCASE("Horspool") {
            for (int N = MIN_LENGTH; N <= MAX_LENGTH; N *= 2) {
                for (int M = 1; M <= N; M *= 2) {
                    std::string randS = random_string(N);
                    std::string randP = random_string(random_int(N / 2, 0));

                    startTime = std::chrono::system_clock::now();
                    Horspool::findPattern(randP, randS);
                    endTime = std::chrono::system_clock::now();

                    std::cout << "Nat," << " Horspool, TLen = " << N << " PLen = " << M << ",  "
                              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                              << " ms" << std::endl;
                }
            }
        }

        std::cout << std::endl;

        SUBCASE("Rabin_Karp") {
            int primeNum = 89;

            for (int N = MIN_LENGTH; N <= MAX_LENGTH; N *= 2) {
                for (int M = 1; M <= N; M *= 2) {
                    std::string randS = random_string(N);
                    std::string randP = random_string(random_int(N / 2, 0));

                    startTime = std::chrono::system_clock::now();
                    Rabin_Karp::findPattern(randP, randS, primeNum);
                    endTime = std::chrono::system_clock::now();

                    std::cout << "Nat," << " Rabin-Karp, TLen = " << N << " PLen = " << M << ",  "
                              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                              << " ms" << std::endl;
                }
            }
        }
    }
}