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

    ~DSM();

public:
    DSM(int elemnentCount);

    DSM(string elementNames, int elementCount);

    DSM(const DSM &other);

    int get_size() const;

    string getName(int index) const;

    void setElementName(int index, string elementName);

    void addLink(string fromElement, string toElement, int weight);

    void deleteLink(string fromElement, string toElement);

    // Analyse Methoden

    bool hasLink(string fromELement, string toElement);

    int linkWeight(string fromElement, string toElement);

    int countToLinks(string elementName);

    int countFromLinks(string elementName);

    int countAllLinks();
};


#endif //LAB3_DSM_H
