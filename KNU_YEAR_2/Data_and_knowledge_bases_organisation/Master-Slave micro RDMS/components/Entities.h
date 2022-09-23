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
    char name [20];
    short year;
    int ID;
    long long address;
};

struct Composition {
    char name [20];
    short year;
    char genre [25];
    int ID;
    long long address;
    long long authorAddress;
};

#endif
