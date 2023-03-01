#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

//Print first n twin prime pairs
void twinPrimes(int n) {
    int ct = 0, first = 3;

    while (ct < n) {
        if (isPrime(first) && isPrime(first + 2)) {
            ct++;
            cout << first << " - " << first + 2 << endl;
        }

        first++;
    }

}

//Print the longest decreasing series in vector v
void maxFallend(const int v[], int len_) {
    int len = 1, start = 0, maxLen = 0, maxStart = 0;

    for (int curr = 1; curr < len_; curr++) {
        if (v[curr] < v[curr - 1]) {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
                maxStart = start;
            }
            start = curr;
            len = 1;
        }
    }

    //Check one more time for maxLen in case the last series is the longest
    if (len > maxLen) {
        maxLen = len;
        maxStart = start;
    }

    for (int i = maxStart; i < maxStart + maxLen; i++) {
        cout << v[i] << ' ';
    }
}

int main() {
    int v[14] = {1, 2, 6, 5, 4, 2, 1, 6, 5, 4, 3, 2, 1, 0};
    maxFallend(v, 14);
}
