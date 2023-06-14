#ifndef MODELE_P4_H
#define MODELE_P4_H

#include <iostream>
#include <string>

using namespace std;

class Tank {
private:
    string id;
    int capacity;
    float fillPercent;

public:
    explicit Tank(const string &_id) {
        id = _id;
        capacity = 0;
        fillPercent = 0;
    }

    // Calculeaza cati litri sunt in rezervor
    float getRemainingLiters() const {
        return fillPercent / 100 * (float) capacity;
    }

    string getId() const {
        return id;
    }

    int getCapacity() const {
        return capacity;
    }

    float getFillPercent() const {
        return fillPercent;
    }

    void setId(const string &_id) {
        id = _id;
    }

    void setCapacity(int _capacity) {
        capacity = _capacity;
    }

    void setFillPercent(float _fp) {
        fillPercent = _fp;
    }
};

class GasTank : public Tank {
private:
    string gas;
    float density;
    static int numId;

public:
    GasTank() : Tank("GTID-" + to_string(numId)) {
        numId += 2;
        density = 0;
    }

    float totalWeight() {
        return density * getRemainingLiters();
    }
};

// variabila statica trebuie initializata inafara clasei
int GasTank::numId = 0;

#endif //MODELE_P4_H
