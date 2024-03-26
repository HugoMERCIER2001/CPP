#include "Particule.h"
#include "Vecteur.h"
#include "StormerVerlet.h"
#include <iostream>
#include <vector>
#include <cmath>

//Constructeur d'un objet de type Stormer Verlet
StormerVerlet::StormerVerlet(std::vector<Particule> particules) : particules(particules) {}


// Définir une fonction pour calculer la force entre deux particules
Vecteur StormerVerlet::calculerForce(const Particule& particule1, const Particule& particule2) {
    Vecteur r = particule2.getPosition()-(particule1.getPosition());
    double distanceCubed = r.norme()*r.norme()*r.norme(); // Utilisation de la méthode norme pour calculer la norme du vecteur
    double G = 6.674e-11; // Constante gravitationnelle
    double forceMagnitude = (particule1.getMasse() * particule2.getMasse() * G) / distanceCubed;
    return r*(forceMagnitude / r.norme());
}
// Méthode pour calculer les forces sur une particule spécifique et mettre à jour sa force
Vecteur StormerVerlet::calculerForcesSurParticule(Particule& particule){
    for (const Particule& autreParticule : particules) {
        if (autreParticule.getIdentifiant() != particule.getIdentifiant()) {
            particule.updateForce((particule.getForce())+(calculerForce(particule, autreParticule)));
        }
    }
}

void StormerVerlet::updateParticule(Particule& particule, double deltaTime){
    // Calcul de la nouvelle position : x_i + v_i*deltaTime + deltaTime*0.5/m_i*F_i*deltaTime 
    // mettre des + et des - marcherait quand même car c++ va comprendre qu'on fait bien appel à operator+ et operator-
    Vecteur nouvellePosition = particule.getPosition()+particule.getVitesse()*deltaTime+particule.getForce()*deltaTime*deltaTime*(0.5/particule.getMasse());
    // Sauvegarde de l'ancienne force
    Vecteur ancienneForce = particule.getForce();
    // Mise à jour de la force
    particule.updateForce(calculerForcesSurParticule(particule));
    // Calcul de la nouvelle vitesse
    Vecteur nouvelleVitesse = particule.getVitesse() + ((particule.getForce() + ancienneForce) / particule.getMasse()) * deltaTime * 0.5;
    // Mise à jour de la position et de la vitesse de la particule
    particule.updatePosition(nouvellePosition);
    particule.updateVitesse(nouvelleVitesse);
}

void StormerVerlet::stormerVerlet_execution(double t_end, double deltaTime){
    double temps = 0.0;
    while (temps < t_end) {
        temps += deltaTime;
        for (Particule& autreParticule : particules) {
            updateParticule(autreParticule,deltaTime);
        }
        // Affichage des quantités t, x, y pour chaque particule
        for (const Particule& particule : particules) {
            std::cout << "Identifiant: " << particule.getIdentifiant() << std::endl;
            std::cout << "Temps: " << temps << std::endl;
            std::cout << "Position: (" << particule.getPosition().getX() << ", " << particule.getPosition().getY() << ", " << particule.getPosition().getZ() << ")" << std::endl;
            std::cout << "Vitesse: (" << particule.getVitesse().getX() << ", " << particule.getVitesse().getY() << ", " << particule.getVitesse().getZ() << ")" << std::endl;
        }
    }
}
