#ifndef LAB4_FRUIT_H
#define LAB4_FRUIT_H

#include <string>
#include <chrono>
#include <iostream>

using namespace std;

class Fruit {
private:
    string name;
    string origin;
    string type;
    time_t expiryDate;
    int quantity;
    int price;

public:
    [[nodiscard]] string getName() const;

    [[nodiscard]] string getOrigin() const;

    [[nodiscard]] string getType() const;

    [[nodiscard]] string getExpiryDateStr() const;

    [[nodiscard]] int getQuantity() const;

    [[nodiscard]] int getPrice() const;

    void setName(const string &_name);

    void setOrigin(const string &_origin);

    void setType(const string &_type);

    void setExpiryDate(time_t _expiryDate);

    void setExpiryDate(const string &_expiryDate);

    void setQuantity(int quantity);

    void setPrice(int price);
};


#endif //LAB4_FRUIT_H
