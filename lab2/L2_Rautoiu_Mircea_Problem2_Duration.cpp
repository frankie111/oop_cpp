//
// Created by Mircea on 3/15/2023.
//

#include "L2_Rautoiu_Mircea_Problem2_Duration.h"
#include <stdexcept>
#include <utility>
#include <sstream>

Duration::Duration(float value, string unit) {
    this->value = value;
    this->unit = std::move(unit);
}

float Duration::get_value() const {
    return value;
}

string Duration::get_unit() const {
    return unit;
}

Duration Duration::add(const Duration &other) const {
    if (unit != other.unit)
        throw std::invalid_argument("add(): Incompatible unit types " + unit + " != " + other.unit);
    return {value + other.value, unit};
}

Duration Duration::subtract(const Duration &other) const {
    if (unit != other.unit)
        throw std::invalid_argument("add(): Incompatible unit types " + unit + " != " + other.unit);
    return {value - other.value, unit};
}

void Duration::scale(float factor) {
    value *= factor;
}

void Duration::divide(float factor){
    value /= factor;
}

/**
 * Return a string representation of Duration
 * @param precision number of decimal points to be displayed for value
 */
string Duration::text(int precision) const{
    stringstream stream;
    //Set precision
    stream.precision(precision);
    stream << fixed;

    //Convert float to string
    stream << value;
    string str_val = stream.str();

    return str_val + " " + unit;
}

/**
 * Compare this object with another Duration object
 *
 * @returns 0 if this == other, -1 if this < other, 1 if this > other
 */
int Duration::compare(const Duration &other) const{
    if (unit != other.unit)
        throw std::invalid_argument("add(): Incompatible unit types " + unit + " != " + other.unit);
    if (value < other.value)
        return -1;
    else if (value == other.value)
        return 0;
    else
        return 1;
}

Duration Duration::operator+(const Duration &other) const {
    return add(other);
}

Duration Duration::operator-(const Duration &other) const {
    return subtract(other);
}

Duration Duration::operator*(float factor) const{
    float res_val = value * factor;
    return {res_val, unit};
}

Duration Duration::operator/(float factor) const{
    float res_val = value / factor;
    return {res_val, unit};
}

Duration Duration::convert(const string &new_unit) const {
    float factor = 1.0;
    if (unit == "s") {
        if (new_unit == "min")
            factor = 1.0f / 60.0f;
        else if (new_unit == "h")
            factor = 1.0f / (60.0f * 60.0f);
    } else if (unit == "min") {
        if (new_unit == "s")
            factor = 60.0;
        else if (new_unit == "h")
            factor = 1.0 / 60.0;
    } else if (unit == "h") {
        if (new_unit == "s")
            factor = 60.0 * 60.0;
        else if (new_unit == "min")
            factor = 60.0;
    }

    return {value * factor, new_unit};
}
