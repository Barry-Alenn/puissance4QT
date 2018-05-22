#ifndef PARTIE_H
#define PARTIE_H
#include "mainwindow.h"
#include <array>
#include "joueur.h"
#include "couleur.h"
#include  <QPointer>

class Partie : public MainWindow {
public:
  Partie(QPointer<const Joueur>&&, QPointer<const Joueur>&&, QWidget *parent = 0);
  void lancer();

protected:
  std::array<QPointer<const Joueur>, 2> joueurs;
  Jeu jeu;
};

#endif // PARTIE_H
