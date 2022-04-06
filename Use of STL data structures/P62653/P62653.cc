#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string w;
struct compare {
    bool operator()(const string &a, const string &b) const{
        if (a.length() == b.length()) {
            string first_word = w.substr(0, a.length());

            if (a == first_word) return false;
            else if (b == first_word) return true;
            if (a > first_word and b > first_word or a < first_word and b < first_word) return a > b;
            else return (a < first_word);

        } else return a.length() > b.length();
    }
};

int main() {
    while (cin >> w) {
        priority_queue<string,vector<string>,compare> s;

        char cmd;
        int tickets_ava = 0;

        while (cin >> cmd and cmd != 'E') {
            if (cmd == 'T') {
                if (s.empty()) {
                    ++tickets_ava;
                }else {
                    cout << s.top() << endl;
                    s.pop();
                }
            }else if (cmd == 'S') {
                string supporter; cin >> supporter;
                if (tickets_ava) {
                    cout << supporter << endl;
                    --tickets_ava;
                }else {
                    s.push(supporter);
                }
            }
        }

        cout << tickets_ava << " ticket(s) left" << endl;
        cout << s.size() << " supporter(s) with no ticket" << endl << endl;
    }

}