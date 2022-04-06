#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string,int> m;
    map<string,int>::iterator it;
    string command;

    while (cin >> command) {
        if (command == "minimum?") {
            if (m.begin() == m.end()) cout << "indefinite minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }else if (command == "maximum?") {
            if (m.begin() == m.end()) cout << "indefinite maximum" << endl;
            else {
                it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }else if (command == "delete") {
            string word; cin >> word;
            it = m.find(word);

            if (it != m.end() and it->second != 1) --it->second;
            else if (it != m.end() and it->second == 1) m.erase(it);
        }else if (command == "store") {
            string word; cin >> word;
            it = m.find(word);

            if (it == m.end()) m.insert(make_pair(word, 1));
            else if (it != m.end()) ++it->second;
        }
    }
}