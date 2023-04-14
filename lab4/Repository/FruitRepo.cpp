#include "FruitRepo.h"

FruitRepo::FruitRepo() = default;

void FruitRepo::add(const Fruit &fruit) {
    fruitList.push_back(fruit);
}

bool FruitRepo::remove(const Fruit &fruit) {
    std::remove(fruitList.begin(), fruitList.end(), fruit);
}

vector<Fruit> FruitRepo::getAll() {
    return fruitList;
}
