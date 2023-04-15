#include "FruitRepo.h"

FruitRepo::FruitRepo() = default;

/**
 * Add a Fruit item to fruitList
 * @param fruit
 */
void FruitRepo::add(const Fruit &fruit) {
    fruitList.push_back(fruit);
}

/**
 * Remove a Fruit item from fruitList if found
 * @param fruit Fruit item to be removed
 * @returns true if element was found or false otherwise
 */
bool FruitRepo::remove(const Fruit &fruit) {
    auto it = find(fruitList.begin(), fruitList.end(), fruit);
    if (it != fruitList.end()) {
        fruitList.erase(it);
        return true;
    }

    return false;
}

vector<Fruit> FruitRepo::getAll() {
    return fruitList;
}

void FruitRepo::remove(int index) {
    if (index < 0 || index > fruitList.size())
        throw out_of_range("FruitRepo::remove(): Index out of range for index " + to_string(index));

    fruitList.erase(fruitList.begin() + index);
}


