#include "Gregaire.h"
#include <numeric> // pour std::accumulate
#include <vector>
#include "Bestiole.h"

Gregaire::Gregaire()
{
    couleur [0] = 49;
    couleur [1] = 140;
    couleur [2] = 230;

    // couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    // couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
}

void Gregaire::bouge(int xLim, int yLim , Bestiole* bestiole)
{  
    // determiner la direction moyenne des voisins
    std::vector<Bestiole*> v = bestiole->getNeighbors();
    int taille = v.size();
    if (taille != 0)
    {
        double somme = 0.0;
        for (int i = 0; i < taille; i++) 
        {
        somme += v[i]->getOrientation();
        }
        double moyenne = somme / taille;
        // cout << moyenne << endl;
        // on change l'orientation de notre bestiole
        bestiole->setOrientation(moyenne);
    }

    // on appelle la méthode bouge classique de notre bestiole avec ces paramètre actualisés
    bestiole->bouge(xLim, yLim);
}