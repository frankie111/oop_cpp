#include "FruitRepo.h"

FruitRepo::FruitRepo() {
    fruitList.emplace_back("Apfel", "Rumanien", "15-05-2023", 1300, 5);
    fruitList.emplace_back("Orange", "Spanien", "22-09-2024", 2000, 4);
    fruitList.emplace_back("Banane", "Costa Rica", "03-07-2025", 1000, 3.5);
    fruitList.emplace_back("Kiwi", "Neuseeland", "16-12-2024", 800, 6);
    fruitList.emplace_back("Traube", "Frankreich", "08-03-2025", 1500, 7);
    fruitList.emplace_back("Ananas", "Hawaii", "30-06-2025", 500, 8);
    fruitList.emplace_back("Wassermelone", "USA", "10-08-2024", 700, 10);
    fruitList.emplace_back("Erdbeere", "Deutschland", "01-05-2025", 1200, 5.5);
    fruitList.emplace_back("Mango", "Indien", "19-07-2024", 900, 4.5);
    fruitList.emplace_back("Pfirsich", "Italien", "27-11-2025", 1000, 6.5);
    fruitList.emplace_back("Apfel", "Deutschland", "02-10-2024", 1100, 3);
    fruitList.emplace_back("Birne", "Deutschland", "09-11-2025", 800, 4);

};

/**
 * Add a Fruit item to fruitList
 * @param fruit Fruit object to be added
 */
void FruitRepo::add(const Fruit &fruit) {
    fruitList.push_back(fruit);
}

/**
 * Removes the Fruit object at a certain index
 * @param index index of object to be erased
 * @throws out_of_range if index is invalid
 */
void FruitRepo::remove(int index) {
    if (index < 0 || index > fruitList.size())
        throw out_of_range("FruitRepo::remove(): Index out of range for index " + to_string(index));

    fruitList.erase(fruitList.begin() + index);
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

/**
 * @returns a copy of the Fruit vector
 */
vector<Fruit> FruitRepo::getAll() {
    return fruitList;
}

/**
 * Update the Fruit object at a certain index
 * @param index of object to be edited
 * @param newFruit new Fruit object to replace the old one
 * @throws out_of_range if given index is invalid
 */
void FruitRepo::update(int index, const Fruit &newFruit) {
    if (index < 0 || index > fruitList.size())
        throw out_of_range("FruitRepo::update(): Index out of range for index " + to_string(index));

    fruitList[index] = newFruit;
}

/**
 * @returns the index of a Fruit object if found, -1 otherwise
 * @param fruit Fruit object to search for
 */
int FruitRepo::getIndexOf(const Fruit &fruit) {
    auto iter = find(fruitList.begin(), fruitList.end(), fruit);
    if (iter != fruitList.end()) {
        int index = int(distance(fruitList.begin(), iter));
        return index;
    }

    return -1;
}

/**
 * @returns the Fruit object at a certain index
 * @param index to be queried
 * @throws out_of_range if index is invalid
 */
Fruit FruitRepo::getFruitAtIndex(int index) {
    if (index < 0 || index > fruitList.size())
        throw out_of_range("FruitRepo::update(): Index out of range for index " + to_string(index));

    return fruitList[index];
}


