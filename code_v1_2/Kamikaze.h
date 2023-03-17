#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "IComportement.h"

class Kamikaze : public IComportement 
{
public:
    void bouge(Bestiole* bestiole);
};

#endif