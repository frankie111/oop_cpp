#include <iostream>
#include <cmath>
using namespace std;

float prob0_a(){

}

bool isPrime(int n) {
    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}



int main(){

}