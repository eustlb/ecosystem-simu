#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"

#include <iostream>
#include <vector>

#include "Bestiole.h"

using namespace std;

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins( const Bestiole & b );

   void populate(float tx_gregaire, float tx_peureuse, float tx_kamikaze, float tx_prevoyante, float tx_persoMult, int tot);

};


#endif
