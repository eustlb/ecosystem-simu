#include "Kamikaze.h"

Kamikaze::Kamikaze()
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Kamikaze::bouge(int xLim, int yLim, Bestiole* bestiole)
{

}

