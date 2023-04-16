#include "FruitController.h"

FruitController::FruitController(FruitRepo &_repo) {
    repo = &_repo;
}

/**
 * Add a new Fruit object to the repo or change the current quantity if object already exists
 */
void FruitController::add(const string &name, const string &origin, const time_t &expiryDate, int quantity, int price) {
    Fruit newFruit = Fruit(name, origin, expiryDate, quantity, price);
    int index = repo->getIndexOf(newFruit);
    if (index == -1){
        repo->add(newFruit);
        return;
    }

    // Update quantity if fruit already exists
    newFruit.setQuantity(newFruit.getQuantity() + repo->getAll()[index].getQuantity());
    repo->update(index, newFruit);
}

bool FruitController::remove(const string &name, const string &origin) {
    return repo->remove(Fruit(name, origin));
}

vector<Fruit> FruitController::find(const string &name, const string &origin) {
    return repo->getAll();
}
