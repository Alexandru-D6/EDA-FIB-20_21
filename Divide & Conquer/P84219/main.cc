#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v, int l, int r) {
    
    if (l > r) return -1;
    else {
        int m = (l+r)/2;
        if (v[m]==x) {
            if (m-1 >= l and v[m-1]== x) return first_occurrence(x,v,l,m-1);
            else return m;
        }else if (v[m] < x) return first_occurrence(x,v,m+1,r);
        else return first_occurrence(x,v,l,m-1);
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return first_occurrence(x, v, 0, v.size()-1);
}

/*
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
            cout << first_occurrence(x, V) << endl;
        }
    }
}*/
