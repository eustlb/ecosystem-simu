#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include "IComportement.h"

class Prevoyante : public IComportement 
{
public:
    Prevoyante();
    void bouge(int xLim, int yLim, Bestiole* bestiole);
};

#endif