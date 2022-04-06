#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool is_cyclic(vector<vector<int>>& arestas) {
    int n = arestas.size();
    
    vector<int> gradosar(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int v : arestas[i]) ++gradosar[v];
    }

    vector<int> nodos;
    for (int i = 0; i < n; ++i) if (gradosar[i] == 0) nodos.push_back(i);

    while (not nodos.empty()) {
        int sel = nodos.back();
        nodos.pop_back();
        --n;
        --gradosar[sel];

        for (int v : arestas[sel]) {
            --gradosar[v];
            if (gradosar[v] == 0) nodos.push_back(v);
        }

    }

    return n>0;
}

int main() {
    int n, m;
    while (cin >> n >> m) {

        vector<vector<int>> arestas(n);
        
        for (int i = 0; i < m; ++i) {
            int vertice1, vertice2;
            cin >> vertice1 >> vertice2;

            arestas[vertice1].push_back(vertice2);
        }

        if (is_cyclic(arestas)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}