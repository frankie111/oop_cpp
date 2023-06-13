#ifndef MODELE_P1_H
#define MODELE_P1_H

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Address {
public:

    Address(const string &_street, const string &_city, const string &_state, T _postalCode,
            const string &_country) {
        street = _street;
        city = _city;
        state = _state;
        postalCode = _postalCode;
        country = _country;
    }

    string street;
    string city;
    string state;
    T postalCode;
    string country;

    bool validate();
};

class Person{

};

class Student: public Person{

};

#endif //MODELE_P1_H
