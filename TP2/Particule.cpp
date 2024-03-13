#include <iostream>
#include <list>
#include <set>
#include <deque>
#include <vector>
#include <random>

class Particle {
private:
    int id;
    double position[3];
    double velocity[3];
    double mass;
    std::string category;
    double force;

public:
    Particle(int id, double x, double y, double z, double vx, double vy, double vz, double mass, std::string category)
        : id(id), mass(mass), category(category), force(0.0) {
        position[0] = x;
        position[1] = y;
        position[2] = z;
        velocity[0] = vx;
        velocity[1] = vy;
        velocity[2] = vz;
    }

    void display() {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Position: (" << position[0] << ", " << position[1] << ", " << position[2] << ")" << std::endl;
        std::cout << "Velocity: (" << velocity[0] << ", " << velocity[1] << ", " << velocity[2] << ")" << std::endl;
        std::cout << "Mass: " << mass << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Force: " << force << std::endl;
    }

    void updateForce(double newForce) {
        force = newForce;
    }
};

int main() {
    // Création et initialisation des collections de particules
    std::list<Particle> particleList;
    std::set<Particle> particleSet;
    std::deque<Particle> particleDeque;
    std::vector<Particle> particleVector;

    // Initialisation des paramètres pour la génération aléatoire
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Ajout de particules à chaque collection
    for (int i = 0; i < 16; ++i) {
        double x = dist(mt);
        double y = dist(mt);
        double z = dist(mt);
        double vx = dist(mt);
        double vy = dist(mt);
        double vz = dist(mt);
        double mass = dist(mt) * 10.0;
        std::string category = "Type" + std::to_string(i);

        // Ajout de particule à la liste
        particleList.emplace_back(i, x, y, z, vx, vy, vz, mass, category);
        
        // Ajout de particule au set
        particleSet.emplace(i, x, y, z, vx, vy, vz, mass, category);
        
        // Ajout de particule à la deque
        particleDeque.emplace_back(i, x, y, z, vx, vy, vz, mass, category);
        
        // Ajout de particule au vector
        particleVector.emplace_back(i, x, y, z, vx, vy, vz, mass, category);
    }

    // Affichage des particules dans chaque collection
    std::cout << "Particules dans la liste:" << std::endl;
    for (const auto& particle : particleList) {
        particle.display();
        std::cout << std::endl;
    }

    std::cout << "Particules dans le set:" << std::endl;
    for (const auto& particle : particleSet) {
        particle.display();
        std::cout << std::endl;
    }

    std::cout << "Particules dans la deque:" << std::endl;
    for (const auto& particle : particleDeque) {
        particle.display();
        std::cout << std::endl;
    }

    std::cout << "Particules dans le vector:" << std::endl;
    for (const auto& particle : particleVector) {
        particle.display();
        std::cout << std<::endl;
    }

    return 0;
}