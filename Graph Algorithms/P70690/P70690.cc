#include <iostream>
#include <vector>
using namespace std;

bool tresure(vector< vector<char> >& A, int n, int m, int r, int c) {
    bool found = (A[r][c] == 't');
    A[r][c] = 'X';

    if (not found and r > 0 and A[r-1][c] != 'X') found = tresure(A, n, m, r-1, c);
    if (not found and r < n-1 and A[r+1][c] != 'X') found = tresure(A, n, m, r+1, c);
    if (not found and c > 0 and A[r][c-1] != 'X') found = tresure(A, n, m, r, c-1);
    if (not found and c < m-1 and A[r][c+1] != 'X') found = tresure(A, n, m, r, c+1);

    return found;
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

    cout << (tresure(graph, n, m, r-1, c-1) ? "yes" : "no") << endl;
}