#include "Particule.h"
#include "Vecteur.h"
#include <iostream>

// Constructeur
Particule::Particule(Vecteur position, Vecteur vitesse, double masse, int identifiant, std::string categorie, Vecteur force) :
    position(position), vitesse(vitesse), masse(masse), identifiant(identifiant), categorie(categorie), force(force) {}

// Méthodes d'accès aux propriétés
Vecteur Particule::getPosition() const {
    return position;
}

Vecteur Particule::getVitesse() const {
    return vitesse;
}

double Particule::getMasse() const {
    return masse;
}

int Particule::getIdentifiant() const {
    return identifiant;
}

std::string Particule::getCategorie() const {
    return categorie;
}

Vecteur Particule::getForce() const {
    return force;
}

void Particule::display() const {
    std::cout << "Identifiant: " << identifiant << std::endl;
    std::cout << "Position: (" << position.getX() << ", " << position.getY() << ", " << position.getZ() << ")" << std::endl;
    std::cout << "Vitesse: (" << vitesse.getX() << ", " << vitesse.getY() << ", " << vitesse.getZ() << ")" << std::endl;
    std::cout << "Masse: " << masse << std::endl;
    std::cout << "Catégorie: " << categorie << std::endl;
    std::cout << "Force: (" << force.getX() << ", " << force.getY() << ", " << force.getZ() << ")" << std::endl;
}

bool Particule::operator<(const Particule& other) const {
    // Implémentez la logique de comparaison ici
    // Par exemple, comparez les attributs de Particule
    // et retournez true si la particule courante est inférieure à l'autre.
    return identifiant < other.identifiant;
}

// Mise à jour de la position
void Particule::updatePosition(const Vecteur& newPosition) {
    position = newPosition;
}

// Mise à jour de la vitesse
void Particule::updateVitesse(const Vecteur& newVitesse) {
    vitesse = newVitesse;
}
// Mise à jour de la force
void Particule::updateForce(const Vecteur newForce) {
    force = newForce;
}