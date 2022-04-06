#include <iostream>
#include <vector>
using namespace std;

bool pintar(const vector<vector<int>>& arestas, vector<int>& colores, int col, int k) {
    if (colores[k] == -1) {
        colores[k] = col;

        for (auto w : arestas[k]) {
            if (not pintar(arestas, colores, 1-col, w)) return false;
        }
        return true;
    }else return colores[k] == col;
}

/*bool dfs(const vector<vector<int>>& arestas, int k, int prev, vector<bool>& visited) {
    visited[k] = true;

    for (int w : arestas[k]) {
        if (!visited[w]) return true and dfs(arestas, w, k, visited);
        else {
            if (w != prev) return false;
        }
    }
    return true;
}

int all_visited(const vector<bool>& visited) {
    for (int i = 0; i < visited.size(); ++i) {
        if (not visited[i]) return i;
    }
    return -1;
}*/

bool two_colorability(const vector<vector<int>>& arestas, vector<int>& color, int n, int k) {
    if (k == n) return true;
    else if (color[k] == -1) return pintar(arestas, color, 0, k) and two_colorability(arestas, color, n, k+1);
    else return two_colorability(arestas, color, n, k+1);
}

int main() {
    int n, m;
    while (cin >> n >> m) {

        vector<vector<int>> arestas(n, vector<int>(0));
        arestas.

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            arestas[x].push_back(y);
            arestas[y].push_back(x);
        }

        vector<int> color(n, -1);
        cout << (two_colorability(arestas, color, n, 0) ? "yes" : "no") << endl;
    }
}