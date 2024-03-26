#include <iostream>
#include <list>
#include <set>
#include <deque>
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include "Particule.h"
#include "Vecteur.h"


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
    // Affichage des particules dans chaque collection
    // std::cout << "Particules dans la liste:" << std::endl;
    // for (const auto& particule : particuleList) {
    //     particule.display();
    //     std::cout << std::endl;
    // }

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
    // for (const auto& particule : particuleVector) {
    //     particule.display();
    //     std::cout << std::endl;
    // }

    return 0;

}