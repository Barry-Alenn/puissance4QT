#ifndef PARTIE_H
#define PARTIE_H

#include <QWidget>
#include "joueur.h"
#include "couleur.h"
#include <memory>
#include <array>

class Partie {

public:
  Partie(std::unique_ptr<const Joueur>&&, std::unique_ptr<const Joueur>&&);
  QWidget* lancer();
  std::unique_ptr<Jeu> getJeu() const;
  ~Partie();

protected:
  std::array<std::unique_ptr<const Joueur>, 2> joueurs;
  std::unique_ptr<Jeu> jeu;
};

#endif // PARTIE_H
