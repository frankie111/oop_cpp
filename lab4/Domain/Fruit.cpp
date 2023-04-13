#include "Fruit.h"

string Fruit::getName() const {
    return name;
}

string Fruit::getOrigin() const {
    return origin;
}

string Fruit::getType() const {
    return type;
}

string Fruit::getExpiryDateStr() const {
    return ctime(&expiryDate);
}

int Fruit::getPrice() const {
    return price;
}

int Fruit::getQuantity() const {
    return quantity;
}

void Fruit::setPrice(int _price) {
    if (price < 0)
        throw invalid_argument("Fruit::setPrice(): price cannot be negative");

    price = _price;
}

void Fruit::setName(const string &_name) {
    if (_name.empty())
        throw invalid_argument("Fruit::setName(): name cannot be an empty string");

    name = _name;
}

void Fruit::setOrigin(const string &_origin) {
    if (_origin.empty())
        throw invalid_argument("Fruit::setOrigin(): origin cannot be an empty string");

    origin = _origin;
}

void Fruit::setType(const string &_type) {
    if (_type.empty())
        throw invalid_argument("Fruit::setType(): type cannot be an empty string");

    type = _type;
}

void Fruit::setExpiryDate(time_t _expiryDate) {
    expiryDate = _expiryDate;
}

void Fruit::setExpiryDate(const string &_expiryDate) {

}

void Fruit::setQuantity(int _quantity) {
    quantity = _quantity;
}