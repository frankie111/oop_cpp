#ifndef MODELE_P3_H
#define MODELE_P3_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Order{
public:
    string date;
    string status;

    void cancel();
    void process();
    void createItem();
    void updateItem();
    void deleteItem();
};

class Customer {
public:
    string address;
    string phone;
    vector<Order> orders;

    void update();
};

class Company : public Customer {
public:
    string name;
    string regno;
};

class Person : public Customer {
public:
    string firstName;
    string lastName;
};

#endif //MODELE_P3_H
