#ifndef JEU_H
#define JEU_H

#include <vector>
#include "couleur.h"
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QButtonGroup>

class Jeu {

public:
  Jeu(unsigned int xGrille = 7, unsigned int yGrille = 6, int colJoue_ = 1);

  bool jouer(unsigned int x, Couleur);
  Couleur gagnant() const;
  bool fini(Couleur&) const;
  unsigned int get_taille() const { return grille.size(); }
  QWidget* affiche();
  QLabel* getPionImg(QPixmap *pion);
  QPushButton* getPionButton(int sizePionX, int sizePionY);
  int getColJoue() const {
      return colJoue;
  }
  void setColJoue(int colJoue_) {
      colJoue = colJoue_;
  }

  QButtonGroup* getBgroup() {
      return bgroup;
  }

  void addPion();

protected:
  unsigned int xGrille;
  unsigned int yGrille;
  int colJoue;
  std::vector< std::vector< Couleur > > grille;

  QWidget *zoneCentrale;

  const int sizePionX;
  const int sizePionY;

  QPixmap *pionRed;
  QPixmap *pionYellow;
  QPixmap *pionEmpty;

  QWidget *wPion;
  QGridLayout *layoutPion;

  QWidget *wGrille;
  QPixmap *pixmapGrille;
  QLabel *labelGrille;

  QWidget *wButton;
  QGridLayout *layoutButton;
  QButtonGroup *bgroup;
  QPushButton *pionButton;

private:
  unsigned int compte(Couleur, unsigned int, unsigned int, int, int) const;
};


#endif // JEU_H
