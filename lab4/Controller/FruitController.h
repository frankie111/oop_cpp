#ifndef LAB4_FRUITCONTROLLER_H
#define LAB4_FRUITCONTROLLER_H


#include "../Repository/FruitRepo.h"
#include "../Domain/Fruit.h"
#include <string>
#include <vector>

using namespace std;

class FruitController {
private:
    //TODO: use smart pointer
    FruitRepo *repo;

public:
    explicit FruitController(FruitRepo &_repo);

    bool add(const string &name, const string &origin,
             const time_t &expiryDate, int quantity, int price
    );

    bool remove(const string &name, const string &origin);

    vector<Fruit> find();
};


#endif //LAB4_FRUITCONTROLLER_H
