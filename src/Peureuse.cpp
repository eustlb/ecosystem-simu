#include "Peureuse.h"
#include "Bestiole.h"

Peureuse::Peureuse()
{
    couleur [0] = 121;
    couleur [1] = 28;
    couleur [2] = 248;

    // couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Peureuse::bouge(int xLim, int yLim, Bestiole* bestiole)
{
    // on appelle la méthode bouge classique de notre bestiole avec ces paramètre actualisés
    bestiole->bouge(xLim, yLim);
}