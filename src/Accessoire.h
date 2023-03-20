#ifndef _ACCESSOIRE_
#define _ACCESSOIRE_

#include "Bestiole.h"

class Accessoire : public Bestiole
{
protected:
    Bestiole *bestiole;
public:
    Accessoire(Bestiole *base_bestiole);
    void add_equipment();
};

#endif