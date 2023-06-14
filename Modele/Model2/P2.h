#ifndef MODELE_P2_H
#define MODELE_P2_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T part(T a, T b) {
    return a / (1 + b);
}

int main() {
    vector<float> s = {7.3, 4.6, 2.8, 8.2, 6.4, 1.9, 9.1};
    sort(s.begin(), s.end(), [](float a, float b) {
        int intrA = (int) a;
        int intrB = (int) b;

        return a - (float) intrA > b - (float) intrB;

    });

    for (auto a: s) {
        cout << a << ' ';
    }
}

#endif //MODELE_P2_H
