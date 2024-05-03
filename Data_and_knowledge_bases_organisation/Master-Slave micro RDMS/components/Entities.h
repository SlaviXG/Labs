//
// Created by SlaviX on 23.09.2022.
//

#ifndef MASTER_SLAVE_MICRO_RDMS_ENTITIES_H
#define MASTER_SLAVE_MICRO_RDMS_ENTITIES_H

/**
    Entities, which are involved into relations,
    and their attributes.
*/

struct Band {
    bool exists;
    char name [21];
    short year;
};

struct Composition {
    bool exists;
    int ID;
    char name [21];
    short year;
    char genre [26];
    long long nextCompAddress;
};

struct BandIDX
{
    bool exists;
    int ID;
    long long bandAddress; // address = numberOfRecord * sizeOfRecord
    long long compositionAddress;
    int numberOfCompositions;
};

#endif
