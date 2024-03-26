//particule.h
#ifndef PARTICULE_H  
#define PARTICULE_H



#include <string>
#include "Vecteur.h"
#include <chrono>

class Particule {
    public:

    Particule(Vecteur position, Vecteur vitesse, double masse, int identifiant, std::string categorie, Vecteur force);
        // Méthodes d'accès aux propriétés
    Vecteur getPosition() const;
    Vecteur getVitesse() const;
    double getMasse() const;
    int getIdentifiant() const;
    std::string getCategorie() const;
    Vecteur getForce() const;
    void updateForce(const Vecteur newForce);
    void display() const;
    void display_short() const;
    bool operator<(const Particule& other) const;

private:
    // Propriétés de la particule
    Vecteur position;
    Vecteur vitesse;
    double masse;
    int identifiant;
    std::string categorie;
    Vecteur force;
};
#endif  //PARTICULE_H