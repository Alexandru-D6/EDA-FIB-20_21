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

void bt(const int& n, int nr_a, int nr_b, vector<char>& sol) {
    if (sol.size() == n) print_sol(sol);
    else {
        if ((nr_a+1)-nr_b <= 2 and (nr_a+1)-nr_b >= -2) {
            sol.push_back('a');
            bt(n, nr_a+1, nr_b, sol);
            sol.pop_back();
        }
        if (nr_a-(nr_b+1) <= 2 and nr_a-(nr_b+1) >= -2) {
            sol.push_back('b');
            bt(n, nr_a, nr_b+1, sol);
            sol.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> sol(0);
    int nr_a = 0, nr_b = 0;
    bt(n, nr_a, nr_b, sol);
}