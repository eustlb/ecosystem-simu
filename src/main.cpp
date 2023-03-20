#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;

// constantes de la simulation 
#include "constantes.h"

int main()
{
   Aquarium       ecosysteme( 640, 480, 60 );

   ecosysteme.getMilieu().populate(TX_GREGAIRE, TX_PEUREUSE, TX_KAMIKAZE, TX_PREVOYANTE, TX_PERSOMULT, TOT);
   ecosysteme.run();

   return 0;

}
