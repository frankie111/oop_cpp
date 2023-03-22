//
// Created by Mircea on 3/15/2023.
//

#ifndef LAB2_L2_RAUTOIU_MIRCEA_PROBLEM2_DURATION_H
#define LAB2_L2_RAUTOIU_MIRCEA_PROBLEM2_DURATION_H

#include <string>

using namespace std;

class Duration {
private:
    float value{};
    string unit;
public:
    Duration(float value, string unit);

    [[nodiscard]] float get_value() const;

    [[nodiscard]] string get_unit() const;

    [[nodiscard]] Duration add(const Duration &other) const;

    [[nodiscard]] Duration subtract(const Duration &other) const;

    void scale(float factor);

    void divide(float factor);

    [[nodiscard]] string text(int precision = 2) const;

    [[nodiscard]] int compare(const Duration &other) const;

    Duration operator+(Duration const &other) const;

    Duration operator-(Duration const &other) const;

    Duration operator*(float factor) const;

    Duration operator/(float factor) const;

    [[nodiscard]] Duration convert(const string &new_unit) const;
};


#endif //LAB2_L2_RAUTOIU_MIRCEA_PROBLEM2_DURATION_H
