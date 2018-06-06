
#include "partie.h"
#include "joueur.h"
#include "couleur.h"
#include <utility>
#include <memory>
#include <array>

Partie::Partie(std::unique_ptr<const Joueur>&& j1, std::unique_ptr<const Joueur>&& j2)
    : jeu(new Jeu())
{
  joueurs[0] = std::move(j1);
  joueurs[1] = std::move(j2);
}

QWidget* Partie::lancer() {
  unsigned int tour(0);
  Couleur vainqueur;

  if(not jeu->fini(vainqueur)) {
      joueurs[tour]->jouer(jeu);
      tour = 1 - tour; // joueur suivant : 0 -> 1   1 -> 0
  }
  return jeu->affiche();
  /*
  if (vainqueur == joueurs[0]->get_couleur()) {
      wLabel->setText("La partie est finie. Le vainqueur est " + joueurs[0]->get_nom());
  } else if (vainqueur == joueurs[1]->get_couleur()) {
      wLabel->setText("La partie est finie. Le vainqueur est " + joueurs[1]->get_nom());
  } else {
      wLabel->setText("La partie est finie. Match nul.");
  }
  */
}

std::unique_ptr<Jeu> Partie::getJeu() const {
    return jeu;
}

Partie::~Partie()
{
    //delete jeu;
}
