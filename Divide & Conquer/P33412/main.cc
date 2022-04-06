#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double>& v, int l, int r) {
    if (r<l) return false;
    else {
        int m = (r+l)/2;
        if (v[m] == x or (v[m-1] == x and m-1 >= l) or (v[m+1] == x and m+1 <= r)) return true;

        if (x < v[m]) return false or resistant_search(x,v,l,m-1);
        else return false or resistant_search(x,v,m+1,r);
    }
}


bool resistant_search(double x, const vector<double>& v) {
    return resistant_search(x,v,0,v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
