#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <vector>

#include "IComportement.h"

#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "PersoMultiple.h"

// constantes de la simulation 
#include "constantes.h"

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   // // on enlève du vecteur de Bestioles les bestioles qui sont mortes
   // auto predicate = [](const Bestiole &b) { return b.vie < 1; };
   // listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), predicate), listeBestioles.end());

   // on actualiste la liste des voisins, c'est-à-dire des bestioles perçues par chaque bestioles
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      actualiserVoisins(*it);
      if ((it->getNeighbors().size() != 0) && dynamic_cast<Gregaire*>(it->comportement) != nullptr)
      {
         cout << it->getNeighbors().size() << endl;
      } 
      // cout << it->x <<" "<< it->y << endl;
      // cout << it-> orientation << endl;
   }

   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      it->action( *this );
      it->draw( *this );
   }

   // // naissance spontannée de bestioles
   
}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;
}

void Milieu::populate(float tx_gregaire, float tx_peureuse, float tx_kamikaze, float tx_prevoyante, float tx_persoMult, int tot)
{
   Gregaire *c_gregaire = new Gregaire();
   Peureuse *c_peureuse = new Peureuse();
   Kamikaze *c_kamikaze = new Kamikaze();
   Prevoyante *c_prevoyante = new Prevoyante();
   IComportement *c_persoMult = new PersoMultiple(c_gregaire, c_peureuse, c_kamikaze, c_prevoyante);

   int nb = 0;
   for (int i = 0; i < tx_gregaire*tot; i++ ){
      this->addMember(Bestiole(c_gregaire));
      nb++;
   };
   std::cout << nb << " bestioles gregaires" << std::endl;
   nb = 0;
   for (int i = 0; i < tx_peureuse*tot; i++ ){
      this->addMember(Bestiole(c_peureuse));
      nb++;
   };
   std::cout << nb << " bestioles peureuses" << std::endl;
   nb = 0;
   for (int i = 0; i < tx_kamikaze*tot; i++ ){
      this->addMember(Bestiole(c_kamikaze));
      nb++;
   };
   std::cout << nb << " bestioles kamikazes" << std::endl;
   nb = 0;
   for (int i = 0; i < tx_prevoyante*tot; i++ ){
      this->addMember(Bestiole(c_prevoyante));
      nb++;
   };
   std::cout << nb << " bestioles prevoyantes" << std::endl;
   nb = 0;
   for (int i = 0; i < tx_persoMult*tot; i++ ){
      this->addMember(Bestiole(c_persoMult));
      nb++;
   };
   std::cout << nb << " bestioles à perso. multiple" << std::endl;
}

void Milieu::actualiserVoisins(Bestiole & b) // actualiser la liste des bestioles perçues par b
{
   std::vector<Bestiole*> nvoisins;

   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if (!(*it == b))
      {
         if ((b.jeTeVois(*it)) || (b.jeTendtends(*it))) 
         {
            nvoisins.push_back(&(*it));
         }
      }
   }
   b.setNeighbors(nvoisins);
}


