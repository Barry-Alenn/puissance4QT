
#include "humain.h"
#include "jeu.h"

Humain::Humain(Couleur une_couleur)
    : Joueur("quidam", une_couleur)
{}

void Humain::jouer(Jeu* jeu) const {

  //unsigned int lu;
  bool valide;

  do {

    //lu = 2; // on pourrait faire ici la validation de la lecture
    //--lu; // remet entre 0 et taille-1 (indice à la C++)

    valide = jeu->jouer(jeu->getColJoue(), couleur);
  } while(not valide);

}
