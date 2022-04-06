#include <iostream>
#include <vector>
using namespace std;

void print_num(const vector<int>& x, const vector<bool> sol) {
    cout << '{';
    bool first = true;
    for (int i = 0; i < x.size(); ++i) {
        if (sol[i]) {
            if (first) first = false;
            else cout << ',';
            cout << x[i];
        }
    }
    cout << '}' << endl;
}

void algoritmo(int num, int k, const vector<int>& x, int suma, int suma_x, vector<bool>& sol) {
    if (suma > num or suma + suma_x < num) return;
    if (k == x.size()) print_num(x, sol);
    sol[k] = false;
    algoritmo(num, k+1, x, suma, suma_x-x[k], sol);
    sol[k] = true;
    algoritmo(num, k+1, x, suma + x[k], suma_x-x[k], sol);
    
}

int main() {
    int num; cin >> num;
    int n; cin >> n;

    vector<int> x(n);
    vector<bool> sol(n);
    int suma_x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        suma_x += x[i];
    }

    algoritmo(num, 0, x, 0, suma_x, sol);
}