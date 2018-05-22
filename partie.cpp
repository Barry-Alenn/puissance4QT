#include "mainwindow.h"
#include <array>
#include "joueur.h"
#include "couleur.h"
#include "partie.h"
#include <utility>
#include  <QPointer>

Partie::Partie(QPointer<const Joueur>&& j1, QPointer<const Joueur>&& j2, QWidget *parent)
    : MainWindow(parent){
  joueurs[0] = std::move(j1);
  joueurs[1] = std::move(j2);
}

void Partie::lancer() {
  unsigned int tour(0);
  Couleur vainqueur;
  do {
    joueurs[tour]->jouer(jeu);
    tour = 1 - tour; // joueur suivant : 0 ->  1   1 -> 0
  } while(not jeu.fini(vainqueur));

  if (vainqueur == joueurs[0]->get_couleur()) {
      wLabel->setText("La partie est finie. Le vainqueur est " + joueurs[0]->get_nom());
  } else if (vainqueur == joueurs[1]->get_couleur()) {
      wLabel->setText("La partie est finie. Le vainqueur est " + joueurs[1]->get_nom());
  } else {
      wLabel->setText("La partie est finie. Match nul.");
  }
}
