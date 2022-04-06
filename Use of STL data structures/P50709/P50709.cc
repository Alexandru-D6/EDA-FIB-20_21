#include<iostream>
#include<queue>
using namespace std;

int main() {
    char command;
    priority_queue<int> list;

    while(cin >> command) {
        if (command == 'S') {
            int num; cin >> num;
            list.push(num);
        }else if (command == 'A') {
            if (not list.empty()) cout << list.top() << endl;
            else cout << "error!" << endl;
        }else if (command == 'R') {
            if (not list.empty()) list.pop();
            else cout << "error!" << endl;
        }else if (command == 'I') {
            int num; cin >> num;
            if (not list.empty()) {
                num += list.top();
                list.pop();
                list.push(num);
            }else cout << "error!" << endl;
        }else if (command == 'D') {
            int num; cin >> num;
            if (not list.empty()) {
                num = list.top() - num;
                list.pop();
                list.push(num);
            }else cout << "error!" << endl;
        }
    }
}