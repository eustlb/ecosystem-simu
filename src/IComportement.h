#ifndef _ICOMPORTEMENT_H_
#define _ICOMPORTEMENT_H_

#include "UImg.h"

class Bestiole;

class IComportement // classe abstraite
{
    public:
        T couleur[3]; // couleur du comportement qui sera partagée par les bestioles de ce comportement
    public:
    /* fonction virtuelle pure*/
        virtual void bouge(int xLim, int yLim, Bestiole* bestiole) = 0;

};

#endif