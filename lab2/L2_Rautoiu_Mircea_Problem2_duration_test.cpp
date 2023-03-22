#include <iostream>
#include "L2_Rautoiu_Mircea_Problem2_Duration.h"
#include <cassert>
#include <cmath>

using namespace std;

/**
 * Checks if x epsilon equals y
 *
 * Checks if abs(x-y) < epsilon
 * @param x, y float numbers to be compared
 * @param epsilon precision of comparison
 * @returns
 */
bool epsilon_equals(const float x, const float y, const float epsilon = 0.001f) {
    if (fabs(x - y) < epsilon)
        return true;
    return false;
}

void test_init_get() {
    cout << "Test Init+Get" << endl;
    Duration dur(5.5, "min");
    assert(dur.get_value() == 5.5);
    assert(dur.get_unit() == "min");
}

void test_add() {
    cout << "Test Add" << endl;
    Duration dur(5.5, "min");
    Duration dur2(2.0, "min");
    Duration dur3(1.5, "h");

    assert(dur.add(dur2).get_value() == 5.5 + 2.0);

    try {
        Duration rez = dur.add(dur3);
        assert(false);
    }
    catch (exception &) {
        assert(true);
    }
}

void test_subtract() {
    cout << "Test Subtract" << endl;
    Duration dur(5.5, "min");
    Duration dur2(2.0, "min");
    Duration dur3(1.5, "h");

    assert(dur.subtract(dur2).get_value() == 5.5 - 2.0);

    try {
        Duration rez = dur.subtract(dur3);
        assert(false);
    }
    catch (exception &) {
        assert(true);
    }
}

void test_scale() {
    cout << "Test Scale" << endl;
    Duration dur(5.5, "min");
    float scale_factor = 1.23;
    dur.scale(scale_factor);
    assert(epsilon_equals(dur.get_value(), 5.5 * scale_factor));
}

void test_divide() {
    cout << "Test Divide" << endl;
    Duration dur(5.5, "min");
    float div_factor = 1.837;
    dur.divide(div_factor);
    assert(epsilon_equals(dur.get_value(), 5.5 / div_factor));
}

void test_text() {
    cout << "Test Text" << endl;
    Duration dur(5.12, "min");
    string text = "5.12 min";
    assert(dur.text() == text);
}

void test_compare() {
    cout << "Test Compare" << endl;
    Duration dur(5.5, "min");
    Duration dur2(2.0, "min");
    Duration dur3(2.0, "min");
    Duration dur4(1.5, "h");

    assert(dur.compare(dur2) == 1);
    assert(dur2.compare(dur) == -1);
    assert(dur2.compare(dur3) == 0);

    try {
        dur.compare(dur4);
        assert(false);
    }
    catch (invalid_argument &) {
        assert(true);
    }
}

void test_convert() {
    cout << "Test Convert" << endl;
    Duration dur(120, "s");

    Duration converted = dur.convert("min");
    assert(epsilon_equals(converted.get_value(), 2) && converted.get_unit() == "min");

    converted = dur.convert("h");
    assert(epsilon_equals(converted.get_value(), 120.0 / 3600.0) && converted.get_unit() == "h");

    Duration dur2(360, "min");

    converted = dur2.convert("s");
    assert(epsilon_equals(converted.get_value(), 360.0 * 60.0) && converted.get_unit() == "s");

    converted = dur2.convert("h");
    assert(epsilon_equals(converted.get_value(), 360.0 / 60.0) && converted.get_unit() == "h");
}

void test_all() {
    test_init_get();
    test_add();
    test_subtract();
    test_scale();
    test_divide();
    test_text();
    test_compare();
    test_convert();
}

int main() {
    test_all();

    float d1, d2, scale;
    string u1, u2;
    cout << "Enter first duration: ";
    cin >> d1;
    cout << "Enter first unit: ";
    cin >> u1;

    cout << "Enter second duration: ";
    cin >> d2;
    cin.clear();
    cout << "Enter second unit: ";
    cin >> u2;

    cout << "Enter a scaling factor: ";
    cin >> scale;

    Duration dur1(d1, u1), dur2(d2, u2);

    cout << "\n" << dur1.text() << " + " << dur2.text() << " = " << dur1.add(dur2).text() << endl;
    cout << dur1.text() << " - " << dur2.text() << " = " << dur1.subtract(dur2).text();

    cout << "\n" << dur1.text() << " * " << scale << " = ";
    dur1.scale(scale);
    cout << dur1.text();

    cout << "\n" << dur2.text() << " * " << scale << " = ";
    dur2.scale(scale);
    cout << dur2.text() << endl;

    int cmp = dur1.compare(dur2);
    if (cmp == 0)
        cout << dur1.text() << " == " << dur2.text();
    else if (cmp == -1)
        cout << dur1.text() << " < " << dur2.text();
    else if (cmp == 1)
        cout << dur1.text() << " > " << dur2.text();
}