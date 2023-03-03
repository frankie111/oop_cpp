#include <iostream>

using namespace std;

bool relativePrimes(int a, int b) {
    if (a == b)
        return false;

    if (a > b)
        swap(a, b);

    for (int i = 2; i <= b / 2; i++) {
        if (b % i == 0)
            if (a % i == 0)
                return false;
    }

    return true;
}

void prob0_a() {

}

// Returns true if a has the same digits as b, false otherwise
bool eqDigits(int a, int b) {
    int digits[10] = {0};
    if (a > b)
        swap(a, b);

    while (b != 0) {
        digits[a % 10]++;
        digits[b % 10]--;
        a /= 10;
        b /= 10;
    }

    for (int digit: digits)
        if (digit)
            return false;

    return true;
}

// read an array of integers and return the size of array
int readArray(int v[]) {
    int len;
    cout << "size of array: ";
    cin >> len;

    for (int i = 0; i < len; i++)
        cin >> v[i];

    return len;
}

// Print the longest series of numbers with equal digits
void prob0_b() {
    int v[100], len;
    len = readArray(v);

    int currLen = 0, maxLen = 0, currStart = 0, maxStart = 0;

    for (int curr = 1; curr < len; curr++) {
        if (eqDigits(v[curr], v[curr - 1])) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = currStart;
            }

            currStart = curr;
            currLen = 1;
        }
    }

    // Check one last time for maxLen in case the last series is the longest
    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = currStart;
    }

    for (int i = maxStart; i < maxStart + maxLen; i++)
        cout << v[i] << ' ';
}

int main() {
    prob0_b();
}
