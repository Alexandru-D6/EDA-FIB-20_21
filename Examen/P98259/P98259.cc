#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<int> moves_Y = {1,0,-1,0};
const vector<int> moves_X = {0,1,0,-1};

bool pos_ok(const vector<vector<char>>& mapa, const int& n, const int& m, const int& i, const int& j) {
    return (i >= 0 and i < n and j >= 0 and j < m and mapa[i][j] != '#');
}

pair<int,int> run_BFS(const vector<vector<char>>& mapa, const int& n, const int& m) {
    vector<vector<pair<int,int>>> distancias(n, vector<pair<int,int>>(m, make_pair(-1,-1)));
    queue<pair<int, int>> cola;
    cola.push(make_pair(0,0));
    distancias[0][0] = make_pair(0, mapa[0][0] == 'P');

    while (not cola.empty()) {
        pair<int,int> pos = cola.front();
        cola.pop();

        if (mapa[pos.first][pos.second] == 'T') return distancias[pos.first][pos.second];

        for (int i = 0; i < 4; ++i) {
            pair<int,int> next_pos = pos;
            next_pos.first += moves_Y[i];
            next_pos.second += moves_X[i];

            if (pos_ok(mapa, n, m, next_pos.first, next_pos.second) and 
                    (distancias[next_pos.first][next_pos.second].first == -1 or 
                    (distancias[pos.first][pos.second].second >= distancias[next_pos.first][next_pos.second].second and
                    distancias[pos.first][pos.second].first < distancias[next_pos.first][next_pos.second].first)) ) {

                distancias[next_pos.first][next_pos.second] = distancias[pos.first][pos.second];
                distancias[next_pos.first][next_pos.second].first += 1;
                distancias[next_pos.first][next_pos.second].second += (mapa[next_pos.first][next_pos.second] == 'P');
                cola.push(next_pos);
            }
        }
    }
    return make_pair(-1,-1);
}

int main() {
    int n, m;
    while(cin >> n >> m) {

        vector<vector<char>> mapa(n, vector<char>(m));
        bool Is_this_telecos = false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char temp; cin >> temp;
                if (not Is_this_telecos) Is_this_telecos = (temp == 'T');
                mapa[i][j] = temp;
            }
        }

        if (Is_this_telecos) {
            pair<int,int> res = run_BFS(mapa, n, m);
            if (res.first == -1) {
                cout << "El telecos esta amagat." << endl;
            }else {
                cout << res.first << ' ' << res.second << endl;
            }

        }else {
            cout << "El telecos ha fugit." << endl;
        }
    }
}