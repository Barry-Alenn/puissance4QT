#ifndef PARTIE_H
#define PARTIE_H
#include "mainwindow.h"
#include <array>
#include "joueur.h"
#include "couleur.h"
#include  <QPointer>
#include <memory>

class Partie : public MainWindow {
public:
  Partie(std::unique_ptr<const Joueur>&&, std::unique_ptr<const Joueur>&&, QWidget *parent = 0);
  void lancer();

protected:
  std::array<std::unique_ptr<const Joueur>, 2> joueurs;
  Jeu jeu;
};

#endif // PARTIE_H
