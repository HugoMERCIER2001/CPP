#include <iostream>
#include <list>
#include <set>
#include <deque>
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include "Particule.h"
#include "Vecteur.h"

std::list<Particule> calcul_forces(std::list<Particule> particuleList){
    for (auto it1 = particuleList.begin(); it1 != particuleList.end(); ++it1++){
        double all_forces_x = 0;
        double all_forces_y = 0;
        Particule particule1 = *it1;
        for (auto it2 = particuleList.begin(); it2 != particuleList.end(); ++it2++){
            if(it1 != it2){
                Particule particule2 = *it2;
                double norme_force = (particule2.getMasse() * particule1.getMasse()) / pow(sqrt(pow((particule2.getPosition().getX() - particule1.getPosition().getX()), 2) + pow((particule2.getPosition().getY() - particule1.getPosition().getY()), 2)), 3);
                all_forces_x = all_forces_x + norme_force * (particule2.getPosition().getX() - particule1.getPosition().getX());
                all_forces_y = all_forces_y + norme_force * (particule2.getPosition().getY() - particule1.getPosition().getY());
            } 
        }
        Vecteur const force = Vecteur(all_forces_x, all_forces_y, 0);
        particule1.updateForce(force);
    }
    return particuleList;
}

void stromer_verlet(std::list<Particule> particuleList, double deltat, double t_end){
    double t = 0;
    //Affichage des particules dans chaque collection
    std::cout << "t = " << t << " \n" << "Particules dans la liste:" << std::endl;
    for (const auto& particule : particuleList) {
        particule.display_short();
        std::cout << std::endl;}
    particuleList = calcul_forces(particuleList);
    while(t != t_end){
        
    } 
}

int execution_stromer_verlet() {

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

    double deltat = 0.015;
    double t_end = 468.5;
    stromer_verlet(particuleList, deltat, t_end);
    return 0;
}

int main(int argc, char* argv[]) {
    // Création et initialisation des collections de particules
    std::list<Particule> particuleList;
    std::set<Particule> particuleSet;
    std::deque<Particule> particuleDeque;
    std::vector<Particule> particuleVector;

    // Initialisation des paramètres pour la génération aléatoire
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    std::cout << " \n QUESTION 3 \n"<< std::endl;
    // Ajout de particules à chaque collection
    for(int k = 0; k < 4; ++k){

    if(k == 0){
        std::cout << "TESTS LISTE : \n";
    }
    if(k == 1){
        std::cout << "TESTS SET : \n";
    }
    if(k == 2){
        std::cout << "TESTS DEQUE : \n";
    }
    if(k == 3){
        std::cout << "TESTS VECTOR : \n";
    }
    for (int j = 1; j< argc; ++j) {
    auto start = std::chrono::steady_clock::now();
    int borne_sup = std::atoi(argv[j]);
    for (int i = 0; i < borne_sup; ++i) {
        double x = dist(mt);
        double y = dist(mt);
        double z = dist(mt);
        Vecteur position = Vecteur(x, y, z);
        double vx = dist(mt);
        double vy = dist(mt);
        double vz = dist(mt);
        Vecteur vitesse = Vecteur(vx, vy, vz);
        double fx = 0;
        double fy = 0;
        double fz = 0;
        Vecteur force = Vecteur(fx, fy, fz);
        double mass = dist(mt) * 10.0;
        std::string category = "Type" + std::to_string(i);

        if(k == 0){
        //à commenter pour tester une seule des templates
        //Ajout de particule à la liste
        particuleList.emplace_back(position, vitesse, mass, i, category, force);}
        
        if(k == 1){
        //Ajout de particule au set
        particuleSet.emplace(position, vitesse, mass, i, category, force);
        }

        if(k == 2){
        //Ajout de particule à la deque
        particuleDeque.emplace_back(position, vitesse, mass, i, category, force);
        }

        if(k == 3){
        //Ajout de particule au vector
        particuleVector.emplace_back(position, vitesse, mass, i, category, force);
        }
    }
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "On test pour " << borne_sup << " particules ";
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << "\n";
    }
    }

    execution_stromer_verlet();
    std::cout << "Fin" << std::endl;
     // Affichage des particules dans chaque collection
    // std::cout << "Particules dans la liste:" << std::endl;
    // for (const auto& particule : particuleList) {
    //     particule.display();
    //     std::cout << std::endl;

    // std::cout << "Particules dans le set:" << std::endl;
    // for (const auto& particule : particuleSet) {
    //     particule.display();
    //     std::cout << std::endl;
    // }

    // std::cout << "Particules dans la deque:" << std::endl;
    // for (const auto& particule : particuleDeque) {
    //     particule.display();
    //     std::cout << std::endl;
    // }

    // std::cout << "Particules dans le vector:" << std::endl;
    // for (const auto& particule : par<Vecteur>ArrayticuleVector) {
    //     particule.display();
    //     std::cout << std::endl;
    // }

    return 0;

}