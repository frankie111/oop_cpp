#ifndef LAB4_FRUIT_H
#define LAB4_FRUIT_H

#include "../Utils/utils.cpp"
#include <iostream>

using namespace std;

namespace domain {

    class Fruit {
    private:
        string name;
        string origin;
        time_t expiryDate;
        int quantity;
        int price;

    public:
        Fruit(string name, string origin, time_t expiryDate = 0, int quantity = 0, int price = 0);

        Fruit(string name, string origin, const string &expiryDate, int quantity = 0, int price = 0);

        [[nodiscard]] string getName() const;

        [[nodiscard]] string getOrigin() const;

        [[nodiscard]] time_t getExpiryDate() const;

        [[nodiscard]] string getExpiryDateStr() const;

        [[nodiscard]] int getQuantity() const;

        [[nodiscard]] int getPrice() const;

        void setName(const string &_name);

        void setOrigin(const string &_origin);

        void setExpiryDate(time_t _expiryDate);

        void setExpiryDate(const string &_expiryDate);

        void setQuantity(int quantity);

        void setPrice(int price);

        bool operator==(const Fruit &other) const;

        bool operator!=(const Fruit &other) const;

        void print() const;

        [[nodiscard]] string toString() const;

        [[nodiscard]] vector<string> toList() const;
    };

}
#endif //LAB4_FRUIT_H
