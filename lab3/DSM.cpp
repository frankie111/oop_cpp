#include "DSM.h"

DSM::DSM(int elemnentCount) : cap{1},
                              size{0},
                              elementNames{new string[1]},
                              matrix{new int *[1]} {
    matrix[0] = new int[1];
}

void DSM::resize() {
    if (size == cap)
        cap *= GROWTH_FACTOR;
    else if (size < cap / (GROWTH_FACTOR * 2))
        cap /= GROWTH_FACTOR;
    else return;

    //resize elementNames:
    auto *newElementNames = new string[cap];
    std::copy(elementNames, elementNames + size, newElementNames);
    delete[] elementNames;
    elementNames = newElementNames;

    //resize matrix:


}

DSM::DSM(string elementNames, int elementCount) {

}

DSM::DSM(const DSM &other) {

}

int DSM::get_size() const {
    return size;
}

string DSM::getName(int index) const {
    return std::string();
}

void DSM::setElementName(int index, string elementName) {

}

void DSM::addLink(string fromElement, string toElement, int weight) {

}

void DSM::deleteLink(string fromElement, string toElement) {

}

bool DSM::hasLink(string fromELement, string toElement) {
    return false;
}

int DSM::linkWeight(string fromElement, string toElement) {
    return 0;
}

int DSM::countToLinks(string elementName) {
    return 0;
}

int DSM::countFromLinks(string elementName) {
    return 0;
}

int DSM::countAllLinks() {
    return 0;
}

DSM::~DSM() {

}
