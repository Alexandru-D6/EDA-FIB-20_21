#include <vector>
#include <iostream>
using namespace std;

int n;
vector<string> T;
vector<bool> usado;
vector<string> palabras;

bool legal(int i) {
    if (not usado[i])return true;
    else return false;
}

void escriure() {
    cout << '('<< T[0];
    for (int i = 1; i < n; ++i) cout << ',' << T[i];
    cout << ')' << endl;
}

void recursiu(int i) {
    if (i == n) {
        escriure();
    }else {
        for (int j = 0; j < n; ++j) {
            if (legal(j)) {
                T[i] = palabras[j];
                usado[j] = true;
                recursiu(i+1);
                usado[j] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    T = vector<string>(n);
    usado = vector<bool>(n,false);
    palabras = vector<string>(n);
    for (int i = 0; i < n; ++i) cin >> palabras[i];
    recursiu(0);
}