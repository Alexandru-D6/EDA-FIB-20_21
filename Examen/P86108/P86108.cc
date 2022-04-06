#include <iostream>
#include <vector>
using namespace std;

void bt(vector<vector<char>>& matrix, int n, int m, int k, int l, int& max_LOL, int parc_max) {
    if (k == n) {
        max_LOL = max(max_LOL, parc_max);
        return;
    }else {
        
        matrix[k][l] = 'L';
        int temp = 0;
        if (          l > 1 and matrix[k][l-1] == 'O' and matrix[k][l-2] == 'L') ++temp;
        if (k > 1 and matrix[k-1][l] == 'O' and matrix[k-2][l] == 'L') ++temp;
        if (k > 1 and l > 1 and matrix[k-1][l-1] == 'O' and matrix[k-2][l-2] == 'L') ++temp;
        if (k > 1 and l+2 < m and matrix[k-1][l+1] == 'O' and matrix[k-2][l+2] == 'L') ++temp;

        if (l < m-1) bt(matrix, n, m, k, l+1, max_LOL, parc_max + temp);
        else bt(matrix, n, m, k + 1, 0, max_LOL, parc_max + temp);
        matrix[k][l] = 'O';
        if (l < m-1) bt(matrix, n, m, k, l+1, max_LOL, parc_max);
        else bt(matrix, n, m, k + 1, 0, max_LOL, parc_max);

    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {

        vector<vector<char>> matrix(n, vector<char>(m));

        int max_LOL = 0;
        bt(matrix, n, m, 0, 0, max_LOL, 0);
        cout << max_LOL << endl;
    }
}