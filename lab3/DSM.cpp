#include "DSM.h"

/**
 * Constructor
 * */
DSM::DSM(int elementCount) : cap{elementCount + 1},
                             size{elementCount},
                             elementNames{new string[cap]},
                             matrix{new int *[cap]} {
    // init matrix
    for (int i = 0; i < cap; i++)
        matrix[i] = new int[cap]{};
}

/**
 * Constructor
 * */
DSM::DSM(string elementNames[], int elementCount) : cap{elementCount + 1},
                                                    size{elementCount},
                                                    elementNames{elementNames},
                                                    matrix{new int *[cap]} {
    // init matrix
    for (int i = 0; i < cap; i++)
        matrix[i] = new int[cap]{};
}

/**
 * Copy Constructor
 * */
DSM::DSM(const DSM &other) : cap{other.cap},
                             size{other.size} {
    elementNames = new string[cap];

    //init matrix
    matrix = new int *[cap];
    for (int i = 0; i < cap; i++)
        matrix[i] = new int[cap]{};

    //copy elementNames
    std::copy(other.elementNames, other.elementNames + size, this->elementNames);

    //copy matrix
    for (int i = 0; i < size; i++)
        std::copy(other.matrix[i], other.matrix[i] + size, this->matrix[i]);
}

/**
 * Auto resize elementNames array and matrix when capacity is reached.
 *\n
 * capacity is multiplied by GROWTH_FACTOR
 */
void DSM::resize() {
    if (size == cap)
        cap *= GROWTH_FACTOR;
//    else if (size < cap / (GROWTH_FACTOR * 2))
//        cap /= GROWTH_FACTOR;
    else return;

    //resize elementNames:
    auto *newElementNames = new string[cap];
    std::copy(elementNames, elementNames + size, newElementNames);
    delete[] elementNames;
    elementNames = newElementNames;

    //resize matrix:
    auto **newMatrix = new int *[cap];
    for (int i = 0; i < cap; i++)
        newMatrix[i] = new int[cap];

    //copy elements to newMatrix:
    for (int i = 0; i < size; i++)
        std::copy(matrix[i], matrix[i] + size, newMatrix[i]);

    //delete old matrix:
    for (int i = 0; i < size; i++)
        delete[]matrix[i];
    delete[]matrix;

    //reassign matrix pointer:
    matrix = newMatrix;
}

/**
 * @returns the size of elementNames array = size of matrix
 */
int DSM::get_size() const {
    return size;
}

/**
 * Get name of element at specific index
 * @param index to be searched at
 * @returns name of element at index
 * @throws out_of_range if index is out of bounds
 */
string DSM::getName(int index) const {
    if (!isIndexValid(index))
        throw out_of_range("getName(): Index out of range for index " + to_string(index));

    return elementNames[index];
}

/**
 * Set element name at specific index
 * @param index
 * @param elementName
 * @throws out_of_range if index is out of bounds
 */
void DSM::setElementName(int index, string &elementName) {
    if (!isIndexValid(index))
        throw out_of_range("getName(): Index out of range for index " + to_string(index));

    elementNames[index] = elementName;
}

/**
 * Add a new link to the DSM.
 * \n
 * Add new elements if names not found
 * @param fromElement
 * @param toElement
 * @param weight
 */
void DSM::addLink(string fromElement, string toElement, int weight) {
    int firstIndex = findElementName(fromElement);
    int secondIndex = findElementName(toElement);

    if (firstIndex == -1)
        firstIndex = addElementName(fromElement);

    if (secondIndex == -1)
        secondIndex = addElementName(toElement);

    matrix[firstIndex][secondIndex] = weight;
}

/**
 * Delete a link from DSM if existent
 * @param fromElement
 * @param toElement
 * @returns true if link was deleted, false otherwise
 */
bool DSM::deleteLink(string fromElement, string toElement) {
    int firstIndex = findElementName(fromElement);
    int secondIndex = findElementName(toElement);

    if (firstIndex == -1 || secondIndex == -1)
        return false;

    matrix[firstIndex][secondIndex] = 0;
    return true;
}

/**
 * @returns true if there is a link between fromElement and toElementS
 * @param fromElement
 * @param toElement
 */
bool DSM::hasLink(string &fromElement, string &toElement) {
    return linkWeight(fromElement, toElement);
}

/**
 * @returns link weight between fromElement and toElement
 * @param fromElement
 * @param toElement
 */
int DSM::linkWeight(string fromElement, string toElement) {
    int firstIndex = findElementName(fromElement);
    int secondIndex = findElementName(toElement);

    return matrix[firstIndex][secondIndex];
}

/**
 * @returns number of links to elementName
 * @param elementName
 */
int DSM::countToLinks(string elementName) {
    int index = findElementName(elementName);
    if (index == -1)
        return -1;

    int ct = 0;
    for (int row = 0; row < size; row++)
        ct += matrix[row][index] > 0;

    return ct;
}

/**
 * @returns number of links from elementName
 * @param elementName
 */
int DSM::countFromLinks(string elementName) {
    int index = findElementName(elementName);
    if (index == -1)
        return -1;

    int ct = 0;
    for (int col = 0; col < size; col++)
        ct += matrix[index][col] > 0;

    return ct;
}

/**
 * @returns total number of links in DSM
 */
int DSM::countAllLinks() {
    int ct = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ct += matrix[i][j] > 0;

    return ct;
}

/**
 * @returns true if index is valid, false otherwise
 * @param index
 */
bool DSM::isIndexValid(int index) const {
    return index < size && index >= 0;
}

/**
 * @returns index of element or -1 if it doesn't exist
 * @param name to search for
 */
int DSM::findElementName(string &name) const {
    for (int i = 0; i < size; i++)
        if (elementNames[i] == name)
            return i;

    return -1;
}

/**
 * Add a new element
 * @param name of element to be added
 * @returns index of element
 */
int DSM::addElementName(string &name) {
    int index = findElementName(name);

    // If element exists return it's index
    if (index != -1)
        return index;

    resize();
    elementNames[size] = name;
    size++;
    return size - 1;
}

/**
 * Prints the DSM
 */
void DSM::printMatrix() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

/**
 * Destructor
 */
DSM::~DSM() {
    delete[] elementNames;
    for (int i = 0; i < cap; i++)
        delete[] matrix[i];
    delete[] matrix;
}
