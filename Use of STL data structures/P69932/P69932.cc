#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    string input;

    while (getline(cin, input)) {
        istringstream iss(input); 
        int num, counter = 0;
        set<int> s;
        
        while (iss >> num) s.insert(num);
        
        set<int>::const_iterator it = s.begin();
        bool is_even = false;
        while (it != s.end()) {
            if (it == s.begin()) {
                ++counter;
                is_even = *it%2 == 0;
            }else if (is_even and *it%2 != 0) {
                ++counter;
                is_even = false;
            }else if (not is_even and *it%2 == 0) {
                ++counter;
                is_even = true;
            }
            ++it;
        }
        
        cout << counter << endl;
    }
}