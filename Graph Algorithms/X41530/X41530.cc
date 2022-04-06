#include <set>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
    
        set<int> v_nodos;
        pair<set<int>::iterator, bool> ret;
        int n_arboles = 0;
        bool arbol = n;

        int i = 0;
        while (arbol and i < m) {
            int nodo_1, nodo_2;
            cin >> nodo_1 >> nodo_2;

            ret = v_nodos.insert(nodo_1);
            bool first_node = ret.second;
            ret = v_nodos.insert(nodo_2);
            bool second_node = ret.second;

            if (first_node and second_node) n_arboles++;
            else if (not first_node and not second_node) arbol = false;

            i++;
        }

        if (arbol) {
            cout << n_arboles + n - v_nodos.size() << endl;
        }else {
            string line;
            getline(cin, line);
            cout << "no" << endl;
        }
    }
}