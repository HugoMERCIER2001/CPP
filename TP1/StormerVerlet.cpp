#include "Particule.h"
#include "Vecteur.h"
#include "StormerVerlet.h"
#include <iostream>
#include <vector>

// Définir une fonction pour calculer la force entre deux particules
Vecteur StormerVerlet::calculerForce(const Particule& particule1, const Particule& particule2) {
    Vecteur r = particule2.getPosition()-(particule1.getPosition());
    double distanceCubed = r.norme()*r.norme()*r.norme(); // Utilisation de la méthode norme pour calculer la norme du vecteur
    double G = 6.674e-11; // Constante gravitationnelle
    double forceMagnitude = (particule1.getMasse() * particule2.getMasse() * G) / distanceCubed;
    return r*(forceMagnitude / r.norme());
}
// Méthode pour calculer les forces sur une particule spécifique et mettre à jour sa force
void StormerVerlet::calculerForcesSurParticule(Particule& particule){
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

void StormerVerlet::stormerVerlet(double t_end, double deltaTime){

    std::cout << "\n QUESTION 5 \n" << std::endl;
    //On initialise la particuleList
    std::list<Particule> particuleList;
    //On a ajoute le Soleil dans la liste
    double x = 0;
    double y = 0;
    double z = 0;
    Vecteur position = Vecteur(x, y, z);
    double vx = 0;
    double vy = 0;
    double vz = 0;
    Vecteur vitesse = Vecteur(vx, vy, vz);
    double fx = 0;
    double fy = 0;
    double fz = 0;
    Vecteur force = Vecteur(fx, fy, fz);
    double mass = 1;
    std::string category = "Soleil";
    particuleList.emplace_back(position, vitesse, mass, 0, category, force);

    //On a ajoute la Terre dans la liste
    double y_Terre = 1;
    Vecteur position_Terre = Vecteur(0, y_Terre, 0);
    double vx_Terre  = -1;
    Vecteur vitesse_Terre = Vecteur(vx_Terre, 0, 0);
    double mass_Terre = 3 * pow(10, -6);
    std::string category_Terre = "Terre";
    particuleList.emplace_back(position_Terre, vitesse_Terre, mass_Terre, 1, category_Terre, force);

    //On a ajoute Jupiter dans la liste
    double y_Jupiter = 5.36;
    Vecteur position_Jupiter = Vecteur(0, y_Jupiter, 0);
    double vx_Jupiter = -0.425;
    Vecteur vitesse_Jupiter = Vecteur(vx_Jupiter, 0, 0);
    double mass_Jupiter = 9.55 * pow(10, -4);
    std::string category_Jupiter = "Jupiter";
    particuleList.emplace_back(position_Jupiter, vitesse_Jupiter, mass_Jupiter, 2, category_Jupiter, force);

    //On a ajoute la comète de Hailey dans la liste
    double x_Hailey = 34.75;
    Vecteur position_Hailey = Vecteur(x_Hailey, 0, 0);
    double vy_Hailey = 0.0296;
    Vecteur vitesse_Hailey = Vecteur(0, vy_Hailey, 0);
    double mass_Hailey = pow(10, -14);
    std::string category_Hailey = "Hailey";
    particuleList.emplace_back(position_Hailey, vitesse_Hailey, mass_Hailey, 3, category_Hailey, force);

    double temps = 0.0;
    while (temps < t_end) {
        temps += deltaTime;
        for (const Particule& autreParticule : particules) {
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
