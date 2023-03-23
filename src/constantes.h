#ifndef CONSTANTES_H
#define CONSTANTES_H

// Définition des constantes

#include <cmath> // pour la constante pi (M_PI)

// CONSTANTES DE CONSTRUCTION DE LA POPULATION
    // taux initiaux 
const float TX_GREGAIRE = .1;
const float TX_PEUREUSE = 0.1;
const float TX_KAMIKAZE = 0.1;
const float TX_PREVOYANTE = 0.1;
const float TX_PERSOMULT = 0.1;

    // nombre total de bestioles
const int TOT = 10; 

    // probabilités de naissance, par défault égales aux proportions
const double P_GREGAIRE = TX_GREGAIRE;
const double P_PEUREUSE = TX_PEUREUSE;
const double P_KAMIKAZE = TX_KAMIKAZE;
const double P_PREVOYANTE = TX_PREVOYANTE;
const double P_PERSOMULT = TX_PERSOMULT;

    // probabilité de clonage
const double P_CLONAGE = 0.1;


// CAPTEURS ET ACCESSOIRES
    // vue
const double P_VUE = 0.8; // proba d'affectation
const double ALPHA_MIN = M_PI/6;
const double ALPHA_MAX = M_PI/2;
const double DIST_VUE_MIN = 10.;
const double DIST_VUE_MAX = 50.;
const double CAPA_VUE_MIN = 0.1;
const double CAPA_VUE_MAX = 0.8;

    // ouie
const double P_OUIE = 0.8; // proba d'affectation
const double DIST_OUIE_MIN = 20.;
const double DIST_OUIE_MAX = 70.;
const double CAPA_OUIE_MIN = 0.1;
const double CAPA_OUIE_MAX = 0.8;

    // accessoires
        // nageoires
const double P_NAGEOIRES = 0.5; // proba d'affectation
const double C_NAGEOIRES_MAX = 1.5;
        // carapace
const double P_CARAPACE = 0.5; // proba d'affectation
const double C_CARAPACE_MAX = 1.5;
        // camouflage
const double P_CAMOUFLAGE = 0.5; // proba d'affectation
const double C_CAMOUFLAGE_MIN = 0.2;
const double C_CAMOUFLAGE_MAX = 0.8;

// COMPORTEMENTS
    // seuil pour la bestiole peureuse
const int S_PEUREUSE = 1000;

// COLLISION
    // probabilité de mort lors d'une collision 
const double P = 0.5;

#endif // CONSTANTES_H










