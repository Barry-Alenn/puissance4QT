
#include "joueur.h"
#include <QString>

Joueur::Joueur(const QString& un_nom, const Couleur& une_couleur)
    : nom(un_nom), couleur(une_couleur) {}

QString Joueur::get_nom() const { return nom; }

Couleur Joueur::get_couleur() const { return couleur; }
