#include<iostream>
#include<set>
using namespace std;

int main() {
    set<string> words;
    set<string>::const_iterator it;
    string input;

    while(cin >> input and input != "END") {
        words.insert(input);
        if (words.size() == 1) it = words.begin();
        else if (input < *it and words.size()%2 == 0) --it;
        else if (input > *it and words.size()%2 != 0) ++it;
        cout << *it << endl;
    }

}