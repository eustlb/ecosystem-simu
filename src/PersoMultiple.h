#ifndef _PERSOMULTIPLE_H_
#define _PERSOMULTIPLE_H_

#include "IComportement.h"

#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"

class PersoMultiple : public IComportement 
{
private:
    IComportement* comportements[4]; // tableau de pointeurs vers les 4 comportements possibles sur le tas
    IComportement* actualComp; // comportement "actuel", c'est-à-dire celui à utiliser au step considéré 
public:
    PersoMultiple(Gregaire* c_gregaire, Peureuse* c_peureuse, Kamikaze* c_kamikaze, Prevoyante* c_prevoyante);
    void bouge(int xLim, int yLim, Bestiole* bestiole);
    void changeComp(); // change de façon aléatoire le comportement actualComp par une des 4 comportements (pointeurs)
};

#endif