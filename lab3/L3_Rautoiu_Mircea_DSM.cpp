#include "L3_Rautoiu_Mircea_DSM.h"


/**
 * Constructor
 * Sets initial capacity to elementCount + 1
 * @tparam T type of matrix weights
 * @param elementCount number of initial elements
 */
template<typename T>
DSM<T>::DSM(int elementCount) {
    if (elementCount < 0)
        throw invalid_argument("DSM(): element count cannot be negative");

    capacity = elementCount + 1;
    size = 0;
    elementNames = new string[capacity];

    // init matrix
    matrix = new T *[capacity];
    for (int i = 0; i < capacity; i++)
        matrix[i] = new T[capacity]{};
}

/**
 * Constructor
 * @tparam T type of matrix weights
 * @param elementCount number of initial elements
 * @param elementNames initial list of elements
 */
template<typename T>
DSM<T>::DSM(string elementNames[], int elementCount) {
    if (elementCount < 0)
        throw invalid_argument("DSM(): element count cannot be negative");

    capacity = elementCount * 2;
    size = elementCount;
    this->elementNames = new string[capacity];

    //Copy names of elements
    std::copy(elementNames, elementNames + size, this->elementNames);

    // init matrix
    matrix = new T *[capacity];

    for (int i = 0; i < capacity; i++)
        matrix[i] = new T[capacity]{};

}

/**
 * Copy Constructor
 * */
template<typename T>
DSM<T>::DSM(const DSM<T> &other) {

    // Deallocate memory if this is not a new object
    if (capacity != 0) {
        delete[] elementNames;
        for (int i = 0; i < capacity; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    // Copy all data from other
    capacity = other.capacity;
    size = other.size;
    elementNames = new string[capacity];
    matrix = new T *[capacity];

    //init matrix
    for (int i = 0; i < capacity; i++)
        matrix[i] = new T[capacity]{};

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
template<typename T>
void DSM<T>::resize() {
    if (size == capacity)
        capacity *= GROWTH_FACTOR;
    else return;

    //    else if (size < capacity / (GROWTH_FACTOR * 2))
    //        capacity /= GROWTH_FACTOR;

    //resize elementNames:
    auto *newElementNames = new string[capacity];
    std::copy(elementNames, elementNames + size, newElementNames);
    delete[] elementNames;
    elementNames = newElementNames;

    //init new matrix
    T **newMatrix = new T *[capacity];
    for (int i = 0; i < capacity; i++)
        newMatrix[i] = new T[capacity];

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
template<typename T>
int DSM<T>::get_size() const {
    return size;
}

/**
 * Get name of element at specific index
 * @param index to be searched at
 * @returns name of element at index
 * @throws out_of_range if index is out of bounds
 */
template<typename T>
string DSM<T>::getName(int index) const {
    if (!isIndexValid(index))
        throw out_of_range("DSM::getName(): Index out of range for index " + to_string(index));

    return elementNames[index];
}


/**
 * Set element name at specific index
 * @param index of element to modify
 * @param elementName name to be set
 * @throws out_of_range if index is out of bounds
 */
template<typename T>
void DSM<T>::setElementName(int index, const string &elementName) {
    if (!isIndexValid(index))
        throw out_of_range("DSM::SetElementName(): Index out of range for index " + to_string(index));

    elementNames[index] = elementName;
}

/**
 * Add a new link to the DSM.
 * \n
 * Add new elements if names not found
 * @param fromElement first element in relation
 * @param toElement second element in relation
 * @param weight of relation
 */
template<typename T>
void DSM<T>::addLink(string fromElement, string toElement, T weight) {
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
 * @param fromElement first element in relation
 * @param toElement second element in relation
 * @returns true if link was deleted, false otherwise
 */
template<typename T>
bool DSM<T>::deleteLink(string fromElement, string toElement) {
    int firstIndex = findElementName(fromElement);
    int secondIndex = findElementName(toElement);

    if (firstIndex == -1 || secondIndex == -1)
        return false;

    matrix[firstIndex][secondIndex] = 0;
    return true;
}

/**
 * @returns true if there is a link between fromElement and toElementS
 * @param fromElement first element in relation
 * @param toElement second element in relation
 */
template<typename T>
bool DSM<T>::hasLink(string fromElement, string toElement) {
    return linkWeight(fromElement, toElement);
}

/**
 * @returns link weight between fromElement and toElement
 * @param fromElement first element in relation
 * @param toElement second element in relation
 */
template<typename T>
T DSM<T>::linkWeight(string fromElement, string toElement) {
    int firstIndex = findElementName(fromElement);
    int secondIndex = findElementName(toElement);

    return matrix[firstIndex][secondIndex];
}

/**
 * @returns number of links to elementName
 * @param elementName name of element to search for as the second element in a relation
 */
template<typename T>
int DSM<T>::countToLinks(string elementName) {
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
 * @param elementName name of element to search for as the first element in a relation
 */
template<typename T>
int DSM<T>::countFromLinks(string elementName) {
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
template<typename T>
int DSM<T>::countAllLinks() {
    int ct = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ct += matrix[i][j] > 0;

    return ct;
}

/**
 * @returns true if index is valid, false otherwise
 * @param index to be queried
 */
template<typename T>
bool DSM<T>::isIndexValid(int index) const {
    return index < size && index >= 0;
}

/**
 * @returns index of element or -1 if it doesn't exist
 * @param name to search for
 */
template<typename T>
int DSM<T>::findElementName(string &name) const {
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
template<typename T>
int DSM<T>::addElementName(string &name) {
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
template<typename T>
void DSM<T>::printMatrix() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << "  ";
        cout << endl;
    }
}

/**
 * Prints the element names in the DSM
 */
template<typename T>
void DSM<T>::printElements() const {
    for (int i = 0; i < size; i++) {
        cout << elementNames[i] << ' ';
    }
}


/**
 * Destructor
 */
template<typename T>
DSM<T>::~DSM() {
    delete[] elementNames;
    for (int i = 0; i < capacity; i++)
        delete[] matrix[i];
    delete[] matrix;
}
