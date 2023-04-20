#ifndef LAB4_FRUITUI_H
#define LAB4_FRUITUI_H

#include "../Controller/FruitController.h"

using namespace std;

class FruitUI {
    friend class Widgets;

private:

    //TODO: use smart pointer
    FruitController *controller;
    static const int MAX_LINE_WIDTH = 100;

public:
    explicit FruitUI(FruitController &_controller);

    void mainMenu() const;

    void addProduct() const;

    void deleteProduct() const;

    void searchProduct() const;

    void printScarceProducts() const;

    void sortByExpiryDate() const;
};


#endif //LAB4_FRUITUI_H
