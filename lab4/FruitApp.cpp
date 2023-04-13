#include <iostream>
#include <cstdlib>
#include "UI/FruitUI.h"
#include "Controller/FruitController.h"
#include "Repository/FruitRepo.h"

int main() {
    FruitRepo repo;
    FruitController controller;
    FruitUI ui(controller);

    ui.mainMenu();

    system("pause");
}
