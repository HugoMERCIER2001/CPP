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

// Opérateur d'addition
Vecteur Vecteur::operator+(const Vecteur& autre) const {
    return Vecteur(x + autre.x, y + autre.y, z + autre.z);
}

// Opérateur de soustraction
Vecteur Vecteur::operator-(const Vecteur& autre) const {
    return Vecteur(x - autre.x, y - autre.y, z - autre.z);
}

// Opérateur de multiplication
Vecteur Vecteur::operator*(const Vecteur& autre) const {
    return Vecteur(x * autre.x, y * autre.y, z * autre.z);
}

// Opérateur de multiplication scalaire
Vecteur Vecteur::operator*(double scalaire) const {
    return Vecteur(x * scalaire, y * scalaire, z * scalaire);
}

// Opérateur de division scalaire
Vecteur Vecteur::operator/(double scalaire) const {
    return Vecteur(x / scalaire, y / scalaire, z / scalaire);
}

// Opérateur de division scalaire
Vecteur Vecteur::operator/(const Vecteur& autre) const {
    return Vecteur(x / autre.x, y / autre.y, z / autre.z);
}



// Norme du vecteur
double Vecteur::norme() const {
    return std::sqrt(x*x + y*y + z*z);
}