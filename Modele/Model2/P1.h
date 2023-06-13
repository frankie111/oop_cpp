#ifndef MODELE_P1_H
#define MODELE_P1_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template<typename MAMA_LU_CRISTI>
class Vector3D {
private:
    MAMA_LU_CRISTI x, y, z;
public:
    string asText() {
        return to_string(x) + " " + to_string(y) + " " + to_string(z);
    };

    Vector3D(MAMA_LU_CRISTI _x, MAMA_LU_CRISTI _y, MAMA_LU_CRISTI _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3D() {
        x = 0;
        y = 0;
        z = 0;
    }
};

template<typename BUNSA_LU_DADU>
class Particle {
private:
    Vector3D<BUNSA_LU_DADU> position;
    int speed, mass;
    string timeStamp;

public:
    Particle(Vector3D <BUNSA_LU_DADU> _position, int _speed, int _mass, string _timeStamp) {
        position = _position;
        speed = _speed;
        mass = _mass;
        timeStamp = _timeStamp;
    }

    int getMass() const {
        return mass;
    }
};

void addBunsa(){
    vector<Particle<int>> particles{
            {Vector3D<int>(1, 2, 3), 4, 5, "6"},
            {Vector3D<int>(7, 8, 9), 10, 11, "12"},
            {Vector3D<int>(13, 14, 15), 16, 17, "18"}
    };

    // Add mass of particles
    int sum = 0;
    for (const auto& particle : particles) {
        sum += particle.getMass();
    }

}

#endif //MODELE_P1_H
