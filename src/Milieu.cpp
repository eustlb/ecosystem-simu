#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <utility> // pour std::pair
#include <random> // pour expérience de Bernoulli

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

// pointeurs vers comportements partagées par les bestioles



Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{
   c_gregaire = new Gregaire();
   c_peureuse = new Peureuse();
   c_kamikaze = new Kamikaze();
   c_prevoyante = new Prevoyante();
   c_persoMult = new PersoMultiple(c_gregaire, c_peureuse, c_kamikaze, c_prevoyante);
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

   // ON ÉVALUE TOUTES LES BESTIOLES ENTRÉES EN COLLISION ET LES MORTS ÉVENTUELLES

      // choix d'implementation : les bestioles ont un rayon de AFF_SIZE/5., collision si plus proches que 2x ce rayon
      // on crée une liste des paires avec des identitées de vecteurs car on ne veut évaluer qu'une seule fois la mort lorsque les 
      // deux cercles des bestioles se superposent (et pas à chaque step).

   for ( std::vector<Bestiole>::iterator it1 = listeBestioles.begin() ; it1 != listeBestioles.end() ; ++it1 )
   {
      for ( std::vector<Bestiole>::iterator it2 = listeBestioles.begin() ; it2 != listeBestioles.end() ; ++it2 )
      {
         if ((!(*it1 == *it2)) && collision(&(*it1), &(*it2)))
         {
            it1->coupDeGrace();
            it2->coupDeGrace();
            cout << "collision" << endl;
         }   
      }
   }

      // on enlève du vecteur de Bestioles les bestioles qui sont mortes
   auto predicate = [](const Bestiole &b) { return b.vie < 1; };
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), predicate), listeBestioles.end());

      // on actualiste la liste des voisins, c'est-à-dire des bestioles perçues par chaque bestioles
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      actualiserVoisins(*it);
      // if ((it->getNeighbors().size() != 0) && dynamic_cast<Gregaire*>(it->comportement) != nullptr)
      // {
      //    cout << it->getNeighbors().size() << endl;
      // } 
   }

   // ON FAIT BOUGER TOUTES LES BESTIOLES 
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      it->action( *this );
      it->draw( *this );
   }

   // // NAISSANCE SPONTANNÉE
   //    // naissance par épreuve de Bernoulli de proba de succès dans les constantes

      // lambda fonction pour l'épreuve de Bernoulli
   auto random_check = [](double P) {
      std::random_device rd;
      double random_num = rd() / static_cast<double>(rd.max());
      return random_num < P;
      };

   if (random_check(P_GREGAIRE))
   {
      this->addMember(Bestiole(c_gregaire));
      cout << "naissance spontannée d'une grégaire" << endl;
      
   }
   if (random_check(P_PEUREUSE))
   {
      this->addMember(Bestiole(c_peureuse));
      cout << "naissance spontannée d'une peureuse" << endl;
   }
   if (random_check(P_KAMIKAZE))
   {
      this->addMember(Bestiole(c_kamikaze));
      cout << "naissance spontannée d'une kamikaze" << endl;
   }
   if (random_check(P_PREVOYANTE))
   {
      this->addMember(Bestiole(c_prevoyante));
      cout << "naissance spontannée d'une peureuse" << endl;
   }
   if (random_check(P_PERSOMULT))
   {
      this->addMember(Bestiole(c_persoMult));
      cout << "naissance spontannée d'une perso. multiple" << endl;
   } 

   // // CLONAGE - NE MARCHE PAS, ERREUR DE SEGMENTATION
   // for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   // {
   //    if (random_check(P_CLONAGE))
   //    {
   //       Bestiole& ref_bestiole = *it;
   //       this->addMember(Bestiole(ref_bestiole));
   //       cout << "naissance par clonage d'une bestiole" << endl;
   //    }
   // }
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

bool Milieu::collision(Bestiole* b1, Bestiole* b2)
{
   int x1 = b1->getX();
   int y1 = b1->getY();

   int x2 = b2->getX();
   int y2 = b2->getY();

   std::pair<int,int> paire(b1->getIdentite(), b2->getIdentite());

   bool is_in = std::find(en_collision.begin(), en_collision.end(), paire) != en_collision.end();

   // choix d'implementation : les bestioles ont un rayon de AFF_SIZE/5., collision si plus proches que 2x ce rayon
   double dist = std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

   double dist_coll = 10; // 2*Bestiole::AFF_SIZE/5;

   if ((dist <= dist_coll) && (!is_in)) // si première rencontre, on ajoute à la liste des en collision
   {
      en_collision.push_back(paire);
      return true;
   }
   if ((!(dist <= dist_coll)) && is_in) // dans les collision mais plus en collision, on retire
   {
      en_collision.remove(paire);
      return false;
   }
   return false;
}