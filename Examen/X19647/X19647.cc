#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void compute_cost(int x, int y, const vector<int>& pesos_ar, const vector<vector<pair<int,int>>>& arestas) {
    int n = arestas.size();
    vector<int> distancias(n, -1);
    queue<int> cola;

    cola.push(x);
    distancias[x] = 0;

    while (not cola.empty()) {
        int act = cola.front();
        cola.pop();

        for (int i = 0; i < arestas[act].size(); ++i) {
            int cost;
            int first = arestas[act][i].first;
            int second = arestas[act][i].second;
            if (first == y) cost = distancias[act] + second;
            else cost = distancias[act] + second + pesos_ar[first];

            if (distancias[first] == -1 or distancias[first] > cost) {
                distancias[first] = cost;
                cola.push(first);
            }
        }
    }

    if (distancias[y] != -1) cout << "c(" << x << ',' << y << ") = " << distancias[y] << endl;
    else cout << "c(" << x << ',' << y << ") = +oo" << endl;

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> pesos_ar(n);
    vector< vector< pair<int,int> > > arestas(n, vector<pair<int,int>>(0));

    for (int i = 0; i < n; ++i) {
        cin >> pesos_ar[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y, w; cin >> x >> y >> w;
        arestas[x].push_back(make_pair(y,w));
        arestas[y].push_back(make_pair(x,w));
    }

    int x, y;

    while (cin >> x >> y) compute_cost(x, y, pesos_ar, arestas);

}