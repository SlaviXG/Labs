//
// Created by SlaviX on 22.09.2022.
//

#include "UI.h"

//Constructors / Destructors
UI::UI() {

    //Creating files
    std::ofstream bands("../data/bands.dat", std::ios::out|std::ios::binary|std::fstream::app);
    std::ofstream bandsIDX("../data/bands.idx", std::ios::out | std::ios::binary|std::fstream::app);
    std::ofstream compositions("../data/compositions.dat", std::ios::out|std::ios::binary|std::fstream::app);

    bands.close();
    bandsIDX.close();
    compositions.close();
}

UI::~UI() {

}

//Interface functions

void UI::addBand() {

    //Creating streams
    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cout << std::endl << "Bands data files cannot be opened." << std::endl;
        return;
    }

    //Creating the Band object
    Band band{};

    std::cout << "Enter the band name (20 symbols max.) :" << std::endl;
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
        std::cout << std::endl << "Bands data files cannot be opened." << std::endl;
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
                bands.write((char*)&(band), sizeof(Band));
                std::cout << "Changed successfully." << std::endl << std::endl;
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
        std::cout << "There's no such band in the database." << std::endl;
    }

    bands.close();
    bandsIDX.close();

}

void::UI::deleteBand()
{
    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    if(!bands.is_open() || !bandsIDX.is_open() || !compositions.is_open())
    {
        std::cout << std::endl << "Data files cannot be opened." << std::endl;
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

        //Deleting
        band.exists = false;
        bandIdx.exists = false;

        bands.seekp(bandIdx.bandAddress, std::ios::beg);
        bands.write((char*)&(band), sizeof(Band));

        bandsIDX.seekp(address, std::ios::beg);
        bandsIDX.write((char*)&(bandIdx), sizeof(BandIDX));

        if(bandIdx.numberOfCompositions)
        {
            //Creating the Composition object
            Composition composition{};

            long long curAddress;
            composition.nextCompAddress = bandIdx.compositionAddress;
            while(composition.nextCompAddress != -1)
            {
                curAddress = composition.nextCompAddress;
                compositions.seekg(curAddress, std::ios::beg);
                compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition));
                composition.exists = false;
                compositions.seekp(curAddress, std::ios::beg);
                compositions.write(reinterpret_cast<char *>(&composition), sizeof(Composition));
            }
        }

        std::cout << "Successfully deleted." << std::endl << std::endl;
    }
    else
    {
        std::cout << "There's no such band in the database." << std::endl;
    }

    bands.close();
    bandsIDX.close();
    compositions.close();
}

void UI::findBandByID() {

    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cout << std::endl << "Bands data files cannot be opened." << std::endl;
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
        Band band{};

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
    std::fstream bands("../data/bands.dat", std::ios::in|std::ios::out|std::ios::binary);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    if(!bands.is_open() || !bandsIDX.is_open())
    {
        std::cout << std::endl << "Bands data files cannot be opened." << std::endl;
        return;
    }

    //Creating the objects to read in
    BandIDX bandIdx;
    Band band;

    //Reading
    bandsIDX.seekg(0, std::ios::beg);
    bands.seekg(0, std::ios::beg);

    int counter = 0;

    while (bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX)))
    {
        bands.read(reinterpret_cast<char *>(&band), sizeof(Band));
        if(bandIdx.exists)
        {
            counter++;

            std::cout << "Band ID : " << bandIdx.ID << std::endl;
            std::cout << "Band name : " << band.name << std::endl;
            std::cout << "Year of creation : " << band.year << std::endl;
            std::cout << "Number of compositions : " << bandIdx.numberOfCompositions << std::endl;

            std::cout << std::endl;
        }
    }

    std::cout << counter << " band" << ((counter-1)?"s":"") << " in total." << std::endl << std::endl;


    bands.close();
    bandsIDX.close();
}

void UI::addComposition() {
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    if(!bandsIDX.is_open() || !compositions.is_open())
    {
        std::cout << std::endl << "Data files cannot be opened." << std::endl;
        return;
    }

    //Creating the Composition object
    Composition composition{};

    std::cout << "Enter the composition name (20 symbols max.) :" << std::endl;
    input(composition.name);
    std::cout << "Enter a year of creation :" << std::endl;
    input(composition.year);
    std::cout << "Enter the composition genre (25 symbols max.) :" << std::endl;
    input(composition.genre);

    composition.exists = true;
    composition.nextCompAddress = -1;

    //Entering band ID
    int bandID;
    std::cout << "Enter author band's ID :" << std::endl;
    input(bandID);

    //Creating the BandIDX object to read in
    BandIDX bandIdx{};

    //Address to read from
    long long address = bandID * sizeof(BandIDX);

    //Reading
    bandsIDX.seekg(address, std::ios::beg);
    bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX));

    //Inserting
    if(bandIdx.exists)
    {
        if(!bandIdx.numberOfCompositions)
        {
            bandIdx.numberOfCompositions++;

            //Moving to the end of the data file
            compositions.seekp(0, std::ios::end);

            //Counting the composition ID
            composition.ID = compositions.tellp()/sizeof(Composition);

            //Get composition address
            bandIdx.compositionAddress = compositions.tellp();

            //Writing the composition
            compositions.write((char*)&(composition), sizeof(Composition));

        }
        else
        {
            bandIdx.numberOfCompositions++;

            long long curAddress;
            Composition tempComposition {};
            tempComposition.nextCompAddress = bandIdx.compositionAddress;
            while(tempComposition.nextCompAddress != -1)
            {
                curAddress = tempComposition.nextCompAddress;
                compositions.seekg(curAddress, std::ios::beg);
                compositions.read(reinterpret_cast<char *>(&tempComposition), sizeof(Composition));
            }

            //Moving to the end of the data file
            compositions.seekp(0, std::ios::end);

            //Counting the composition ID
            composition.ID = compositions.tellp()/sizeof(Composition);

            //Saving the address of the new composition to the previous
            tempComposition.nextCompAddress = compositions.tellp();

            //Writing new composition
            compositions.write((char*)&(composition), sizeof(Composition));

            compositions.close();
            std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
            //Moving to the address of previous composition
            compositions.seekp(curAddress, std::ios::beg);

            //Updating the previous composition
            compositions.write((char*)&(tempComposition), sizeof(Composition));
        }

        //Rewrite the bandIdx data
        bandsIDX.seekp(address, std::ios::beg);
        bandsIDX.write(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX));
    }
    else
    {
        std::cout << "There's no such band in the database." << std::endl;
    }

    std::cout << std::endl;

    bandsIDX.close();
    compositions.close();

    //TODO: write on free space
}

void UI::updateComposition() {
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    if(!compositions.is_open())
    {
        std::cout << std::endl << "Compositions data file cannot be opened." << std::endl;
        return;
    }

    Composition composition = {};
    std::cout << "Enter the ID of composition :" << std::endl;
    input(composition.ID);

    long long address = composition.ID * sizeof(Composition);

    compositions.seekg(address, std::ios::beg);
    compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition));

    if(composition.exists)
    {
        switch (choice("Which attribute would you like to change?", 3,
                       "Name", "Year", "Genre")){
            case 1:
            {
                std::cout << "Enter new composition name :" << std::endl;
                input(composition.name);
                compositions.seekp(address, std::ios::beg);
                compositions.write((char*)&(composition), sizeof(Composition));
                std::cout << "Changed successfully." << std::endl << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Enter a new year :" << std::endl;
                input(composition.year);
                compositions.seekp(address, std::ios::beg);
                compositions.write((char*)&(composition), sizeof(Composition));
                std::cout << "Changed successfully." << std::endl << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Enter new genre :" << std::endl;
                input(composition.genre);
                compositions.seekp(address, std::ios::beg);
                compositions.write((char*)&(composition), sizeof(Composition));
                std::cout << "Changed successfully." << std::endl << std::endl;
                break;
            }
        }
    }
    else
    {
        std::cout << "There's no such composition in the database." << std::endl;
    }

    compositions.close();
}

void UI::deleteComposition() {
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    if(!compositions.is_open() || !bandsIDX.is_open())
    {
        std::cout << std::endl << "Data files cannot be opened." << std::endl;
        return;
    }

    int bandID;
    std::cout << "Enter the ID of author Band :" << std::endl;
    input(bandID);

    //Creating the BandIDX object to read in
    BandIDX bandIdx{};

    //Address to read from
    long long bandAddress = bandID * sizeof(BandIDX);

    //Reading
    bandsIDX.seekg(bandAddress, std::ios::beg);
    bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX));

    if(bandIdx.exists)
    {
        if(bandIdx.numberOfCompositions)
        {
            Composition composition = {};
            int compositionID;
            std::cout << "Enter the ID of composition of this author to delete :" << std::endl;
            input(compositionID);
            long long compositionAddress = compositionID * sizeof(Composition);

            long long curAddress = -1;
            composition.nextCompAddress = bandIdx.compositionAddress;
            bool found = false;

            if(bandIdx.compositionAddress == compositionAddress)
            {
                found = true;

                //Reading the composition by address
                compositions.seekg(compositionAddress, std::ios::beg);
                compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition));

                composition.exists = false;

                compositions.seekp(compositionAddress, std::ios::beg);
                compositions.write(reinterpret_cast<char *>(&composition), sizeof(Composition));

                bandIdx.numberOfCompositions--;

                if(bandIdx.numberOfCompositions == 0) // The first comp. == the only one comp.
                {
                    bandIdx.compositionAddress = -1;
                    bandsIDX.seekp(bandAddress, std::ios::beg);
                    bandsIDX.write((char*)&(bandIdx), sizeof(BandIDX));

                }
                else // The first comp. contains further comps.
                {
                    bandIdx.compositionAddress = composition.nextCompAddress;
                    bandsIDX.seekp(bandAddress, std::ios::beg);
                    bandsIDX.write((char*)&(bandIdx), sizeof(BandIDX));
                }

                std::cout << "Successfully deleted." << std::endl << std::endl;
            }
            else
            {
                while(composition.nextCompAddress != -1)
                {
                    curAddress = composition.nextCompAddress;
                    compositions.seekg(curAddress, std::ios::beg);

                    compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition));

                    if(composition.nextCompAddress == compositionAddress) //If current.next == searched
                    {
                        found = true;

                        Composition nextComp = {};

                        long long targetAdr = composition.nextCompAddress; // searched address

                        //reading the searched composition to nextComp
                        compositions.seekg(targetAdr, std::ios::beg);
                        compositions.read(reinterpret_cast<char *>(&nextComp), sizeof(Composition));

                        //current.next address = searched.next address, excluding the searched
                        composition.nextCompAddress = nextComp.nextCompAddress;
                        
                        compositions.seekp(curAddress, std::ios::beg);
                        compositions.write(reinterpret_cast<char *>(&composition), sizeof(Composition));

                        //rewriting the searched composition
                        nextComp.exists = false;
                        compositions.seekp(targetAdr, std::ios::beg);
                        compositions.write(reinterpret_cast<char *>(&nextComp), sizeof(Composition));

                        //updating bandIDX
                        bandIdx.numberOfCompositions--;

                        bandsIDX.seekp(bandAddress, std::ios::beg);
                        bandsIDX.write((char*)&(bandIdx), sizeof(BandIDX));

                        std::cout << "Successfully deleted." << std::endl << std::endl;

                        break;
                    }
                }
                if(!found)
                {
                    std::cout << "There's no such composition of this author." << std::endl;
                }
            }
        }
        else
        {
            std::cout << "The band has 0 compositions added." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << "There's no such band in the database." << std::endl;
    }

    compositions.close();
    bandsIDX.close();
}

void UI::printCompositionsOfTheBand() {
    std::fstream bandsIDX("../data/bands.idx", std::ios::in | std::ios::out | std::ios::binary);
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    if(!bandsIDX.is_open() || !compositions.is_open())
    {
        std::cout << std::endl << "Data files cannot be opened." << std::endl;
        return;
    }

    //Creating the Composition object
    Composition composition{};

    int bandID;
    std::cout << "Enter the band ID :" << std::endl;
    input(bandID);

    //Creating the BandIDX object to read in
    BandIDX bandIdx{};

    //Address to read from
    long long address = bandID * sizeof(BandIDX);

    //Reading
    bandsIDX.seekg(address, std::ios::beg);
    bandsIDX.read(reinterpret_cast<char *>(&bandIdx), sizeof(BandIDX));

    if(bandIdx.exists)
    {
        int counter = 0;
        if(bandIdx.numberOfCompositions)
        {
            long long curAddress;
            composition.nextCompAddress = bandIdx.compositionAddress;
            while(composition.nextCompAddress != -1)
            {
                counter++;
                curAddress = composition.nextCompAddress;
                compositions.seekg(curAddress, std::ios::beg);
                compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition));
                std::cout << "Composition ID : " << composition.ID << std::endl;
                std::cout << "Composition name : " << composition.name << std::endl;
                std::cout << "Year of creation : " << composition.year << std::endl;
                std::cout << "Genre : " << composition.genre << std::endl;

                std::cout << std::endl;
            }
        }
        std::cout << counter << " composition" << ((counter-1)?"s":"") << " in total." << std::endl << std::endl;
    }
    else
    {
        std::cout << "There's no such band in the database." << std::endl;
    }

    std::cout << std::endl;

    bandsIDX.close();
    compositions.close();
}

void UI::printCompositions() {
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    if(!compositions.is_open())
    {
        std::cout << std::endl << "Compositions data files cannot be opened." << std::endl;
        return;
    }

    //Creating the Composition object
    Composition composition{};

    //Reading
    compositions.seekg(0, std::ios::beg);

    int counter = 0;

    while (compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition)))
    {
        if(composition.exists)
        {
            counter++;


            std::cout << "Composition ID : " << composition.ID << std::endl;
            std::cout << "Composition name : " << composition.name << std::endl;
            std::cout << "Year of creation : " << composition.year << std::endl;
            std::cout << "Genre : " << composition.genre << std::endl;

            std::cout << std::endl;
        }
    }

    std::cout << counter << " composition" << ((counter-1)?"s":"") << " in total." << std::endl << std::endl;

    compositions.close();
}

void UI::findCompositionByID() {
    std::fstream compositions("../data/compositions.dat", std::ios::in|std::ios::out|std::ios::binary);
    if(!compositions.is_open())
    {
        std::cout << std::endl << "Compositions data files cannot be opened." << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter the ID of composition :" << std::endl;
    input(ID);

    //Creating the Composition object
    Composition composition{};

    //Reading
    compositions.seekg(ID * sizeof(Composition), std::ios::beg);
    compositions.read(reinterpret_cast<char *>(&composition), sizeof(Composition));

    if(composition.exists)
    {
        std::cout << "Composition name : " << composition.name << std::endl;
        std::cout << "Year of creation : " << composition.year << std::endl;
        std::cout << "Genre : " << composition.genre << std::endl;
    }
    else
    {
        std::cout << "There's no such composition in the database." << std::endl;
    }

    std::cout << std::endl;

    compositions.close();
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
            case 3:
            {
                deleteBand();
                break;
            }
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
            case 6:
            {
                addComposition();
                break;
            }
            case 7:
            {
                updateComposition();
                break;
            }
            case 8:
            {
                deleteComposition();
                break;
            }
            case 9:
            {
                printCompositionsOfTheBand();
                break;
            }
            case 10:
            {
                printCompositions();
                break;
            }
            case 11:
            {
                findCompositionByID();
                break;
            }
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
            std::cout << "Incorrect input. Try again." << std::endl;
        }
        else
        {
            incorrectInput = false;
        }
    }
}
