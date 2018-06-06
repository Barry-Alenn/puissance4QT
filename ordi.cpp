
#include "ordi.h"
//#include "jeu.h"

Ordi::Ordi(Couleur couleur)
    : Joueur("Le programme", couleur) {}

void Ordi::jouer(Jeu* jeu) const {
  for (size_t i(0); i < jeu->get_taille(); ++i) {
    if (jeu->jouer(i, couleur)) {
        return;
    }
  }
}
