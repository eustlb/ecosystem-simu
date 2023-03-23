#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"

#include <iostream>
#include <vector>
#include <list>

#include "Bestiole.h"
#include "IComportement.h"

#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "PersoMultiple.h"

// constantes de la simulation 
#include "constantes.h"

using namespace std;

class Milieu : public UImg
{

private :
   static const T          white[];
   int                     width, height;
   
   std::vector<Bestiole>   listeBestioles;
   std::list<std::pair<int, int>> en_collision; // on crée une liste des paires avec des identitées de vecteurs car on ne veut évaluer qu'une seule fois la mort lorsque les deux cercles des bestioles se superposent (et pas à chaque step).
   Gregaire *c_gregaire;
   Peureuse *c_peureuse;
   Kamikaze *c_kamikaze;
   Prevoyante *c_prevoyante;
   IComportement *c_persoMult;
   
public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins( const Bestiole & b );

   void populate(float tx_gregaire, float tx_peureuse, float tx_kamikaze, float tx_prevoyante, float tx_persoMult, int tot);

   void actualiserVoisins(Bestiole & b); // actualiser la liste des bestioles perçues par b

   bool collision(Bestiole* b1, Bestiole* b2);

};


#endif
