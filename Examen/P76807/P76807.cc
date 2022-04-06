#include <iostream>
#include <vector>
using namespace std;

vector<vector< pair<int,vector<bool>> >> sudoku(9, vector< pair<int,vector<bool>> >(9));

void print_sudoku() {
    cout << endl;
    for (int i = 0; i < 9; ++i) {
        if (sudoku[i][0].first != -1) cout << sudoku[i][0].first;
        else cout << '.';
        
        for (int j = 1; j < 9; ++j) {
            if (sudoku[i][j].first != -1) cout << ' ' << sudoku[i][j].first;
            else cout << " .";
        }
        cout << endl;
    }
}

void check_around(int i, int j) {
    for (int a = 0; a < 9; ++a) {
        if (sudoku[a][j].first > 0 and sudoku[i][j].second[ sudoku[a][j].first-1 ]) {
            sudoku[i][j].second[ sudoku[a][j].first-1 ] = false;
            ++sudoku[i][j].first;
        }
        if (sudoku[i][a].first > 0 and sudoku[i][j].second[ sudoku[i][a].first-1 ]) {
            sudoku[i][j].second[ sudoku[i][a].first-1 ] = false;
            ++sudoku[i][j].first;
        }
    }
    int ii = i/3;
    int jj = j/3;

    for (int a = ii*3; a < (ii+1)*3; ++a) {
        for (int b = jj*3; b < (jj+1)*3; ++b) {
            if (sudoku[a][b].first > 0 and sudoku[i][j].second[ sudoku[a][b].first-1 ]) {
                sudoku[i][j].second[ sudoku[a][b].first-1 ] = false;
                ++sudoku[i][j].first;
            }
        }
    }
}

/*bool other_opt(int i, int j, int x) {
    int ii = i/3;
    int jj = j/3;

    for (int a = ii*3; a < (ii+1)*3; ++a) {
        for (int b = jj*3; b < (jj+1)*3; ++b) {
            if ((a != i or b != j) and sudoku[a][b].second[x]) return true;
        }
    }
    return false;
}*/

bool its_alone(int i, int j, int x) {
    bool state1 = true;
    bool state2 = true;

    for (int a = 0; a < 9; ++a) {
        if (sudoku[a][j].second[x] and a/3 != i/3) {
            state1 = false;
        }
        if (sudoku[i][a].second[x] and a/3 != j/3) {
            state2 = false;
        }
    }
    return state1 and state2;
}

void init_sudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudoku[i][j].first <= 0) {
                check_around(i, j);
            }
        }
    }
}

void update_candidatos(int i, int j, int x) {
    for (int a = 0; a < 9; ++a) {
        if (sudoku[a][j].second[x] and sudoku[a][j].first < 0) {
            sudoku[a][j].second[x] = false;
            ++sudoku[a][j].first;
        }
        if (sudoku[i][a].second[x] and sudoku[i][a].first < 0) {
            sudoku[i][a].second[x] = false;
            ++sudoku[i][a].first;
        }
    }
    int ii = i/3;
    int jj = j/3;

    for (int a = ii*3; a < (ii+1)*3; ++a) {
        for (int b = jj*3; b < (jj+1)*3; ++b) {
            if (sudoku[a][b].second[x] and sudoku[a][b].first < 0) {
                sudoku[a][b].second[x] = false;
                ++sudoku[a][b].first;
            }
        }
    }
}

void solve_sudoku(int unsolved_cell) {
    init_sudoku();
    bool special = false;
    while (unsolved_cell > 0) {
        bool found_one = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (not special and sudoku[i][j].first == -1) {
                    int k = 0;
                    while (not sudoku[i][j].second[k]) ++k;

                    sudoku[i][j].first = k+1;
                    update_candidatos(i, j, k);
                    --unsolved_cell;
                    found_one = true;

                    /*cout << char('A' + i) << j + 1 << endl;
                    print_sudoku();
                    cout << unsolved_cell << endl;*/
                }else if (special and sudoku[i][j].first < 0) {
                    for (int k = 0; k < 9; ++k) {
                        if(sudoku[i][j].second[k] and its_alone(i, j, k)) {
                            sudoku[i][j].first = k+1;
                            update_candidatos(i, j, k);
                            --unsolved_cell;
                            found_one = true;
                            special = false;

                            cout << char('A' + i) << j + 1 << endl;
                            print_sudoku();
                            cout << unsolved_cell << endl;
                        }
                    }
                }
            }
        }
        if (not found_one) special = true;
    }
}

int main() {
    int n;
    cin >> n;
    //cout << n;

    for (int i = 0; i < n; ++i) {
        int unsolved_cell = 0;
        for (int ii = 0; ii < 9; ++ii) {
            for (int iii = 0; iii < 9; ++iii) {
                char temp;
                cin >> temp;

                if (temp == '.')  {
                    sudoku[ii][iii] = make_pair(-9, vector<bool>(9,1));
                    ++unsolved_cell;
                }else sudoku[ii][iii] = make_pair(temp - '0', vector<bool>(9,0));
            }
        }
        solve_sudoku(unsolved_cell);
        print_sudoku();
    }
}