#include "Prevoyante.h"

Prevoyante::Prevoyante()
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Prevoyante::bouge(Bestiole* bestiole)
{

}