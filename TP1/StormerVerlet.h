#ifndef STORMERVERLET_H
#define STORMERVERLET_H

#include "Particule.h"
#include "Vecteur.h"
#include <iostream>
#include <vector>

class StormerVerlet {
private:
    std::vector<Particule> particules;

public:
    StormerVerlet(std::vector<Particule> particules);
    Vecteur calculerForce(const Particule& particule1, const Particule& particule2);
    Vecteur calculerForcesSurParticule(Particule& particule);
    void updateParticule(Particule& particule, double deltaTime);
    void stormerVerlet_execution(double t_end, double deltaTime);
};

#endif 