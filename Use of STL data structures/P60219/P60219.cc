#include<iostream>
#include<set>
using namespace std;

struct compare {
    bool operator()(const string &a, const string &b) {
        if (a.size() == b.size()) return a<b;
        else return a.size() < b.size();
    }
};

void print_sets(const set<string> &has, const set<string, compare> &had, const int &c) {
    set<string>::iterator it_has = has.begin();
    set<string, compare>::iterator it_had = had.begin();

    if (c > 1) cout << endl;

    cout << "GAME #" << c << endl << "HAS:" << endl;

    while (it_has != has.end()) {
        cout << *it_has << endl;
        ++it_has;
    }

    cout << endl << "HAD:" << endl;

    while (it_had != had.end()) {
        cout << *it_had << endl;
        ++it_had;
    }

}

int main() {
    set<string> has;
    set<string, compare> had;
    set<string>::iterator it_has;
    set<string, compare>::iterator it_had;
    string input;
    int counter = 1;
    while (cin >> input and input != "QUIT") {
        if (input == "END") {
            
            print_sets(has, had, counter);

            has.clear();
            had.clear();
            ++counter;
        }else {
            if (has.find(input) != has.end()) {
				has.erase(input);
				had.insert(input);
			} else {
				has.insert(input);
				had.erase(input);
			}
        }
    }

    print_sets(has, had, counter);
}