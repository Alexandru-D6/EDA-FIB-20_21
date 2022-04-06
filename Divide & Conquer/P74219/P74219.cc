#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mult(const vector<vector<int>>& A, const vector<vector<int>>& B, int m) {
    return {
            {(A[0][0]*B[0][0] + A[0][1]*B[1][0])%m , (A[0][0]*B[0][1] + A[0][1]*B[1][1])%m},
            {(A[1][0]*B[0][0] + A[1][1]*B[1][0])%m , (A[1][0]*B[0][1] + A[1][1]*B[1][1])%m}
           };
}

vector<vector<int>> potencia(const vector<vector<int>>& M, int n, int m) {
    if (n == 0) return {{1,0},{0,1}};
    else {
        vector<vector<int>> Y = potencia(M, n/2, m);

        if (n%2 == 0) return mult(Y,Y, m);
        else return mult(mult(Y,Y,m),M,m);
    }
}

int fibonacci_mod(int n, int m) {
    vector< vector<int>> R(2, vector<int>(2));
    R = {{0,1},{1,1}};
    if (n > 0) {
        R = potencia(R, n-1, m);
        return R[1][1];
    }else return 0;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << fibonacci_mod(n,m) << endl;
    }
}