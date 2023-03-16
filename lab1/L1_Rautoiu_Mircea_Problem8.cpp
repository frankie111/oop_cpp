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
void twinPrimes() {
    int n, ct = 0, first = 3;
    cout << "n:";
    cin >> n;

    while (ct < n) {
        if (isPrime(first) && isPrime(first + 2)) {
            ct++;
            cout << first << " - " << first + 2 << endl;
        }

        first++;
    }

}

//read a vector of integers and return the size of vector
int readVector(int v[]) {
    int len;
    cout << "size of vector: ";
    cin >> len;

    for (int i = 0; i < len; i++) {
        printf("[%d]: ", i);
        cin >> v[i];
    }

    return len;
}

//Print the longest decreasing series in vector v
void maxDecreasing() {
    int v[100], len;

    len = readVector(v);

    int currLen = 1, start = 0, maxLen = 0, maxStart = 0;

    for (int curr = 1; curr < len; curr++) {
        if (v[curr] < v[curr - 1])
            currLen++;
        else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = start;
            }
            start = curr;
            currLen = 1;
        }
    }

    //Check one more time for maxLen in case the last series is the longest
    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = start;
    }

    for (int i = maxStart; i < maxStart + maxLen; i++)
        cout << v[i] << ' ';
}

int main() {
    //twinPrimes();
    maxDecreasing();
}
