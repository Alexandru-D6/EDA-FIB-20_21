#include <iostream>
#include <set>
using namespace std;

/*void print_set(const set<unsigned long long int>& joyas) {
    set<unsigned long long int>::const_iterator it = joyas.begin();

    while (it != joyas.end()) {
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
}*/

int main() {
    int n;
    cin >> n;

    string command;
    unsigned long long int value;
    set<unsigned long long int> joyas;
    unsigned long long int suma_act = 0;
    set<unsigned long long int>::iterator it_min = joyas.begin();

    while(cin >> command >> value) {
        if (command == "leave") {
            
            if (joyas.size() < n) {
                joyas.insert(value);
                suma_act += value;
                it_min = joyas.begin();
            }else {
                if (value < *it_min) joyas.insert(value);
                else {
                    suma_act -= *it_min;
                    suma_act += value;
                    joyas.insert(value);
                    ++it_min;
                }
            }

        }else if (command == "take") {
            
            if (joyas.size() <= n) {
                suma_act -= value;
                joyas.erase(value);
                it_min = joyas.begin();
            }else {
                if (value < *it_min) joyas.erase(value);
                else {
                    --it_min;
                    suma_act += *it_min;
                    suma_act -= value;
                    joyas.erase(value);
                }
            }
        }
        //print_set(joyas);
        //cout << "--- " << *it_min << endl;
        cout << suma_act << endl;
    }
}