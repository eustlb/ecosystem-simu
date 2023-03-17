#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include "IComportement.h"

class Prevoyante : public IComportement 
{
public:
    void bouge(Bestiole* bestiole);
};

#endif