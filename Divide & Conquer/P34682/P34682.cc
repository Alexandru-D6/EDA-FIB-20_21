#include <iostream>
#include <vector>
using namespace std;

int fixed_point(const vector<int>& v, int a, int l, int r) {
    if (l>r) return -1;
    else {
        int mid = (l+r)/2;

        if (mid+1 == v[mid]+a) {
            int more_little = fixed_point(v,a,l,mid-1);
            
            if (more_little == -1) return mid+1;
            else return more_little;
        }else if (mid+1 > v[mid]+a) return fixed_point(v,a,mid+1,r);
        else return fixed_point(v,a,l,mid-1);
    }
}

int main() {
    int vn, an;
    int sequence = 0;
    while (cin >> vn) {
        ++sequence;
        vector<int> v(vn);
        for(int i = 0; i < vn; ++i) cin >> v[i];
        cin >> an;
        vector<int> a(an);
        for(int i = 0; i < an; ++i) cin >> a[i];

        cout << "Sequence #" << sequence << endl;
        for (int i = 0; i < an; ++i) {
            int res = fixed_point(v, a[i], 0, v.size()-1);

            if (res != -1) cout << "fixed point for " << a[i] << ": " << res << endl;
            else cout << "no fixed point for " << a[i] << endl;
        }
        cout << endl;
    }
}