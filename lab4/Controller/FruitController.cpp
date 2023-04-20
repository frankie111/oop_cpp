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
 * @returns a vector of Fruit objects representing matches sorted by names
 */
vector<Fruit> FruitController::find(const string &keyWord) const {
    vector<Fruit> matches;

    if (keyWord.empty())
        matches = repo->getAll();
    else {
        string lowerKey = toLower(keyWord);

        for (const Fruit &fruit: repo->getAll())
            if (toLower(fruit.getName()).find(lowerKey) != string::npos ||
                toLower(fruit.getOrigin()).find(lowerKey) != string::npos)
                matches.push_back(fruit);
    }

    // Sort matches by name attribute:
    sort(matches.begin(), matches.end(), [](const Fruit &fruit1, const Fruit &fruit2) {
        return fruit1.getName() < fruit2.getName();
    });

    return matches;
}

/**
 * Find all fruit with a quantity less than or equal to a specified threshold
 * @param threshold
 * @returns a vector of Fruit objects sorted by names
 */
vector<Fruit> FruitController::findScarce(int threshold) const {
    vector<Fruit> matches;

    for (const Fruit &fruit: repo->getAll())
        if (fruit.getQuantity() <= threshold)
            matches.push_back(fruit);

    // Sort matches by name attribute:
    sort(matches.begin(), matches.end(), [](const Fruit &fruit1, const Fruit &fruit2) {
        return fruit1.getName() < fruit2.getName();
    });

    return matches;
}

/**
 * @returns a vector of all Fruit objects sorted by expiry dates
 */
vector<Fruit> FruitController::sortByExpiryDate() const {
    vector<Fruit> list = repo->getAll();

    // Sort list by expiry date:
    sort(list.begin(), list.end(), [](const Fruit &fruit1, const Fruit &fruit2) {
        return fruit1.getExpiryDate() < fruit2.getExpiryDate();
    });

    return list;
}



