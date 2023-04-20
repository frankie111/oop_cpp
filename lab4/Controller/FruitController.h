#ifndef LAB4_FRUITCONTROLLER_H
#define LAB4_FRUITCONTROLLER_H

#include "../Repository/FruitRepo.h"

using namespace std;

class FruitController {
private:
    //TODO: use smart pointer
    FruitRepo *repo;

public:
    explicit FruitController(FruitRepo &_repo);

    void add(const string &name, const string &origin,
             const time_t &expiryDate, int quantity, int price
    );

    bool remove(const string &name, const string &origin);

    [[nodiscard]] vector<Fruit> find(const string &keyWord = "") const;

    [[nodiscard]] vector<Fruit> findScarce(int threshold) const;

    [[nodiscard]] vector<Fruit> sortByExpiryDate() const;

};


#endif //LAB4_FRUITCONTROLLER_H
