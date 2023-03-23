#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"

#include <iostream>
#include <vector>

#include "IComportement.h"

using namespace std;


class Milieu;


class Bestiole
{

public :
   static const double     AFF_SIZE;
private :
   static const double     MAX_VITESSE;
   static const int        MAX_VIE;


   static int              next;

public :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   std::vector<Bestiole*>   voisins; // vecteur de pointeurs vers les bestioles perçues à la step considérée

public: // attributs des capteurs
   // yeux 
   double dist_vue;
   double alpha; // angle de vue (cf. cahier des charges)
   double capa_vue;
   // oreilles
   double dist_ouie;
   double capa_ouie;

public: // attributs des accesoires
   // nageoires
   double coef_nageoires; // à mettre à 1 par défaut si pas de nageoires.
   double coef_carapace; // à mettre à 1 par défaut si pas de carapace.
   double coef_camouflage; // à mettre à 0 par défaut si pas de camouflave

public :
   int               vie; // -1 à chaque step, morte si 0 
   IComportement* comportement;

public :                                           // Forme canonique :
   Bestiole( IComportement* comp );                // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut

   void bouge( int xLim, int yLim );

   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   bool jeTendtends( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   void setNeighbors(std::vector<Bestiole*> v); // setteur des voisins

   std::vector<Bestiole*> getNeighbors();

   double getOrientation() {return orientation;} ;

   void setOrientation(double o);

   int getX() {return x;} ;
   int getY() {return y;} ;

   double getVitesse() {return vitesse;} ;

   double getCumulX() {return cumulX;} ; 

   double getCumulY() {return cumulY;} ;   

   void coupDeGrace();

   int getIdentite() {return identite;};

};


#endif
