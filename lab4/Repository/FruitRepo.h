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

    void update(int index, const Fruit &newFruit);

    int getIndexOf(const Fruit &fruit);

    Fruit getFruitAtIndex(int index);

    vector<Fruit> getAll();

};


#endif //LAB4_FRUITREPO_H
