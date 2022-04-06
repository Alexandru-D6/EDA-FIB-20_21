#include <vector>
#include <iostream>
using namespace std;

int n, num;
vector<int> T;
vector<bool> C, D1, D2;

/* n-j-1+i

   0  1  2  3
    _  _  _  _
0  |3  2  1  0

1  |3  3  2  1

2  |5  4  3  2

3  |6  5  4  3 

*/

inline int diag1(int i, int j) {
    return n - j - 1 + i;
}

/* i+j

   0  1  2  3
    _  _  _  _
0  |0  1  2  3

1  |1  2  3  4

2  |2  3  4  5

3  |3  4  5  6 

*/

inline int diag2(int i, int j) {
    return i+j;
}

void recursive(int i) {
    if (i == n) {
        ++num;
    }else {
        for (int j = 0; j < n; ++j) {
            if (not C[j] and not D1[diag1(i,j)] and not D2[diag2(i,j)]) {
                T[i] = j;
                C[j] = true;
                D1[diag1(i,j)] =true;
                D2[diag2(i,j)]=true;
                recursive(i+1);
                C[j]=false;
                D1[diag1(i,j)] =false;
                D2[diag2(i,j)]=false;
            }
        }
    }
}

int main() {
    cin >> n;
    T = vector<int>(n);
    C = vector<bool>(n, false);
    D1 = vector<bool>(2*n-1), false;
    D2 = vector<bool>(2*n-1), false;
    num = 0;
    recursive(0);
    cout << num << endl;
}