#ifndef HUMAIN_H
#define HUMAIN_H
#include "mainwindow.h"
#include "joueur.h"
#include "couleur.h"
#include "jeu.h"

class Humain : public Joueur  {
public:
  Humain(Couleur une_couleur = rouge)
      : Joueur("quidam", une_couleur) {

  }
  void jouer(Jeu*) const;
};

#endif // HUMAIN_H
