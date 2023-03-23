#include "Kamikaze.h"
#include "Bestiole.h"

#include <tgmath.h> // pour fonction atan2
#include <tuple>
Kamikaze::Kamikaze()
{
    couleur [0] = 217;
    couleur [1] = 81;
    couleur [2] = 23;

    // couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Kamikaze::bouge(int xLim, int yLim, Bestiole* bestiole)
{
    // choix d'implementation : la kamikaze choisi parmis les bestioles qu'elle perçoit celle qui est la plus proche et cherche la collision
    // afin de cherche la collision, elle estime sa position au prochain step et s'oriente vers cette position avant de bouger.

    // on récupère les voisins de la bestiole
    std::vector<Bestiole*> v = bestiole->getNeighbors();

    // lambda fonction pour avoir la distance entre deux bestioles
    auto distance = [] (Bestiole* bestiole, Bestiole* voisin) -> double {
        int x = voisin->getX();
        int y = voisin->getY();
        double dist = std::sqrt((x-bestiole->getX())*(x-bestiole->getX()) + (y-bestiole->getY())*(y-bestiole->getY()));
        return dist;
        };


    int taille = v.size();
    if (taille != 0)
    {
        Bestiole* plus_proche = v[0];
        double dist_small = distance(bestiole, plus_proche);
        
        for (int i = 0; i < taille; i++) 
        {
            double dist = distance(bestiole, v[i]);
            if (dist < dist_small) 
            {
                plus_proche = v[i];
                dist_small = dist;
            }
        }

        // on estime sa position au prochain step 
        std::tuple<int, int> proch_pos = estime(xLim, yLim, plus_proche);
        int next_x = std::get<0>(proch_pos);
        int next_y = std::get<1>(proch_pos);

        // on determine l'orientation à adopter pour pointer vers cette position
        int x = bestiole->getX();
        int y = bestiole->getY();
        double orientation = atan2(y-next_x, next_y-x); // attention, l'axe y est vers le bas, d'où un tel choix
    
        // on change l'orientation de notre bestiole
        bestiole->setOrientation(orientation);
    }

    // on appelle la méthode bouge classique de notre bestiole avec ces paramètre actualisés
    bestiole->bouge(xLim, yLim);

}

std::tuple<int, int> Kamikaze::estime(int xLim, int yLim, Bestiole* voisin)
{
    int x = voisin->getX();
    int y = voisin->getY();
    double orientation = voisin->getOrientation();
    double vitesse = voisin->getVitesse();
    double cumulX = voisin->getCumulX();
    double cumulY = voisin->getCumulY();

    ////////
    // on récupère le code de la methode bouge de Bestiole
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
    ////////

    return std::tuple<int, int>{x, y};
}

