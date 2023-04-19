#include "Fruit.h"


Fruit::Fruit(string name,
             string origin,
             time_t expiryDate,
             int quantity,
             int price) : name(std::move(name)),
                          origin(std::move(origin)),
                          expiryDate(
                                  expiryDate),
                          quantity(quantity),
                          price(price) {}

string Fruit::getName() const {
    return name;
}

string Fruit::getOrigin() const {
    return origin;
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

void Fruit::setExpiryDate(time_t _expiryDate) {
    expiryDate = _expiryDate;
}

void Fruit::setExpiryDate(const string &_expiryDate) {
    expiryDate = strToTime(_expiryDate);
}

void Fruit::setQuantity(int _quantity) {
    quantity = _quantity;
}

bool Fruit::operator==(const Fruit &other) {
    return name == other.name && origin == other.origin;
}

void Fruit::print() const {
    cout << name << ' ' << origin << ' ' << timeToStr(expiryDate) << ' ' << quantity << ' ' << price;
}

string Fruit::toString() const {
    return name + ' ' + origin + ' ' + timeToStr(expiryDate) + ' ' + to_string(quantity) + ' ' + to_string(price);
}

vector<string> Fruit::toList() const {
    vector<string> details = {name, origin, timeToStr(expiryDate), to_string(quantity), to_string(price)};
    return details;
}
