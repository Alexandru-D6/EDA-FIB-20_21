#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<int> moves_Y = { 2, 2, 1,-1,-2,-2,-1, 1};
const vector<int> moves_X = {-1, 1, 2, 2, 1,-1,-2,-2};

bool pos_ok(const vector<vector<char>>& mapa, const pair<int,int>& pos) {
    return (pos.first >= 0 and pos.first < mapa.size() and pos.second >= 0 and pos.second < mapa[0].size() and mapa[pos.first][pos.second] != 'X');
}

void run_bfs(vector<vector<char>>& mapa, const pair<int,int>& init_pos) {
    queue<pair<int,int>> cola;
    cola.push(init_pos);
    vector<vector<int>> distancias(mapa.size(), vector<int>(mapa[0].size(), -1));
    distancias[init_pos.first][init_pos.second] = 0;

    while (not cola.empty()) {
        pair<int,int> pos = cola.front();
        cola.pop();

        if (mapa[pos.first][pos.second] == 'p') {
            cout << distancias[pos.first][pos.second] << endl;
            return;
        }

        for (int i = 0; i < 8; ++i) {
            pair<int,int> temp_pos = pos;
            temp_pos.first += moves_Y[i];
            temp_pos.second += moves_X[i];
            if (pos_ok(mapa, temp_pos) and distancias[temp_pos.first][temp_pos.second] == -1) {
                distancias[temp_pos.first][temp_pos.second] = distancias[pos.first][pos.second] + 1;
                cola.push(temp_pos);
            }
        }
    }

    cout << "no" << endl;

}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> mapa(n, vector<char>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> mapa[i][j];
        }

        pair<int,int> init_pos;
        cin >> init_pos.first >> init_pos.second;
        init_pos.first -= 1;
        init_pos.second -= 1;

        run_bfs(mapa, init_pos);
    }
}