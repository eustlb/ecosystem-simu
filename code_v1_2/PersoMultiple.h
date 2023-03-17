#ifndef _PERSOMULTIPLE_H_
#define _PERSOMULTIPLE_H_

#include "IComportement.h"

class PersoMultiple : public IComportement 
{
private:
    IComportement* comportements[4]; // tableau de pointeurs vers les 4 comportements possibles sur le tas
    IComportement* actualComp; // comportement "actuel", c'est-à-dire celui à utiliser au step considéré 
public:
    void bouge(Bestiole* bestiole);
    void selectComp(); // change de façon aléatoire le comportement actualComp par une des 4 comportements (pointeurs)
};

#endif