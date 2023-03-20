#include "Peureuse.h"
#include "Bestiole.h"
#include "constantes.h"

Peureuse::Peureuse()
{
    couleur [0] = 121;
    couleur [1] = 28;
    couleur [2] = 248;

    // couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Peureuse::bouge(int xLim, int yLim, Bestiole* bestiole)
{
    // on récupère les voisins perçus par la bestiole 
    std::vector<Bestiole*> v = bestiole->getNeighbors();
    int taille = v.size();
    if ((taille >= S_PEUREUSE) && (taille != 0))
    {
        // determiner la direction moyenne des voisins (comme pour grégaire)
        double somme = 0.0;
        for (int i = 0; i < taille; i++) 
        {
        somme += v[i]->getOrientation();
        }
        double moyenne = somme / taille;
        // cout << moyenne << endl;
        // on change l'orientation de notre bestiole telle quelle soit opposée à cette direction moyenne 
        bestiole-> setOrientation(M_PI + moyenne);

    }
    // on appelle la méthode bouge classique de notre bestiole avec ces paramètre actualisés
    bestiole->bouge(xLim, yLim);
}