#ifndef LAB4_FRUITREPO_H
#define LAB4_FRUITREPO_H


#include<iostream>
#include <vector>
#include "../Domain/Fruit.h"

class FruitRepo {
private:
    vector<Fruit> fruitList{};
public:
    explicit FruitRepo();

    void add(const Fruit &fruit);

    bool remove(const Fruit &fruit);

    void remove(int index);

    vector<Fruit> getAll();

};


#endif //LAB4_FRUITREPO_H
