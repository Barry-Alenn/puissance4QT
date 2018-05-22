#ifndef JEU_H
#define JEU_H
#include "mainwindow.h"
#include <vector>
#include "couleur.h"
#include <QWidget>

class Jeu : public MainWindow {
public:
  Jeu(unsigned int xGrille = 6, unsigned int yGrille = 5, QWidget *parent = 0);

  bool jouer(unsigned int x, Couleur);
  Couleur gagnant() const;
  bool fini(Couleur&) const;
  size_t get_taille() const { return grille.size(); }
  void affiche();
  QLabel* getPionImg(QPixmap &pion, int sizePionX, int sizePionY);
  QPushButton* getPionButton(int sizePionX, int sizePionY);

protected:
  unsigned int xGrille;
  unsigned int yGrille;
  std::vector< std::vector< Couleur > > grille;

private:
  unsigned int compte(Couleur, size_t, size_t, int, int) const;
};

#endif // JEU_H
