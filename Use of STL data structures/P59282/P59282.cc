#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int,int> numbers;
    string command;
    map<int,int>::iterator it;
    int num, counter = 0;
    double average = 0;

    cout.setf(ios::fixed);
    cout.precision(4);

    while (cin >> command) {
        if (command == "number") {
            cin >> num;
            it = numbers.find(num);
            average += num;
            ++counter;

            if (it == numbers.end()) {
                numbers.insert(make_pair(num, 1));
            }else {
                it->second += 1;
            }

        }else {
            it = numbers.begin();

            if (it != numbers.end()) {
                average -= it->first;
                counter--;
                if (it->second > 1) it->second -= 1;
                else numbers.erase(it);
            }
        }

        if (numbers.size() == 0) cout << "no elements" << endl;
        else cout << "minimum: " << numbers.begin()->first << ", maximum: " << (--numbers.end())->first << ", average: " << double(average/counter) << endl;

    }
}