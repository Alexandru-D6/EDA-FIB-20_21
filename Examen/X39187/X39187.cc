#include <iostream>
#include <vector>
using namespace std;

void print_sol(const vector<char>& sol) {
    int size = sol.size();

    for(int i = 0; i < size; ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void bt(const int& n, const int& c_original, int c, vector<char>& sol) {
    if (sol.size() == n) print_sol(sol);
    else {
        if (c != 0) {
            sol.push_back('b');
            bt(n, c_original, c-1, sol);
            sol.pop_back();
        }
        if (c < c_original) {
            sol.push_back('s');
            bt(n, c_original, c+1, sol);
            sol.pop_back();
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<char> sol(0);

    bt(n, c, c, sol);
}