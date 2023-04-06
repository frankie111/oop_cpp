#include <iostream>
#include <cassert>
#include "L3_Rautoiu_Mircea_DSM.h"
#include "L3_Rautoiu_Mircea_DSM.cpp"

void testInit() {
    cout << "Test Init" << endl;
    DSM<int> dsm(5);
    assert(dsm.get_size() == 5);

    string elems[] = {"car", "engine", "wheels"};
    DSM<int> dsm1(elems, 3);
    assert(dsm1.get_size() == 3);

    const DSM<int> dsm2(dsm);
    assert(dsm2.get_size() == 5);
}

void testAdd() {
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 3);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("wheels", "body", 2);

//    assert(dsm.get_size() == 3);

}

void testSetElementName() {

}

void testAddLink() {

}

void testDeleteLink() {

}

void testHasLink() {

}

void testLinkWeight() {

}

void testCountToLinks() {

}

void testCountFromLinks() {

}

void testCountAllLinks() {

}

void testAll() {
    testInit();
    testAdd();
//    testSetElementName();
//    testAddLink();
//    testDeleteLink();
//    testHasLink();
//    testLinkWeight();
//    testCountToLinks();
//    testCountFromLinks();
//    testCountAllLinks();

}

int main() {
    testAll();
}
