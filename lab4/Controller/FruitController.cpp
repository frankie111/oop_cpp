#include "FruitController.h"

FruitController::FruitController(FruitRepo &_repo) {
    repo = &_repo;
}

bool FruitController::add(const string &name, const string &origin, const time_t &expiryDate, int quantity, int price) {
    return false;
}

bool FruitController::remove(const string &name, const string &origin) {
    return false;
}
