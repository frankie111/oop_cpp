#include <iostream>
#include "L2_Rautoiu_Mircea_Problem2_Duration.h"
#include <cassert>
#include <cmath>

using namespace std;

bool epsilon_equals(float x, float y, float epsilon = 0.001f){
    if(fabs(x - y) < epsilon)
        return true; //they are same
    return false; //they are not same
}

void test_init_get() {
    Duration dur = Duration(5.5, "min");
    assert(dur.get_value() == 5.5);
    assert(dur.get_unit() == "min");
}

void test_add() {
    Duration dur = Duration(5.5, "min");
    Duration dur2 = Duration(2.0, "min");
    Duration dur3 = Duration(1.5, "h");

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
    Duration dur = Duration(5.5, "min");
    Duration dur2 = Duration(2.0, "min");
    Duration dur3 = Duration(1.5, "h");

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
    Duration dur = Duration(5.5, "min");
    float scale_factor = 1.23;
    dur.scale(scale_factor);
    assert(epsilon_equals(dur.get_value(), 5.5 * scale_factor));
}

void test_divide(){
    Duration dur = Duration(5.5, "min");
    float div_factor = 1.837;
    dur.divide(div_factor);
    assert(epsilon_equals(dur.get_value(), 5.5 / div_factor));
}

void test_text(){
    Duration dur = Duration(5.12, "min");
    string text = "5.12 min";
    assert(dur.text() == text);
}

void test_compare(){

}

void test_all() {
    test_init_get();
    test_add();
    test_subtract();
    test_scale();
    test_divide();
    test_text();
    test_compare();
}

int main() {
    test_all();

//    float d1, d2, scale;
//    string u1, u2;
//    cout << "Enter first duration: ";
//    cin >> d1;
//    cout << "Enter first unit: ";
//    cin >> u1;
//
//    cout << "Enter second duration: ";
//    cin >> d2;
//    cin.clear();
//    cout << "Enter second unit: ";
//    cin >> u2;
//
//    cout << "Enter a scaling factor: ";
//    cin >> scale;
//
//    Duration dur1(d1, u1), dur2(d2, u2);
//
//    cout << "\n" << dur1.text() << " + " << dur2.text() << " = " << dur1.add(dur2).text() << endl;
//    cout << dur1.text() << " - " << dur2.text() << " = " << dur1.subtract(dur2).text();
//
//    cout << "\n" << dur1.text() << " * " << scale << " = ";
//    dur1.scale(scale);
//    cout << dur1.text();
//
//    cout << "\n" << dur2.text() << " * " << scale << " = ";
//    dur2.scale(scale);
//    cout << dur2.text() << endl;
//
//    int cmp = dur1.compare(dur2);
//    if (cmp == 0)
//        cout << dur1.text() << " == " << dur2.text();
//    else if (cmp == -1)
//        cout << dur1.text() << " < " << dur2.text();
//    else if (cmp == 1)
//        cout << dur1.text() << " > " << dur2.text();

}