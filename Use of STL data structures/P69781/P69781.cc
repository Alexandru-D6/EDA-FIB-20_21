#include<iostream>
#include<map>
using namespace std;

int main() {
    
    int x, y, n;

    while (cin >> x >> y >> n) {
        map<int, int> m;
        map<int,int>::const_iterator it;
        int cicle = 0;
        bool repeted = false;

        m.insert(make_pair(n, cicle));

        while (not repeted and n <= 100000000) {
            ++cicle;

            if (n%2 == 0) n = (n/2) + x;
            else n = (3*n) + y;

            it = m.find(n);

            if (it == m.end()) m.insert(make_pair(n,cicle));
            else repeted = true;
        }

        if (repeted) cout << (m.size() - it->second) << endl;
        else cout << n << endl;

    }
}