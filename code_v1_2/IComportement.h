#ifndef _ICOMPORTEMENT_H_
#define _ICOMPORTEMENT_H_

#include "Bestiole.h"

class IComportement // classe abstraite
{
    // public:
    //     T[3] couleur; // couleur du comportement qui sera partagée par les bestioles de ce comportement
    public:
    /* fonction virtuelle pure*/
        virtual void bouge(Bestiole* bestiole) = 0;

};

#endif