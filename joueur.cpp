#include "mainwindow.h"
#include "joueur.h"
#include <QString>

Joueur::Joueur(const QString& un_nom, const Couleur& une_couleur = rouge, QWidget *parent )
    : nom(un_nom), couleur(une_couleur), MainWindow(parent) {}

QString Joueur::get_nom() const { return nom; }

Couleur Joueur::get_couleur() const { return couleur; }
