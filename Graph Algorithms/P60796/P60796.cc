/*

//Implementacion con grafos como tal

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

double inf = std::numeric_limits<double>::infinity();

typedef vector<vector<int>> graph;

enum color {white, gray, black};

vector<color> c;
vector<char> el1;
vector<int> d, p;

void bfs (const graph& G, int s) {
    for (int u = 0; u < G.size(); ++u) {
        if (u==s) {
            c[u] = gray;
            d[u] = 0;
        }else {
            c[u] = white;
            d[u] = inf;
        }
        p[u] = -1;
    }

    queue<int> Q;
    Q.push(s);

    while (not Q.empty()) {
        int u = Q.front(); 
        Q.pop();

        if (el1[u] == 't') {
            cout << "minimum distance: " << d[u] << endl;
            return;
        }

        for (int v : G[u]) {
            if (c[v] == white) {
                c[v] = gray;
                d[v] = d[u]+1;
                p[v] = u;
                Q.push(v);
            }
        }
        c[u] = black;
    }

    cout << "no treasure can be reached" << endl;
}

*/

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

    while (not cola.empty()) {
        pos coord = cola.front();
        cola.pop();
        if (mapa[coord.x][coord.y] == 't') return dist[coord.x][coord.y];

        for (int i = 0; i < N_DIRS; ++i) {
            if (inside(coord.x + DX[i], coord.y + DY[i], r, c) and 
                mapa[coord.x + DX[i]][coord.y + DY[i]] != 'X' and
                dist[coord.x + DX[i]][coord.y + DY[i]] == UNDEF) {
                    cola.push({coord.x + DX[i], coord.y + DY[i]});
                    dist[coord.x + DX[i]][coord.y + DY[i]] = dist[coord.x][coord.y] + 1;
            }
        }
    }

    return UNDEF;
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

    if (distance > 0) cout << "minimum distance: " << distance << endl;
    else cout << "no treasure can be reached" << endl;
}