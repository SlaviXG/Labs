//
// Created by SlaviX on 22.09.2022.
//

#include "UI.h"

//Constructors / Destructors
UI::UI() {
//    this->bands = std::fstream("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary|std::fstream::app);
//    this->bandsIDX = std::fstream("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary|std::fstream::app);
//    this->compositions = std::fstream("../data/compositions.dat", std::ios::in | std::ios::out | std::ios::binary|std::fstream::app);
//    //this->compositionsIDX = std::fstream("../data/compositions.idx", std::ios::in | std::ios::out | std::ios::binary|std::fstream::app);
//
//    if(!bands.is_open() || !bandsIDX.is_open() || !compositions.is_open() || !compositionsIDX.is_open())
//        std::cerr << "File can not be opened." << std::endl;

    //TODO: Loading from file, delete streams from the constructor
}

UI::~UI() {
//    bands.close();
//    bandsIDX.close();
//    compositions.close();
//    //compositionsIDX.close();
}

//Interface functions

void UI::addBand() {

    //Creating streams
    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary|std::fstream::app);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary|std::fstream::app);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cerr << std::endl << "Bands data files cannot be opened." << std::endl;
        return;
    }

    //Creating the Band object
    Band band{};

    std::cout << "Enter band name (20 symbols max.) :" << std::endl;
    input(band.name);
    std::cout << "Enter a year of creation :" << std::endl;
    input(band.year);

    //Stating the flag that the record exists
    band.exists = true;

    //Creating the object of further IDX record
    BandIDX bandIdx {};
    bandIdx.exists = true;
    bandIdx.numberOfCompositions = 0;
    bandIdx.compositionAddress = -1;

    //Moving to the end of the data file
    bands.seekp(0, std::ios::end);

    //Getting the address before writing
    bandIdx.bandAddress = bands.tellp();

    //Counting the ID to save
    bandIdx.ID = bandIdx.bandAddress / (sizeof(Band));

    //Writing to the data file
    bands.write((char*)&(band), sizeof(Band));

    //Closing the stream
    bands.close();

    //Moving to the end of the idx file
    bandsIDX.seekp(0, std::ios::end);

    //Writing to the idx file
    bandsIDX.write((char*)&(bandIdx), sizeof(BandIDX));

    //Closing the stream
    bandsIDX.close();

    std::cout << std::endl << "The band is added successfully." << std::endl << std::endl;

    //TODO: Write on free space
}

void UI::updateBand() {
    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cerr << std::endl << "Bands data files cannot be opened." << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter the band ID :" << std::endl;
    input(ID);

    //Creating the BandIDX object to read in
    BandIDX bandIdx{};

    //Address to read from
    long long address = ID * sizeof(BandIDX);

    //Reading
    bandsIDX.seekg(address, std::ios::beg);
    bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX));

    if(bandIdx.exists)
    {
        //Creating the Band object to read in
        Band band {};

        //Reading
        bands.seekg(bandIdx.bandAddress, std::ios::beg);
        bands.read(reinterpret_cast<char *>(&band), sizeof(Band));

        std::cout << "Band name : " << band.name << std::endl;
        std::cout << "Year of creation : " << band.year << std::endl;

        std::cout << std::endl;

        switch (choice("Which attribute would you like to change?", 2, "Band name", "Year of creation")) {
            case 1:
            {
                std::cout << "Enter new band name :" << std::endl;
                input(band.name);
                bands.seekp(bandIdx.bandAddress, std::ios::beg);
                bands.seekg(bandIdx.bandAddress, std::ios::beg);
                bands.write((char*)&(band), sizeof(Band));
                std::cout << "Changed successfully" << std::endl << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Enter a new year :" << std::endl;
                input(band.year);
                bands.seekp(bandIdx.bandAddress, std::ios::beg);
                bands.write((char*)&(band), sizeof(Band));
                std::cout << "Changed successfully." << std::endl << std::endl;
                break;
            }
        }

    }
    else
    {
        std::cerr << "There's no such band in the database." << std::endl;
    }

    bands.close();
    bandsIDX.close();

}

void UI::findBandByID() {

    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary|std::fstream::app);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary|std::fstream::app);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cerr << std::endl << "Bands data files cannot be opened." << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter the band ID :" << std::endl;
    input(ID);

    //Creating the BandIDX object to read in
    BandIDX bandIdx{};

    //Address to read from
    long long address = ID * sizeof(BandIDX);

    //Reading
    bandsIDX.seekg(address, std::ios::beg);
    bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX));

    if(bandIdx.exists)
    {
        //Creating the Band object to read in
        Band band {};

        //Reading
        bands.seekg(bandIdx.bandAddress, std::ios::beg);
        bands.read(reinterpret_cast<char *>(&band), sizeof(Band));

        std::cout << "Band name : " << band.name << std::endl;
        std::cout << "Year of creation : " << band.year << std::endl;
        std::cout << "Number of compositions : " << bandIdx.numberOfCompositions << std::endl;
    }
    else
    {
        std::cout << "There's no such band in the database." << std::endl;
    }

    std::cout << std::endl;

    bands.close();
    bandsIDX.close();
}

void UI::printBands() {
    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary|std::fstream::app);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary|std::fstream::app);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cerr << std::endl << "Bands data files cannot be opened." << std::endl;
        return;
    }

    //Creating the objects to read in
    BandIDX bandIdx;
    Band band;

    //Reading
    bandsIDX.seekg(0, std::ios::beg);
    bands.seekg(0, std::ios::beg);

    while (bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX)))
    {
        if(bandIdx.exists)
        {
            bands.read(reinterpret_cast<char *>(&band), sizeof(Band));

            std::cout << "Band ID : " << bandIdx.ID << std::endl;
            std::cout << "Band name : " << band.name << std::endl;
            std::cout << "Year of creation : " << band.year << std::endl;
            std::cout << "Number of compositions : " << bandIdx.numberOfCompositions << std::endl;

            std::cout << std::endl;
        }
    }

    //Checking the end of the file
    bandsIDX.seekg(0, std::ios::end);
    long long END = bandsIDX.tellg(); // End of the file

    bands.close();
    bandsIDX.close();
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
//            case 3:
//            {
//                deleteBand();
//                break;
//            }
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
//            case 6:
//            {
//                addComposition();
//                break;
//            }
//            case 7:
//            {
//                updateComposition();
//                break;
//            }
//            case 8:
//            {
//                deleteComposition();
//                break;
//            }
//            case 9:
//            {
//                printCompositionsOfTheBand();
//                break;
//            }
//            case 10:
//            {
//                printCompositions();
//                break;
//            }
//            case 11:
//            {
//                findCompositionByID();
//                break;
//            }
            default:
            {
                maintainingMenu = false;
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

template<class T>
void UI::input(T &value) {
    bool incorrectInput = true;
    while (incorrectInput)
    {
        std::cin>>value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Processing input :
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Incorrect input. Try again." << std::endl;
        }
        else
        {
            incorrectInput = false;
        }
    }
}
