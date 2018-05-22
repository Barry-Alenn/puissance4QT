#ifndef ORDI_H
#define ORDI_H
#include "mainwindow.h"
#include "joueur.h"
#include "couleur.h"
#include "jeu.h"

class Ordi : public Joueur  {
public:
  Ordi(Couleur couleur = jaune) : Joueur("Le programme", couleur) {}
  void jouer(Jeu&) const;
};

#endif // ORDI_H
