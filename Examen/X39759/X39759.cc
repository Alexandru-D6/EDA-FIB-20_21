#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> moves = {{2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}};

/*void print_matrix(const vector<vector<int>>& d) {
    for(const auto& i : d) {
        for (const auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
}*/

bool pos_ok(int n, int m, int i, int j) {
    return (i < n and j < m and i >= 0 and j >= 0);
}

int bfs(const pair<int,int>& start, const pair<int,int>& next, int n, int m) {
    int INF = n*m;
    queue<pair<int,int>> cola;
    cola.push(start);
    vector<vector<int>> d(n, vector<int>(m, INF));
    d[start.first][start.second] = 0;

    while (not cola.empty()) {
        pair<int,int> pos = cola.front();
        cola.pop();

        if (pos == next) return d[pos.first][pos.second];

        for (pair<int,int> w : moves) {
            pair<int,int> temp = pos;
            temp.first += w.first;
            temp.second += w.second;
            if (pos_ok(n, m, temp.first, temp.second) and d[temp.first][temp.second] == INF) {
                    d[temp.first][temp.second] = d[pos.first][pos.second]+1;
                    cola.push(make_pair(temp.first, temp.second));
            }
        }
    }
    return -1;
}

int main() {
    int n, m, W, L;
    while (cin >> n >> m >> W >> L) {
        int k;
        cin >> k;

        vector<pair<int,int>> coins(k);
        for (int i = 0; i < k; ++i) {
            int c1, c2;
            cin >> c1 >> c2;
            coins[i] = make_pair(c1,c2);
        }

        pair<int,int> start = {0,0};
        int max_points = 0;
        int suma_par = 0;
        bool stop = false;

        for (int i = 0; i < k and not stop; ++i) {
            pair<int,int> next = coins[i];
            int dist = bfs(start, next, n, m);
            if (dist == -1) stop = true;
            else {
                suma_par += (W - L*dist);
                max_points = max(max_points, suma_par);
            }
            start = next;
        }
        cout << max_points << endl;
    
    }
}