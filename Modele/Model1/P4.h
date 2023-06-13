#ifndef MODELE_P4_H
#define MODELE_P4_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Part {
public:
    string name;

    virtual float calculatePrice() = 0;
};

class BasicPart : public Part {
public:
    float unitPrice;

    BasicPart(float _unitPrice) {
        unitPrice = _unitPrice;
    }

    float calculatePrice() override;
};

class CompoundPart : public Part {
public:
    float assemblyCost;
    vector<Part> parts;

    CompoundPart(float _assemblyCost) {
        assemblyCost = _assemblyCost;
    }

    float calculatePrice() override;
};

#endif //MODELE_P4_H
