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
    time_t expiryDate;
    int quantity;
    int price;

public:
    Fruit(string name, string origin, time_t expiryDate = 0, int quantity = 0, int price = 0);

    [[nodiscard]] string getName() const;

    [[nodiscard]] string getOrigin() const;
    
    [[nodiscard]] string getExpiryDateStr() const;

    [[nodiscard]] int getQuantity() const;

    [[nodiscard]] int getPrice() const;

    void setName(const string &_name);

    void setOrigin(const string &_origin);

    void setExpiryDate(time_t _expiryDate);

    void setExpiryDate(const string &_expiryDate);

    void setQuantity(int quantity);

    void setPrice(int price);

    bool operator==(const Fruit& other);

    void print();
};


#endif //LAB4_FRUIT_H
