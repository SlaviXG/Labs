#ifndef A__APP_H
#define A__APP_H

#include <iostream>
#include "Point.h"
#include "Timer.h"

/*
    Wrapper class.
*/

class App
{
public:
    //Function that gets user's input and returns a result of choice
    static short choice(const char* criteria, short choice_amount, const char* variant, ...);

    //App modes
    static void DemoMode();
    static void BenchmarkMode();

    //In-app sorting functions
    static void insertionSort(Point* point_array, int n, bool printing = false);
    static void quickSort(Point* point_array, int low, int high, int max_size, bool printing = false); //from 0 to n-1
    static void mergeSort(Point* point_array, int begin, int end, int max_size, bool printing = false); //from 0 to n-1
    static void combinedSort(Point* point_array, int begin, int end, unsigned threshold, int max_size, bool printing = false); //from 0 to n-1

    //Array-printing function
    static void printArray(Point* point_array, int n);

    //Auxiliary function to quick-sort
    static int partition(Point* point_array, int low, int high);
    //Auxiliary function to merge-sort
    static void merge(Point* point_array, int left, int mid, int right);
};

int binpow(int, int);


#endif //A__APP_H
