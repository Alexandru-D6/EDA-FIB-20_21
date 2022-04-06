#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> M;
int n;

vector<vector<int>> floyd_marshall() {
    vector<vector<int>> d = M;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < n; ++ii) d[i][ii] = min(d[i][ii], d[i][k] + d[k][ii]);
        }
    }

    return d;
}

int main() {
    cin >> n;

    M = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) cin >> M[i][ii];
    }

    vector<vector<int>> out = floyd_marshall();

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) cout << out[i][ii] << ' ';
        cout << endl;
    }
    cout << endl;
}