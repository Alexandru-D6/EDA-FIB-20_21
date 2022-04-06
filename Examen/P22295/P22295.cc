#include <iostream>
#include <vector>
using namespace std;

vector<char> word;
int actual_size = 0;

const vector<int> moves_Y = { 1, 0,-1, 0};
const vector<int> moves_X = { 0, 1, 0,-1};

void print_word(const vector<char>& word, const int& actual_size) {
    for (int i = 0; i < actual_size; ++i) cout << word[i];
    cout << endl;
}

bool pos_ok(const pair<int,int>& next_pos, const int& first, const int& second) {
    return (next_pos.first >= 0 and next_pos.first < first and next_pos.second >= 0 and next_pos.second < second);
}

void backtracking(const vector< vector<char> >& mapa, vector< vector<bool> >& vistos, const pair<int,int>& actual_pos, const pair<int,int>& last_pos) {
    if (actual_pos == last_pos) {
        print_word(word, actual_size);
        return;
    }else {
        for (int i = 0; i < 4; ++i) {
            pair<int,int> next_pos = actual_pos;
            next_pos.first += moves_Y[i];
            next_pos.second += moves_X[i];
            if (pos_ok(next_pos, mapa.size(), mapa[0].size()) and vistos[next_pos.first][next_pos.second] == false ) {
                vistos[next_pos.first][next_pos.second] = true;
                word[actual_size] = mapa[next_pos.first][next_pos.second];
                ++actual_size;
                backtracking(mapa, vistos, next_pos, last_pos);
                vistos[next_pos.first][next_pos.second] = false;
                --actual_size;
            }
        }
    }
}

int main() {
    pair<int,int> size;
    cin >> size.first >> size.second;
    word = vector<char>(size.first*size.second);

    vector< vector<char> > mapa(size.first, vector<char>(size.second));
    vector< vector<bool> > vistos(size.first, vector<bool>(size.second, false));

    for (int i = 0; i < size.first; ++i) {
        for (int j = 0; j < size.second; ++j) cin >> mapa[i][j];
    }

    pair<int,int> init_pos;
    cin >> init_pos.first >> init_pos.second;
    pair<int,int> last_pos;
    cin >> last_pos.first >> last_pos.second;

    vistos[init_pos.first][init_pos.second] = true;
    word[actual_size] = mapa[init_pos.first][init_pos.second];
    ++actual_size;
    backtracking(mapa, vistos, init_pos, last_pos);

}