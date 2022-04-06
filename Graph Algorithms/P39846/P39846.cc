#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int UNDEF = -1;
const int N_DIRS = 4;
const int DX[N_DIRS] = {1, 0, -1, 0};
const int DY[N_DIRS] = {0, 1, 0, -1};

struct pos{
    int x, y;
    pos(int ii, int jj) : x(ii), y(jj) {}
};

bool inside(int x, int y, int r, int c) {
    return (0 <= x and 0 <= y and x < r and y < c);
}

int bfs(const vector<vector<char>>& mapa, int sx, int sy) {
    int r = mapa.size();
    int c = mapa[0].size();
    queue<pos> cola;
    cola.push( pos(sx,sy) );
    vector<vector<int>> dist(r, vector<int>(c,UNDEF));
    dist[sx][sy] = 0;
    int max_distance = -1;

    while (not cola.empty()) {
        pos coord = cola.front();
        cola.pop();
        if (mapa[coord.x][coord.y] == 't') {
            int temp = dist[coord.x][coord.y];
            if (temp > max_distance) max_distance = temp;
        }

        for (int i = 0; i < N_DIRS; ++i) {
            if (inside(coord.x + DX[i], coord.y + DY[i], r, c) and 
                mapa[coord.x + DX[i]][coord.y + DY[i]] != 'X' and
                dist[coord.x + DX[i]][coord.y + DY[i]] == UNDEF) {
                    cola.push({coord.x + DX[i], coord.y + DY[i]});
                    dist[coord.x + DX[i]][coord.y + DY[i]] = dist[coord.x][coord.y] + 1;
            }
        }
    }

    return max_distance;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector< vector < char > > mapa(r, vector<char>(c));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cin >> mapa[i][j];
    }

    int sx, sy;
    cin >> sx >> sy;

    int distance = bfs(mapa, sx-1, sy-1);

    if (distance > 0) cout << "maximum distance: " << distance << endl;
    else cout << "no treasure can be reached" << endl;
}