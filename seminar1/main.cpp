#include <iostream>
#include <string>

using namespace std;

void ub1() {
    string vorname, nachname;

    cout << "Vorname:";
    cin >> vorname;

    cout << "Nachname:";
    cin >> nachname;

    unsigned long long zeichenAnzahl = vorname.size() + nachname.size();

    printf("Hallo %s %s \nzeichenAnzahl=%llu", vorname.c_str(), nachname.c_str(), zeichenAnzahl);
}

struct Kundendaten {
    int nummer = 0;
    string name;
    int postLeitZahl = 0;
    string ortsname;
};

void ub2() {
    Kundendaten kundenArray[10];
}

void ub3() {
    const int m = 2, n = 3, p = 2;
    int m1[m][n] = {{1, 2, 3},
                    {2, 3, 4}};
    int m2[n][p] = {{1, 2},
                    {2, 3},
                    {1, 3}};
    int mul[m][p] = {};

    //multiply matrices
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++) {
                mul[i][j] += m1[i][k] * m2[k][j];
            }

    //print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << mul[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ub3();
}
