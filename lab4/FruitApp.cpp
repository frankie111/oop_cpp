#include <iostream>
#include "UI/FruitUI.h"

int main() {
    FruitRepo repo;
    FruitController controller(repo);
    FruitUI ui(controller);

    ui.mainMenu();

    system("pause");
}
