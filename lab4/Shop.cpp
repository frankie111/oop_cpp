#include <iostream>
#include "UI/FruitUI.h"

using namespace std;
using namespace ui;

int main() {
    unique_ptr<FruitRepo> repoPtr = make_unique<FruitRepo>();
    unique_ptr<FruitController> controllerPtr = make_unique<FruitController>(std::move(repoPtr));
    FruitUI ui(std::move(controllerPtr));

    ui.mainMenu();

    system("pause");
}
