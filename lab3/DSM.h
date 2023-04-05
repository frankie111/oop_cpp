#ifndef LAB3_DSM_H
#define LAB3_DSM_H

#include <iostream>

using namespace std;


class DSM {
private:
    const int GROWTH_FACTOR = 2;
    int cap;
    int size;

    //dynamic array for element names;
    string *elementNames;

    //dsm
    int **matrix;

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

    void setElementName(int index, string &elementName);

    void addLink(string fromElement, string toElement, int weight);

    bool deleteLink(string fromElement, string toElement);

    // Analyse Methoden

    bool hasLink(string &fromElement, string &toElement);

    int linkWeight(string fromElement, string toElement);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();

    void printMatrix() const;
};


#endif //LAB3_DSM_H
