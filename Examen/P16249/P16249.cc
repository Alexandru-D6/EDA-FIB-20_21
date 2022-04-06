#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

//vector<string> i2s;
//map<string,int> s2i;

void print_mapa(const map<string,int>& m) {
    map<string,int>::const_iterator it = m.begin();
    while (it != m.end()) {
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}

/*string int2string(int x) {
    return i2s[x];
}

int string2int(string x) {
    map<string,int>::iterator it = s2i.find(x);
    if (it != s2i.end()) return it->second;
    else {
        int n = i2s.size();
        i2s.push_back(x);
        s2i.insert(make_pair(x,n));
        return n;
    }
}*/

int main() {
    int n;
    while (cin >> n) {
        //i2s.clear();
        //s2i.clear();
        map<int,string> i2s;
        map<string,int> s2i;

        for (int i = 0; i < n; ++i) {
            string temp;
            cin >> temp;
            i2s.insert(make_pair(i,temp));
            s2i.insert(make_pair(temp,i));
        }

        vector<vector<int>> g(n);
        vector<int> predecesores(n,0);

        int m;
        cin >> m;

        for (int i = 0; i < m; ++i) {
            string x, y;
            cin >> x >> y;

            g[s2i.find(x)->second].push_back(s2i.find(y)->second);
            ++predecesores[s2i.find(y)->second];
        }

        /*for (auto& w : s2i) cout << w.first << ' ' << w.second << endl;

        for (auto& w : g) {
            for (auto& e : w) {
                if (e == -1) cout << ". ";
                else cout << i2s.find(e)->second << ' ';
            }
            cout << endl;
            cout << "--" << endl;
        }*/

        priority_queue<string, vector<string>, greater<string>> cola;

        for (int i = 0; i < predecesores.size(); ++i) 
            if (predecesores[i] == 0) cola.push(i2s.find(i)->second);

        vector<string> sol;
        while (not cola.empty()) {
            string palabra = cola.top();
            cola.pop();
            sol.push_back(palabra);
        
            for (auto& w : g[s2i.find(palabra)->second]) {
                --predecesores[w];
                if (predecesores[w] == 0) cola.push(i2s.find(w)->second);
            }
        }

        if (sol.size() != n) cout << "NO VALID ORDERING";
        else {
            for (auto& w : sol) cout << w;
        }
        cout << endl;
    }
}