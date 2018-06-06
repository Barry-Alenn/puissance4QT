#ifndef HUMAIN_H
#define HUMAIN_H

#include "jeu.h"
#include "joueur.h"
#include "couleur.h"


class Humain : public Joueur  {
public:
  Humain(Couleur une_couleur = rouge);
  void jouer(Jeu*) const;
};

#endif // HUMAIN_H
