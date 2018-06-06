#ifndef JOUEUR_H
#define JOUEUR_H

#include "jeu.h"
#include "couleur.h"
#include <QString>

class Joueur {
public:
  Joueur(const QString& un_nom, const Couleur& une_couleur = rouge);
  virtual ~Joueur() {}
  virtual void jouer(Jeu*) const = 0;
  QString get_nom() const;
  Couleur get_couleur() const;

protected:
  QString nom;
  const Couleur couleur;
};

#endif // JOUEUR_H
