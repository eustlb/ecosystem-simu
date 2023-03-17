#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "IComportement.h"

class Peureuse : public IComportement 
{
public:
    Peureuse();
    void bouge(Bestiole* bestiole);
};

#endif