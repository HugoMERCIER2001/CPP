#ifndef VECTEUR_H
#define VECTEUR_H

#include <string>

class Vecteur{
    public: 
        Vecteur(double X, double Y, double Z);

        //Liste des méthodes :
        double getX() const;
        double getY() const;
        double getZ() const;
        // Vecteur& operator+=(const Vecteur& autre) { x += autre.x; return *this; }
        Vecteur operator+(const Vecteur& autre) const;
        Vecteur operator-(const Vecteur& autre) const;
        Vecteur operator*(const Vecteur& autre) const ;
        Vecteur operator*(double scalaire) const;
        Vecteur operator/(const Vecteur& autre) const ;
        Vecteur operator/(double scalaire) const;
        double  norme() const;
        

    private:
        double x;
        double y;
        double z;
};


#endif /* VECTEUR_H */