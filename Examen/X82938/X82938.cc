#include <iostream>
#include <vector>
using namespace std;

int top(const vector<int>& v, int l, int r) {
    if (r >= l) {
        int mid = (r+l)/2;

        if (mid == 0 or mid == v.size()-1) return -1;

        if (v[mid] > v[mid-1] and v[mid] > v[mid+1]) return mid;
        else if (v[mid] < v[mid-1]) return top(v, l, mid-1);
        else if (v[mid] < v[mid+1]) return top(v, mid+1, r);
    }
    return -1;
}

bool binary_search(bool inc, int a, int b, const vector<int>& v, int x) {
    if (b >= a) {
        int m = (a+b)/2;

        if (v[m] == x) return true;

        bool cond;
        if (inc) cond = v[m] < x;
        else cond = v[m] > x;

        if (cond) return binary_search(inc, m+1, b, v, x);
        else return binary_search(inc, a, m-1, v, x);

    }
    return false;
}

bool search(int x, const vector<int>& v) {
    int _top = top(v, 0, v.size()-1);
    if (_top == -1) return binary_search(v[0] < v[1], 0, v.size(), v, x);
    else return binary_search(1, 0, _top, v, x) or binary_search(0, _top, v.size(), v, x);
}

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    int x;
    while (cin >> x) cout << (search(x, V) ? "true" : "false") << endl;
    
}