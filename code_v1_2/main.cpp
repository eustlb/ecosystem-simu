#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{
   // creation des differents comportements sur la pile 

   float tx_gregaire = 0.2;
   float tx_peureuse = 0.2;
   float tx_kamikaze = 0.2;
   float tx_prevoyante = 0.2;
   float tx_persoMult = 0.2;
   int tot = 10; // nombre total de bestioles

   Aquarium       ecosysteme( 640, 480, 30 );

   ecosysteme.getMilieu().populate(tx_gregaire, tx_peureuse, tx_kamikaze, tx_prevoyante, tx_persoMult, tot);
   ecosysteme.run();

   return 0;

}
