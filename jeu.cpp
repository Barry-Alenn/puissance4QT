
#include "jeu.h"
#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>
#include <QLabel>
#include <QButtonGroup>

Jeu::Jeu(unsigned int xGrille , unsigned int yGrille, int colJoue_)
  : xGrille(xGrille), yGrille(yGrille),
    colJoue(colJoue_),
    grille(xGrille, std::vector<Couleur>(yGrille, vide)),
    zoneCentrale(new QWidget()),
    sizePionX(50),
    sizePionY(50),
    pionRed(new QPixmap(":/pions/images/red.png")),
    pionYellow(new QPixmap(":/pions/images/yellow.png")),
    pionEmpty(new QPixmap(":/pions/images/empty.png")),
    wPion(new QWidget(zoneCentrale)),
    layoutPion(new QGridLayout(wPion)),
    wGrille(new QWidget(zoneCentrale)),
    pixmapGrille(new QPixmap(":/grille/images/grille.png")),
    labelGrille(new QLabel(wGrille)),
    wButton(new QWidget(zoneCentrale)),
    layoutButton(new QGridLayout(wButton)),
    bgroup(new QButtonGroup(wButton)),
    pionButton(new QPushButton())

{}

// ------------------------------------------------------------
bool Jeu::jouer(unsigned int i, Couleur c) {
  if (c == vide) return false;
  if (i >= get_taille()) return false;
  size_t j(0);
  while ((j < get_taille()) and (grille[i][j] != vide)) ++j;
  if (j >= get_taille()) return false;
  grille[i][j] = c;
  return true;
}

// ------------------------------------------------------------
Couleur Jeu::gagnant() const {
  Couleur vainqueur(vide);
  for (size_t i(0); i < get_taille(); ++i) {
    for (size_t j(0); j < get_taille(); ++j) {
      if (grille[i][j] != vide) {
        vainqueur = grille[i][j];
        // teste dans les 5 directions possibles (+ (0,0) qui ne fait
        // rien)
        for (int di(0); di <= 1; ++di)
          for (int dj(-1); dj <= 1; ++dj)
            if (compte(vainqueur, i, j, di, dj) >= 4) return vainqueur;
      }
    }
  }
  return vide;
}

// ------------------------------------------------------------
unsigned int Jeu::compte(Couleur couleur, unsigned int i, unsigned int j, int di, int dj) const
{
  unsigned int n(1);
  if ((di != 0) or (dj != 0)) {
    for (i += di, j += dj;
        (i < get_taille()) and (j < get_taille()) and (grille[i][j] == couleur);
        i += di, j += dj)
      ++n;
  }
  return n;
}

// ------------------------------------------------------------
bool Jeu::fini(Couleur& resultat) const {
  resultat = gagnant();
  if (resultat == vide) {
    // est-ce plein ?
    for (auto ligne : grille) {
      for (auto kase : ligne) { // "case" est un mot réservé du C++ ;-)
        if (kase == vide)
          return false;
      }
    }
  }
  return true;
}
// ------------------------------------------------------------

QWidget* Jeu::affiche() {

  layoutPion->setSpacing(2);
  layoutPion->setContentsMargins(18, 43, 0, 0);

  if (get_taille() > 0) {
    unsigned int j(yGrille - 1);
    do {
      for (unsigned int i(0); i < get_taille(); ++i) {
        switch (grille[i][j]) {
        case vide  :
            layoutPion->addWidget(getPionImg(pionEmpty), (yGrille - j), i);
            break;
        case rouge :
            layoutPion->addWidget(getPionImg(pionRed), (yGrille - j), i);
            break;
        case jaune :
            layoutPion->addWidget(getPionImg(pionYellow), (yGrille - j), i);
            break;
        }
      }
    } while (j-- != 0);
  }

  wPion->setLayout(layoutPion);
/*-------------------------------------------------------------------*/

  labelGrille->setGeometry(0, 0, 400, 400);
  QSize labelSizeGrille = labelGrille->size();
    *pixmapGrille = pixmapGrille->scaled(labelSizeGrille, Qt::KeepAspectRatio, Qt::FastTransformation);
    labelGrille->setPixmap(*pixmapGrille);

/*-------------------------------------------------------------------*/

    layoutButton->setSpacing(2);
    layoutButton->setContentsMargins(18, 43, 0, 0);

    for (int i = 0; i < 7; i++)
    {
        pionButton = getPionButton(sizePionX, 310);
        bgroup->addButton(pionButton, i);
        layoutButton->addWidget(pionButton, 0, i);
    }

    wButton->setLayout(layoutButton);

    return zoneCentrale;
}

QLabel* Jeu::getPionImg(QPixmap *pion) {
    QLabel *labelPion = new QLabel(wPion);
    labelPion->setGeometry(0, 0, sizePionX, sizePionY);
    QSize labelSize = labelPion->size();
         *pion = pion->scaled(labelSize, Qt::KeepAspectRatio, Qt::FastTransformation);
         labelPion->setPixmap(*pion);
    return labelPion;
}

QPushButton* Jeu::getPionButton(int sizePionX, int sizePionY) {
    QPushButton *button = new QPushButton();
    button->setMinimumSize(sizePionX, sizePionY);
    button->setFlat(true);
    button->setUpdatesEnabled(false);
    return button;
}

void Jeu::addPion() {

    layoutPion->removeWidget(layoutPion->itemAtPosition(5, 1)->widget());
    delete layoutPion->itemAtPosition(5, 1)->widget();
    layoutPion->addWidget(getPionImg(pionRed), 5, 1);
}

