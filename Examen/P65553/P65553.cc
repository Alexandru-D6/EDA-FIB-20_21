#include <iostream>
#include <map>
using namespace std;

void print(const map<string,int>& coleccion) {
    map<string,int>::const_iterator it = coleccion.begin();
    
    while (it != coleccion.end()) {
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}

int main() {
    int n;

    while (cin >> n) {
        map<string,int> coleccion;
        map<string,int>::iterator it = coleccion.end();
        int total_games = 0;

        for (int i = 0; i < n; ++i) {
            string game; cin >> game;
            it = coleccion.find(game);

            if (it == coleccion.end()) {
                coleccion.insert(make_pair(game, 1));
            }else {
                it->second += 1;
            }
            ++total_games;
        }

        cin >> n;

        for (int i = 0; i < n; ++i) {
            string game; cin >> game;
            it = coleccion.find(game);

            if (it == coleccion.end() and total_games > 0) {
                coleccion.insert(make_pair(game, 1));
                ++total_games;
            }else if (it->second < total_games-(it->second)){
                it->second += 1;
                ++total_games;
            }
        }

        print(coleccion);

        for (int i = 0; i < 20; ++i) cout << '-';
        cout << endl;
    }

}