#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std; 

map<string, int> trad;
int nr_nodos_trad = 0;

void compute_output(const map<pair<string,string>,pair<string,string>>& circuito, map<string,bool>& partial_sol) {
    map<pair<string,string>,pair<string,string>>::const_iterator it = circuito.begin();

    while (it != circuito.end()) {
        if (it->second.first == "AND") {
            partial_sol.insert(make_pair(it->second.second, (partial_sol[it->first.first] and partial_sol[it->first.second])));
        }else if (it->second.first == "OR") {
            partial_sol.insert(make_pair(it->second.second, (partial_sol[it->first.first] or partial_sol[it->first.second])));
        }else if (it->second.first == "NOT") {
            partial_sol.insert(make_pair(it->second.second, not partial_sol[it->first.first]));
        }
        ++it;
    }
}

int string2int(string x) {
    map<string,int>::iterator it = trad.find(x);

    if (it != trad.end()) return it->second;
    else {
        trad.insert(make_pair(x, nr_nodos_trad));
        ++nr_nodos_trad;
        return nr_nodos_trad;
    }
}

int main() {

    vector< vector< int > > circuito;
    //map< pair<string,string>, pair<string, string> > circuito; //entrada, entrada, puerta logica, salida

    set<string> input;
    set<string> output;

    string serial;

    cin >> serial;
    while (cin >> serial and serial != "END") output.insert(serial);

    cin >> serial;
    while (cin >> serial and serial != "END") input.insert(serial);

    string hardware;
    while (cin >> hardware and hardware != "END") {
        if (hardware != "NOT") {
            string x, y, z;
            cin >> x >> y >> z;

            int _x = string2int(x);
            int _y = string2int(y);
            int _z = string2int(z);

            if (_y == circuito.size()) {
                circuito.push_back(_y);
            }
            if (_z == circuito)

            circuito.insert(make_pair(make_pair(y,z),make_pair(hardware, x)));
        }else {
            string x, y;
            cin >> x >> y;

            circuito.insert(make_pair(make_pair(y,y),make_pair(hardware, x)));
        }
    }


    char x;
    while (cin >> x) {
        map< string, bool > partial_sol; //entrada, su estado
        set<string>::const_iterator it = input.begin();
        partial_sol.insert(make_pair(*it, char('F'-x)));
        ++it;

        while (it != input.end()) {
            cin >> x;
            partial_sol.insert(make_pair(*it, char('F'-x)));
            ++it;
        }

        compute_output(circuito, partial_sol);

        it = output.begin();
        cout << (partial_sol[*it] ? 'T' : 'F');
        ++it;

        while (it != output.end()) {
            cout << ' ' << (partial_sol[*it] ? 'T' : 'F');
            ++it;
        }
        cout << endl;
    }
}