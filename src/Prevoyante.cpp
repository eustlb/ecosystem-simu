#include "Prevoyante.h"
#include "Bestiole.h"

Prevoyante::Prevoyante()
{
    couleur [0] = 125;
    couleur [1] = 146;
    couleur [2] = 42;

    // couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Prevoyante::bouge(int xLim, int yLim, Bestiole* bestiole)
{
    // on appelle la méthode bouge classique de notre bestiole avec ces paramètre actualisés
    bestiole->bouge(xLim, yLim);
}