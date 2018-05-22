#include "mainwindow.h"
#include "jeu.h"
#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>
#include <QLabel>

Jeu::Jeu(unsigned int xGrille , unsigned int yGrille, QWidget *parent)
  : xGrille(xGrille), yGrille(yGrille), MainWindow(parent), grille(xGrille, std::vector<Couleur>(yGrille, vide) )
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
unsigned int Jeu::compte(Couleur couleur, size_t i, size_t j, int di, int dj) const
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

void Jeu::affiche() {

  QWidget *zoneCentrale = new QWidget;

  QWidget *wPion = new QWidget(zoneCentrale);
  const int sizePionX = 50;
  const int sizePionY = 50;
  QPixmap pionRed(":/pions/images/red.png");
  QPixmap pionYellow(":/pions/images/yellow.png");

  //PionImg *pion1 = new PionImg(pion, sizePion);

  QGridLayout *layoutPion = new QGridLayout;

  layoutPion->setSpacing(2);
  layoutPion->setContentsMargins(18, 43, 0, 0);

  if (get_taille() > 0) {
    size_t j(get_taille()-1);
    do {
      for (unsigned int i(0); i < get_taille(); ++i) {
        switch (grille[i][j]) {
        case vide  : break;
        case rouge :
            layoutPion->addWidget(getPionImg(pionYellow, sizePionX, sizePionY), j, i);
            break;
        case jaune :
            layoutPion->addWidget(getPionImg(pionRed, sizePionX, sizePionY), j, i);
            break;
        }
      }
    } while (j-- != 0);
  }

  wPion->setLayout(layoutPion);
/*------------------------------------------------*/
  QWidget *wGrille = new QWidget(zoneCentrale);

  QLabel *labelGrille  = new QLabel(wGrille);
  labelGrille->setGeometry(0, 0, 400, 400);
  QPixmap pixmapGrille(":/grille/images/grille.png");
  QSize labelSizeGrille = labelGrille->size();
    pixmapGrille = pixmapGrille.scaled(labelSizeGrille, Qt::KeepAspectRatio, Qt::FastTransformation);
    labelGrille->setPixmap(pixmapGrille);

/*------------------------------------------------*/
  QWidget *wButton = new QWidget(zoneCentrale);

  //PionButton *button1 = new PionButton();

  QGridLayout *layoutButton = new QGridLayout;
  layoutButton->setSpacing(2);
  layoutButton->setContentsMargins(18, 43, 0, 0);

  for(unsigned int i{0}; i <= xGrille; ++i) {
      for(unsigned int j{0}; j <= yGrille; ++j) {
          layoutPion->addWidget(getPionButton(sizePionX, sizePionY), j, i);
      }
  }

  wButton->setLayout(layoutButton);

  setCentralWidget(zoneCentrale);
}

QLabel* Jeu::getPionImg(QPixmap &pion, int sizePionX, int sizePionY) {
    QLabel *labelPion = new QLabel();
    labelPion->setGeometry(0, 0, sizePionX, sizePionY);
    QSize labelSize = labelPion->size();
         pion = pion.scaled(labelSize, Qt::KeepAspectRatio, Qt::FastTransformation);
         labelPion->setPixmap(pion);
    return labelPion;
}

QPushButton* Jeu::getPionButton(int sizePionX, int sizePionY) {
    QPushButton *button = new QPushButton();
    button->setMinimumSize(sizePionX, sizePionY);
    button->setFlat(true);
    button->setUpdatesEnabled(false);
    return button;
}
