//
// Created by SlaviX on 22.09.2022.
//

#ifndef MASTER_SLAVE_MICRO_RDMS_UI_H
#define MASTER_SLAVE_MICRO_RDMS_UI_H

#include <iostream>
#include <numeric>
#include <fstream>
#include <filesystem>

#include "Entities.h"

class UI {
protected:
    //Interface functions
    void addBand();
    void updateBand();
    void deleteBand();
    void findBandByID();
    void printBands();
    void addComposition();
    void updateComposition();
    void deleteComposition();
    void printCompositionsOfTheBand();
    void printCompositions();
    void findCompositionByID();

//    //Input-output streams
//    std::fstream bands;
//    std::fstream bandsIDX;
//    std::fstream compositions;
//    std::fstream compositionsIDX;

public:
    //Constructors / Destructors
    UI();
    virtual ~UI();

    //Starting and maintaining the menu
    void interact();

private:
    //Generates the choice and returns the number of appropriate variant
    short choice(const char* criteria, short choice_amount, const char* variants, ...);
    //Save input
    template<class T> void input (T& value);
};


#endif
