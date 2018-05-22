#include "mainwindow.h"
#include "humain.h"
#include "jeu.h"

void Humain::jouer(Jeu& jeu) const {
  size_t lu;
  bool valide;
  do {

    lu = 1; // on pourrait faire ici la validation de la lecture
    --lu; // remet entre 0 et taille-1 (indice à la C++)
    valide = jeu.jouer(lu, couleur);
    ++lu;
  } while(not valide);
}
