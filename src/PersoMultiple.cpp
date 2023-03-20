#include "PersoMultiple.h"

PersoMultiple::PersoMultiple(Gregaire* c_gregaire, Peureuse* c_peureuse, Kamikaze* c_kamikaze, Prevoyante* c_prevoyante)
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

    comportements[0] = c_gregaire;
    comportements[1] = c_peureuse;
    comportements[2] = c_kamikaze;
    comportements[3] = c_prevoyante;

    int i = rand() % 4; // generer un indice entier dans [0,3]
    actualComp = comportements[i];
}

void PersoMultiple::bouge(int xLim, int yLim, Bestiole* bestiole)
{

}

void PersoMultiple::changeComp()
{
    int i = rand() % 4; // generer un indice entier dans [0,3]
    actualComp = comportements[i];
}