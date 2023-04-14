#include <iostream>
#include "UI/FruitUI.h"
#include "Controller/FruitController.h"
#include "Repository/FruitRepo.h"

int main() {
    FruitRepo repo;
    FruitController controller(repo);
    FruitUI ui(controller);

    ui.mainMenu();

    system("pause");
}
