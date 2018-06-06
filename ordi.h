#ifndef ORDI_H
#define ORDI_H

#include "jeu.h"
#include "joueur.h"
#include "couleur.h"


class Ordi : public Joueur  {
public:
  Ordi(Couleur couleur = jaune);
  void jouer(Jeu*) const;
};

#endif // ORDI_H
