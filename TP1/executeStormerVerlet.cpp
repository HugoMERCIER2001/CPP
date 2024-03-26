#include "Particule.h"
#include "Vecteur.h"
#include "StormerVerlet.h"
#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char* argv[]) {
    std::cout << "\n QUESTION 5 \n" << std::endl;
    //On initialise la particuleList
    std::vector<Particule> particules;
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
    particules.emplace_back(position, vitesse, mass, 0, category, force);

    //On a ajoute la Terre dans la liste
    double y_Terre = 1;
    Vecteur position_Terre = Vecteur(0, y_Terre, 0);
    double vx_Terre  = -1;
    Vecteur vitesse_Terre = Vecteur(vx_Terre, 0, 0);
    double mass_Terre = 3 * pow(10, -6);
    std::string category_Terre = "Terre";
    particules.emplace_back(position_Terre, vitesse_Terre, mass_Terre, 1, category_Terre, force);

    //On a ajoute Jupiter dans la liste
    double y_Jupiter = 5.36;
    Vecteur position_Jupiter = Vecteur(0, y_Jupiter, 0);
    double vx_Jupiter = -0.425;
    Vecteur vitesse_Jupiter = Vecteur(vx_Jupiter, 0, 0);
    double mass_Jupiter = 9.55 * pow(10, -4);
    std::string category_Jupiter = "Jupiter";
    particules.emplace_back(position_Jupiter, vitesse_Jupiter, mass_Jupiter, 2, category_Jupiter, force);

    //On a ajoute la comète de Hailey dans la liste
    double x_Hailey = 34.75;
    Vecteur position_Hailey = Vecteur(x_Hailey, 0, 0);
    double vy_Hailey = 0.0296;
    Vecteur vitesse_Hailey = Vecteur(0, vy_Hailey, 0);
    double mass_Hailey = pow(10, -14);
    std::string category_Hailey = "Hailey";
    particules.emplace_back(position_Hailey, vitesse_Hailey, mass_Hailey, 3, category_Hailey, force);

    StormerVerlet mon_verlet = StormerVerlet(particules);
    double deltaT = 0.015;
    double t_end = 468.5;
    mon_verlet.stormerVerlet_execution(deltaT, t_end);
    return 0;
}
