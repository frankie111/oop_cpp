#include "FruitController.h"

FruitController::FruitController(FruitRepo &_repo) {
    repo = &_repo;
}

/**
 * Add a new Fruit object to the repo or change the current quantity if object already exists
 * @returns true if a new Fruit object was added, false if existent object was modified
 */
bool FruitController::add(const string &name, const string &origin, const time_t &expiryDate, int quantity, int price) {
    Fruit newFruit = Fruit(name, origin, expiryDate, quantity, price);
    int index = getIndexOf(newFruit);
    if (index == -1) {
        repo->add(newFruit);
        return true;
    }

    newFruit.setQuantity(newFruit.getQuantity() + repo->getAll()[index].getQuantity());
    repo->remove(index);
    repo->add(newFruit);
    return false;
}

bool FruitController::remove(const string &name, const string &origin) {
    return false;
}

vector<Fruit> FruitController::find(const string &name, const string &origin) {

}

/**
 * @returns the index of a Fruit object or -1 if not found
 * @param fruit
 */
int FruitController::getIndexOf(const Fruit &fruit) {
    vector<Fruit> list = repo->getAll();
    for (int i = 0; i < list.size(); i++) {
        if (fruit == list[i])
            return i;
    }

    return -1;
}
