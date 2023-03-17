#include "Milieu.h"

#include <cstdlib>
#include <ctime>

#include "IComportement.h"

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
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   }

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;
}

// void Milieu::populate(float tx_gregaire, float tx_peureuse, float tx_kamikaze, float tx_prevoyante, float tx_persoMult, int tot)
// {
//    IComportement *c_gregaire = new Gregaire();
//    IComportement *c_peureuse = new Peureuse();
//    IComportement *c_kamikaze = new Kamikaze();
//    IComportement *c_prevoyante = new Prevoyante();
//    IComportement *c_persoMult = new PersoMult(c_gregaire, c_peureuse, c_kamikaze, c_prevoyante);





//    for (int i = 0; i < tx_gregaire*tot; i++ ){
//       this->addMember(Bestiole(IComportement))
//    }

// }

