#include <iostream>
#include <cassert>
#include "DSM.h"

int main() {
    string names[3] = {"car", "wheels", "engine"};
    DSM dsm1(names, 3);
    dsm1.addLink("car", "engine", 2);
    dsm1.addLink("wheels", "engine", 3);
    dsm1.printMatrix();

    cout << endl;

    dsm1.addLink("engine", "body", 2);
    dsm1.printMatrix();

    cout << endl;

    dsm1.deleteLink("car", "engine");
    dsm1.printMatrix();
}
