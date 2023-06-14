#ifndef MODELE_P3_H
#define MODELE_P3_H

#include <iostream>
#include <string>

using namespace std;

class Feeder {
private:
    // Doua instante posibile
    static Feeder *instanceA, *instanceB;

    // Bool pentru a alterna instantele returnate de getInstance
    static bool choice;

    string name;

    // Constructor privat
    explicit Feeder(const string &_name) {
        name = _name;
    }

public:
    // Functia statica care returneaza o instanta
    static Feeder *getInstance() {
        // Schimba instanta
        choice = !choice;

        if (choice == 0) {
            if (instanceA == nullptr)
                instanceA = new Feeder("A");
            return instanceA;
        } else {
            if (instanceB == nullptr)
                instanceB = new Feeder("B");
            return instanceB;
        }
    }

    string getName() const {
        return name;
    }

    // Stergem copy constructor
    Feeder(Feeder &other) = delete;

    // Stergem assignment operator
    void operator=(const Feeder &other) = delete;
};

// Variabilele statice trebuie initializate inafara clasei
Feeder *Feeder::instanceA = nullptr;
Feeder *Feeder::instanceB = nullptr;
bool Feeder::choice = true;

void test() {
    Feeder *feeder;
    for (int i = 0; i < 10; i++) {
        feeder = Feeder::getInstance();
        cout << feeder->getName() << endl;
    }
}

#endif //MODELE_P3_H
