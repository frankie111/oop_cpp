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
    if (index == -1) {
        repo->add(newFruit);
        return;
    }

    // Update quantity if fruit already exists
    newFruit.setQuantity(newFruit.getQuantity() + repo->getAll()[index].getQuantity());
    repo->update(index, newFruit);
}

/**
 * Removes a Fruit item by name and origin
 * @returns true if the operations was successful, false otherwise
 */
bool FruitController::remove(const string &name, const string &origin) {
    return repo->remove(Fruit(name, origin));
}

/**
 * Find all fruit that match a certain keyword
 * @param keyWord keyword to search for
 * @returns a vector of Fruit objects representing matches
 */
vector<Fruit> FruitController::find(const string &keyWord) {
    if (keyWord.empty())
        return repo->getAll();

    string lowerKey = toLower(keyWord);

    vector<Fruit> matches;
    for (const Fruit &fruit: repo->getAll())
        if (toLower(fruit.getName()).find(keyWord) != string::npos ||
            toLower(fruit.getOrigin()).find(keyWord) != string::npos)
            matches.push_back(fruit);

    return matches;
}
