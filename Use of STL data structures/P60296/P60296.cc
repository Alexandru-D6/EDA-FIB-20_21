#include <iostream>
#include <map>
#include <set>
using namespace std;

struct compare {
	bool operator() (const pair <string, int> &a, const pair <string, int> &b) const {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

void ranking(const map<string,int> &a) {
    set<pair<string, int>, compare> b;
    map<string, int>::const_iterator it = a.begin();

    while (it != a.end()) {
        b.insert(make_pair(it->first, it->second));
        ++it;
    }

    set<pair<string, int>>::const_iterator it2 = b.begin();

    cout << endl << "RANKING" << endl; 
    while (it2 != b.end()) {
        cout << it2->first << ' ' << it2->second << endl;
        ++it2;
    }
}

int main() {
    map<string, int> players;
    map<string, int>::const_iterator it;
    set<string> connected;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "LOGIN") {
            string player; cin >> player;
            players.insert(make_pair(player,1200));
            connected.insert(player);
        }else if (cmd == "LOGOUT") {
            string player; cin >> player;
            connected.erase(player);
        }else if (cmd == "PLAY") {
            string p1, p2; cin >> p1 >> p2;

            if (connected.find(p1) != connected.end() and connected.find(p2) != connected.end()) {
                players.find(p1)->second += 10;
                if (players.find(p2)->second >= 1210) players.find(p2)->second -= 10;
            }else cout << "player(s) not connected" << endl;
        }else if (cmd == "GET_ELO") {
            string player; cin >> player;

            if (players.find(player) != players.end()) cout << player << ' ' << players.find(player)->second << endl;
        }
    }

    ranking(players);
}