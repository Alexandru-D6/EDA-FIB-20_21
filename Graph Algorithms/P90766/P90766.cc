#include <iostream>
#include <vector>
using namespace std;

void tresure(vector< vector<char> >& A, int n, int m, int r, int c, int& n_tresures) {
    if (A[r][c] == 't') n_tresures++;
    A[r][c] = 'X';

    if (r > 0 and A[r-1][c] != 'X') tresure(A, n, m, r-1, c, n_tresures);
    if (r < n-1 and A[r+1][c] != 'X') tresure(A, n, m, r+1, c, n_tresures);
    if (c > 0 and A[r][c-1] != 'X') tresure(A, n, m, r, c-1, n_tresures);
    if (c < m-1 and A[r][c+1] != 'X') tresure(A, n, m, r, c+1, n_tresures);
}

int main() {
    
    int n, m;
    cin >> n >> m;
    vector< vector<char> > graph(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    int n_tresures = 0;
    tresure(graph, n, m, r-1, c-1, n_tresures);

    cout << n_tresures << endl;
}