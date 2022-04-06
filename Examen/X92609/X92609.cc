#include <iostream>
#include <vector>
using namespace std;

void subsetsum(int& contador, const vector<int>& monedas, int suma, int sum_par, const int& x, int k) {
    if (sum_par > x or sum_par + suma < x) return;
    if (k == monedas.size()) {
        ++contador;
        return;
    }
    for (int i = 0; i < 3; ++i) {
        subsetsum(contador, monedas, suma-2*monedas[k], sum_par+i*monedas[k], x, k+1);
    }
}

int main() {
    int x, n;
    cin >> x >> n;

    vector<int> monedas(n);
    int suma = 0;

    for (int i = 0; i < n; ++i) {
        cin >> monedas[i];
        suma += monedas[i];
    }    

    int contador = 0;
    subsetsum(contador, monedas, 2*suma, 0, x, 0);

    cout << contador << endl;
}