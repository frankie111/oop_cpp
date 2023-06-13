#ifndef MODELE_P2_H
#define MODELE_P2_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Location {
public:
    string id;
    int points;
    int translation;
    int rotation;
};

class Path {
public:
    string name;
    string element;
    int time;
    vector<Location> locations;
    int flip;
    int rotate;

    bool operator==(const Path &other) const {
        return name == other.name;
    }

};

class Run {
public:
    vector<Path> paths;
    int fixedTimes;
    int numCycles;
    int times;
    int power;
    int powerFraction;

    void addPath(const Path &path) {
        paths.push_back(path);
    }

    void addLocation(const Path &path, const Location &loc) {
        auto it = std::find(paths.begin(), paths.end(), path);
        if (it != paths.end()) {
            it->locations.push_back(loc);
        }
    };
};

#endif //MODELE_P2_H
