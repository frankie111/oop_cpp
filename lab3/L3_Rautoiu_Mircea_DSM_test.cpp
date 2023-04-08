#include <iostream>
#include <cassert>
#include "L3_Rautoiu_Mircea_DSM.h"
#include "L3_Rautoiu_Mircea_DSM.cpp"

void testConstructor1() {
    cout << "\tConstructor 1" << endl;
    DSM<int> dsm(2);
    dsm.addLink("car", "engine", 2);
    dsm.addLink("car", "body", 3);
    dsm.addLink("steering", "wheels", 2);
    assert(dsm.get_size() == 5);
}

void testConstructor2() {
    cout << "\tConstructor 2" << endl;
    string elems[] = {"car", "engine", "wheels"};
    DSM<int> dsm1(elems, 3);
    assert(dsm1.get_size() == 3);
}

void testCopyConstructor() {
    cout << "\tCopy Constructor" << endl;
    DSM<int> dsm(2);
    dsm.addLink("car", "engine", 2);
    dsm.addLink("car", "body", 3);
    dsm.addLink("steering", "wheels", 2);

    DSM<int> dsm_copy(dsm);
    assert(dsm_copy.get_size() == 5);
}

void testInit() {
    cout << "Test Init" << endl;
    testConstructor1();
    testConstructor2();
    testCopyConstructor();
}


void testAdd() {
    cout << "Test Add" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("wheels", "body", 2);

    assert(dsm.get_size() == 4);
}

void testSetElementName() {
    cout << "Test Set Element Name" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.setElementName(0, "body");
    assert(dsm.getName(0) == "body");
}

void testDeleteLink() {
    cout << "Test Delete Link" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("wheels", "body", 2);

    dsm.deleteLink("car", "engine");
    assert(dsm.hasLink("car", "engine") == false);
}

void testHasLink() {
    cout << "Test Has Link" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("wheels", "body", 2);

    assert(dsm.hasLink("car", "engine"));
    assert(dsm.hasLink("wheels", "body"));
    assert(dsm.hasLink("body", "wheels") == false);
}

void testLinkWeight() {
    cout << "Test Link Weight" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("wheels", "body", 2);

    assert(dsm.linkWeight("car", "engine") == 3);
    assert(dsm.linkWeight("wheels", "body") == 2);
}

void testCountToLinks() {
    cout << "Test Count To Links" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("wheels", "engine", 2);
    dsm.addLink("engine", "body", 4);

    assert(dsm.countToLinks("engine") == 2);
    assert(dsm.countToLinks("body") == 1);
    assert(dsm.countToLinks("car") == 0);
}

void testCountFromLinks() {
    cout << "Test Count From Links" << endl;
    string elems[] = {"car", "engine"};
    DSM<int> dsm(elems, 2);

    dsm.addLink("car", "engine", 3);
    dsm.addLink("car", "body", 2);
    dsm.addLink("engine", "body", 4);

    assert(dsm.countFromLinks("car") == 2);
    assert(dsm.countFromLinks("engine") == 1);
    assert(dsm.countFromLinks("body") == 0);
}

void testCountAllLinks() {

}

void testAll() {
    testInit();
    testAdd();
    testSetElementName();
    testDeleteLink();
    testHasLink();
    testLinkWeight();
    testCountToLinks();
    testCountFromLinks();
    testCountAllLinks();

}

int main() {
    testAll();
    system("pause");
}
