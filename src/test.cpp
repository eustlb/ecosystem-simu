#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include "IComportement.h"

#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "PersoMultiple.h"

#include <iostream>

using namespace std;

// constantes de la simulation 
#include "constantes.h"

int main()
{
   Gregaire *c_gregaire = new Gregaire();
   Peureuse *c_peureuse = new Peureuse();

   Bestiole b1 = Bestiole(c_gregaire);
   Bestiole b2 = Bestiole(c_peureuse);

   b1.initCoords(1024, 1280);
   b2.initCoords(1024, 1280);
   
   cout << b1.dist_ouie << endl; 
   if ( (b1.jeTeVois(b2)) || (b1.jeTendtends(b2)) ) 
   {
    cout <<  "oui" << endl; 
   }
   

}
