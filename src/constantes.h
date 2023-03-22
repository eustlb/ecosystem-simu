#include <cmath> // pour la constante pi (M_PI)

// constantes de la simulation 
const float TX_GREGAIRE = 0.;
const float TX_PEUREUSE = 0.8;
const float TX_KAMIKAZE = 0.2;
const float TX_PREVOYANTE = 0.;
const float TX_PERSOMULT = 0.;
const int TOT = 5; // nombre total de bestioles

// vue
const double ALPHA_MIN = M_PI/2;
const double ALPHA_MAX = M_PI/2 + .01;
const double DIST_VUE_MIN = 100.;
const double DIST_VUE_MAX = 101.;
const double CAPA_VUE_MIN = 0.1;
const double CAPA_VUE_MAX = 0.8;

// ouie
const double DIST_OUIE_MIN = 150.;
const double DIST_OUIE_MAX = 151.;
const double CAPA_OUIE_MIN = 0.1;
const double CAPA_OUIE_MAX = 0.8;

// seuil pour la bestiole peureuse
const int S_PEUREUSE = 1000;

// probabilité de mort lors d'une collision 
const double P = 0.5;



