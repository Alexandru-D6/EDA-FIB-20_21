#include <iostream>
#include <vector>
using namespace std;

void mult(const vector<int>& a, const vector<int>& b, vector<int>& out) {
    for (int i = 0; i < b.size(); ++i) {
        out[i] = a[b[i]];
    }
}

void potencia(const vector<int>& p, int exp, vector<int>& out) {
    if (exp == 0) for (int i = 0; i < p.size(); ++i) out[i] = i;
    else if (exp == 1) out = p;
    else {
        potencia(p, exp/2, out);
        vector<int> res(p.size());
        mult(out, out, res);
        if (exp%2 == 0) {
            out = res;
        }else {
            mult(res, p, out);
        }
    }
    return;
}

int main() {
    int size, exp;
    while (cin >> size) {
        vector <int> p(size);
        for (int i = 0; i< size; ++i) cin >> p[i];
        cin >> exp;

        vector <int> out(size);
        potencia(p, exp, out);

        cout << out[0];
        for (int i = 1; i < size; ++i) cout << ' ' << out[i];
        cout << endl;
    }
}