#ifndef LAB4_FRUITUI_H
#define LAB4_FRUITUI_H

#include "../Controller/FruitController.h"

using namespace std;

class FruitUI {
private:
    static const int MAX_LINE_WIDTH = 64;
    enum TitleStyle {
        TITLE_CHAR = '=',
        SUBTITLE_CHAR = '-'
    };

    //TODO: use smart pointer
    FruitController *controller;

    void printTitle(const string &title, TitleStyle tStyle = TITLE_CHAR) const;

    [[nodiscard]] int menu(const string &title, const vector<string> &options) const;

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
