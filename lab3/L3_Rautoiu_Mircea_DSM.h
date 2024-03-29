#ifndef LAB3_L3_RAUTOIU_MIRCEA_DSM_H
#define LAB3_L3_RAUTOIU_MIRCEA_DSM_H

#include <iostream>

using namespace std;

template<typename T>
class DSM {
private:
    static const int GROWTH_FACTOR = 2;
    int capacity{0};
    int size{0};

    //dynamic array for element names;
    string *elementNames{};

    //dsm
    T **matrix;

    void resize();

    [[nodiscard]] bool isIndexValid(int index) const;

    int findElementName(string &name) const;

    int addElementName(string &name);

public:

    ~DSM();

    explicit DSM(int elementCount);

    DSM(string elementNames[], int elementCount);

    DSM(const DSM &other);

    [[nodiscard]] int get_size() const;

    [[nodiscard]] string getName(int index) const;

    void setElementName(int index, const string &elementName);

    void addLink(string fromElement, string toElement, T weight);

    bool deleteLink(string fromElement, string toElement);

    // Analyse Methoden

    [[nodiscard]] bool hasLink(string fromElement, string toElement);

    T linkWeight(string fromElement, string toElement);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();

    void printMatrix() const;

    void printElements() const;
};

#endif //LAB3_L3_RAUTOIU_MIRCEA_DSM_H
