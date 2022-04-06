#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pair<int,int>> diagonales = {{1,1},{-1,1},{-1,-1},{1,-1}};

bool pos_ok(int n, int m, int i, int j) {
    return (i < n and j < m and i >= 0 and j >= 0);
}

bool ghost(const vector<vector<char>>& mapa, pair<int,int> P) {
    for (pair<int,int> i : moves) {
        if (mapa[P.first+i.first][P.second+i.second] == 'F') return true;
    }
    for (auto i : diagonales) {
        if (mapa[P.first+i.first][P.second+i.second] == 'F') return true;
    }
    return false;
}

void print_matrix(const vector<vector<bool>>& a) {
    for(const auto& i : a) {
        for (const auto& j : i) cout << j << ' ';
        cout << endl;
    }
    cout << endl;
}

void print_matrix_c(const vector<vector<char>>& a) {
    for(const auto& i : a) {
        for (const auto& j : i) cout << j << ' ';
        cout << endl;
    }
    cout << endl;
}

bool bfs(const vector<vector<char>>& mapa, pair<int,int> P) {
    queue<pair<int,int>> cola;
    cola.push(P);
    vector<vector<bool>> visited(mapa.size(), vector<bool>(mapa[0].size(), false));
    visited[P.first][P.second] = true;

    if (ghost(mapa, P)) return false;
    
    while (not cola.empty()) {
        pair<int,int> pos = cola.front();
        cola.pop();

        if (mapa[pos.first][pos.second] == 'B') {
            //print_matrix(visited);
            return true;
        }


        for (pair<int,int> w : moves) {
            pair<int,int> temp = pos;
            temp.first += w.first;
            temp.second += w.second;

            if (pos_ok(mapa.size(),mapa[0].size(), temp.first, temp.second) and (not visited[temp.first][temp.second]) and mapa[temp.first][temp.second] != 'X' and not ghost(mapa, temp)) {
                //cout << pos.first << ' ' << pos.second << endl;
                //cout << "- " <<  temp.first << ' ' << temp.second << endl;
                visited[temp.first][temp.second] = true;
                //print_matrix(visited);
                cola.push(temp);
            }
        }
    }
    //print_matrix(visited);
    return false;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        vector<vector<char>> mapa(n, vector<char>(m));

        pair<int,int> pos_pacman;
        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < m; ++ii) {
                cin >> mapa[i][ii];
                if (mapa[i][ii] == 'P') pos_pacman = make_pair(i,ii);
            }
        }
        cout << (bfs(mapa, pos_pacman) ? "yes" : "no") << endl;
    }
}