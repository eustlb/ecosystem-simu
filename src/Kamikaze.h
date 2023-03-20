#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "IComportement.h"

class Kamikaze : public IComportement 
{
public:
    Kamikaze();
    void bouge(int xLim, int yLim, Bestiole* bestiole);
    std::tuple<int, int> estime(int xLim, int yLim, Bestiole* voisin); // pour estimer la position d'un prochain voisin
};

#endif