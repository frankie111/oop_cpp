#ifndef MODELE_P5_H
#define MODELE_P5_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class LibMaterial {
private:
    string id{};
    string author{};

protected:
    bool available{};
public:
    LibMaterial() = default;

    virtual void changeState() = 0;
};

class Text : public LibMaterial {
private:
    int numPage;
    int numWords;

public:
    Text(int _numPage, int _numWords) : LibMaterial() {
        numPage = _numPage;
        numWords = _numWords;
    }

    void changeState() override {
        available = !available;
    }
};

class Audio : public LibMaterial {
public:
    Audio(int _duration, const string& _chord) : LibMaterial() {
        duration = _duration;
        chord = _chord;
    }

    void changeState() override {
        available = !available;
    }

private:
    int duration;
    string chord;
};

class Video : public LibMaterial {
public:
    Video(int _duration, int _quality) : LibMaterial() {
        duration = _duration;
        quality = _quality;
    }

    void changeState() override {
        available = !available;
    }
private:
    int duration;
    int quality;
};

#endif //MODELE_P5_H
