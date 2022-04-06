#include <iostream>
#include <vector>
using namespace std;

/*
9 7 4 9
8 7 7 5 7 1 7 2 1 3 2 3 3 4 6 4 4 0

4 0 2 3
0 2 2 3 3 0
*/

int a, b;

void dfs(const vector<vector<int>>& G, int x, int y, vector<bool>& par_sol, vector<bool>& sol, vector<int>& times_visited) {
    if (x == y) {
        for(int i = 0; i < sol.size(); ++i) sol[i] = sol[i] or par_sol[i];
        //return;
    }

    for (auto w : G[x]) {
        if (times_visited[w] < 2) {
            if (w != a and w != b) par_sol[w] = true;
            ++times_visited[w];
            dfs(G, w, y, par_sol, sol, times_visited);
            par_sol[w] = false;
            //--times_visited[w];
        }

    }
}

int contador(const vector<bool>& a) {
    int cont = 0;
    for (auto w : a) if (w) ++cont;
    return cont;
}

int main() {
    int n, m;

    while (cin >> n >> a >> b >> m) {

        vector<vector<int>> G(n);

        for (int i = 0; i < m; ++i) {
            int a1, a2;
            cin >> a1 >> a2;

            G[a1].push_back(a2);
        }

        vector<bool> sol(n, false);
        vector<bool> par_sol(n, false);
        vector<int> times_visited(n, 0);
        times_visited[a] = 1;
        dfs(G, a, b, par_sol, sol, times_visited);

        /*for (auto w : sol) cout << w << ' ';
        cout << endl;*/

        cout << contador(sol) << endl;
    }
}