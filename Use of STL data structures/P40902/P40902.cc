#include <iostream> 
#include <iterator>
#include <map> 
  
using namespace std; 
  
int main() {
    string person, command;
    map <string, int> casino;

    while (cin >> person >> command) {
        map<string, int>::iterator it = casino.find(person);
        if (command == "enters") {
            if (it == casino.end()) casino.insert(make_pair(person, 0));
            else cout << person << " is already in the casino" << endl;
        }else if (command == "wins") {
            int num; cin >> num;
            if (it != casino.end()) casino[person] += num;
            else cout << person << " is not in the casino" << endl;
        }else if (command == "leaves") {
            if (it != casino.end()) {
                cout << person << " has won " << it->second << endl;
                it = casino.erase(it);
            } else cout << person << " is not in the casino" << endl;
        }
    }
    cout << "----------" << endl;
    map<string, int>::iterator it = casino.begin();

    while (it != casino.end()) {
        cout << it->first << " is winning " << it->second << endl;
        it = casino.erase(it);
    }

}