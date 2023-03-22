#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <tgmath.h> // pour fonction atan2
#include <random> // pour expérience de Bernoulli


#include "constantes.h"
#include "Gregaire.h"


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const int         Bestiole::MAX_VIE = 1000;


int               Bestiole::next = 0;


Bestiole::Bestiole( IComportement* comp )
{

   identite = ++next;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   // parametres des capteurs, initialisation aléatoire
   // vue
   dist_vue = DIST_VUE_MIN + (DIST_VUE_MAX - DIST_VUE_MIN)*rand() / RAND_MAX;
   alpha =  ALPHA_MIN + (ALPHA_MAX - ALPHA_MIN)*rand() / RAND_MAX;
   // ouie
   dist_ouie =  DIST_OUIE_MIN + (DIST_OUIE_MAX - DIST_OUIE_MIN)*rand() / RAND_MAX;

   vie = rand() % MAX_VIE; 
   comportement = comp;

   // Accessoires
   // carapace
   coef_carapace = 1; // à 1 par défaut, équivalent à pas de carapace

   // cout << "const Bestiole (" << identite << ") par defaut et vie :" << vie << endl;

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   comportement = b.comportement;

   dist_vue = b.dist_vue;
   dist_ouie = b.dist_ouie;
   alpha = b.alpha;

   vie = b.vie;

   coef_carapace = b.coef_carapace;

}


Bestiole::~Bestiole( void )
{

   
   // cout << "dest Bestiole ("<< this->identite << ")" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse; 
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

   // réduire la vie de 1

   vie -= 1;

}


void Bestiole::action( Milieu & monMilieu )
{
   this->comportement->bouge(monMilieu.getWidth(), monMilieu.getHeight(), this);
}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., this->comportement->couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., this->comportement->couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTendtends( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= dist_ouie );

}

bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;
   double angle; // angle par rapport à l'horizontale de b

   angle = atan2(y-b.y, b.x-x); // attention, l'axe y est vers le bas, d'où un tel choix
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );

   // on s'assure d'avoir un angle dans [-pi,pi] car atan2 renvoie un angle dans [-pi,pi]
   auto proj_angle = [] (double orientation) -> double {return (orientation - 2*M_PI * floor(orientation / (2*M_PI))) - M_PI;};
   double orientation_norm = proj_angle(orientation); 
   // seuils du cone de vue
   double s_low = proj_angle(orientation_norm - alpha/2); 
   double s_high = proj_angle(orientation_norm + alpha/2);

   // if ((angle >= s_low) && (angle <= s_high) && (dist <= dist_vue) && dynamic_cast<Gregaire*>(b.comportement) != nullptr)
   // {
   //    cout << "je te vois" << endl;
   //    cout << angle*180/M_PI << endl;
   // }

   return ((angle >= s_low) && (angle <= s_high) && (dist <= dist_vue));
}

void Bestiole::setNeighbors(std::vector<Bestiole*> v){
   voisins = v;
}

std::vector<Bestiole*>  Bestiole::getNeighbors()
{
   return voisins;
}

void Bestiole :: setOrientation(double o) 
{
   orientation = o;
}

void Bestiole::coupDeGrace()
{
   // Créer un générateur de nombres aléatoireq
   std::random_device rd;
   // Générer un nombre aléatoire entre 0 et 1
   double random_num = rd() / static_cast<double>(rd.max());

   // Expérience de bernouilli de succès P/coef_carapace
   if (random_num < (P/coef_carapace)) 
   { // cas de mort

      cout << "mort :" << random_num << endl;
      vie = 0; // on set la vie à 0 pour que la bestiole soit considérée comme morte au prochain step
   } 
}