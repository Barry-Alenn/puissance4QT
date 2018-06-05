#ifndef PARTIE_H
#define PARTIE_H
#include "mainwindow.h"
#include <array>
#include "joueur.h"
#include "couleur.h"
#include <memory>
#include "jeu.h"

class Partie {

public:
  Partie(std::unique_ptr<const Joueur>&&, std::unique_ptr<const Joueur>&&);
  QWidget* lancer();
  Jeu* getJeu() const {
      return jeu;
  }
  ~Partie();

protected:
  std::array<std::unique_ptr<const Joueur>, 2> joueurs;
  Jeu *jeu;
};

#endif // PARTIE_H
