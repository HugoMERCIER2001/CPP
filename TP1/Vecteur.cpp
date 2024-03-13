#include "Vecteur.h"

Vecteur::Vecteur(double X, double Y, double Z): x(X), y(Y), z(Z) {}

double Vecteur::getX() const {
    return x;
}

double Vecteur::getY() const {
    return y;
}

double Vecteur:: getZ() const {
    return z;
}
