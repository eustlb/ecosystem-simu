#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "IComportement.h"

class Gregaire : public IComportement 
{
public:
    Gregaire();
    void bouge(int xLim, int yLim, Bestiole* bestiole);  
};

#endif