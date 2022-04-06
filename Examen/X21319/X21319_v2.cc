#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std; 

vector<string> i2s;
map<string,int> s2i;

string int2string(int x) {
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
}

int main() {
    set<string> output;
    set<string> input;
    vector<int> predecesores;
    vector< vector< int > > circuito;
    map<string,string> puertas;

    string token;

    cin >> token; //output
    while (cin >> token and token != "END") output.insert(token);

    cin >> token; //input
    while (cin >> token and token != "END") {
        input.insert(token);
        string2int(token);
        predecesores.push_back(0);
        circuito.push_back(vector<int>(0));   
        puertas.insert(make_pair(token, "DIRECTO"));
    }
    
    string hardware;

    while (cin >> hardware and hardware != "END") {
        if (hardware != "NOT") {
            string o, x, y;
            cin >> o >> x >> y;
            cout << o << ' ' << x << ' ' << y << endl;

            puertas.insert(make_pair(o,hardware));

            int _o = string2int(o);
            if (_o == predecesores.size()) {
                predecesores.push_back(2);
                circuito.push_back(vector<int>(0));
            }else predecesores[_o] += 2;

            int _x = string2int(x);
            circuito[_o].push_back(_x);
            /*if (_o == i2s.size()-1) circuito.push_back(vector<int>(1, _x));
            else circuito[_o].push_back(_x);*/
            int _y = string2int(y);
            circuito[_o].push_back(_y);
            /*if (_o == i2s.size()-1) circuito.push_back(vector<int>(1, _y));
            else circuito[_o].push_back(_y);*/

            cout << _o << ' ' << _x << ' ' << _y << endl;
        }else {
            string o, x;
            cin >> o >> x;
            cout << o << ' ' << x << endl;
            puertas.insert(make_pair(o,hardware));

            int _o = string2int(o);
            if (_o == predecesores.size()) {
                predecesores.push_back(1);
                circuito.push_back(vector<int>(0));
            }else ++predecesores[_o];

            int _x = string2int(x);
            circuito[_o].push_back(_x);
            /*if (_o == i2s.size()-1) circuito.push_back(vector<int>(1, _x));
            else circuito[_o].push_back(_x);*/
            cout << _o << ' ' << _x << endl;
        }
    }

    for (int i = 0; i < circuito.size(); ++i) {
        cout << int2string(i) << ":" << endl;
        for (int j = 0; j < circuito[i].size(); ++j) cout << int2string(circuito[i][j]) << ' ';
        cout << endl;
    }
    cout << endl;

    char temp;
    while (cin >> temp) {
        vector<bool> sol(circuito.size());
        set<string>::const_iterator it = input.begin();
        sol[string2int(*it)] = bool(temp-'F');
        ++it;

        for (int i = 1; i < input.size(); ++i) {
            cin >> temp;
            sol[string2int(*it)] = bool(temp-'F');
            ++it;
        }

        queue<int> cola;

        for (int i = 0; i < predecesores.size(); ++i) 
                if (predecesores[i] == 0) cola.push(i);

        while(not cola.empty()) {
            int punto = cola.front();
            cola.pop();
            string opt = puertas.find(int2string(punto))->second;
            if (opt == "AND") sol[punto] = circuito[punto][0] and circuito[punto][1];
            else if (opt == "OR") sol[punto] = circuito[punto][0] and circuito[punto][1];
            else if (opt == "NOT") sol[punto] = not circuito[punto][0];
            
            for 
        }


    }

}