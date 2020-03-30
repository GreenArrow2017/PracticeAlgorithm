//
// Created by GreenArrow on 2020/3/5.
//
#include <iostream>
#include <list>

using namespace std;
list<int>::iterator pos[100010];
bool isExited[100010] = {false};

int main() {
    int n;
    cin >> n;
    list<int> Queue;
    if (n > 0) {
        Queue.push_back(1);
        pos[1] = Queue.begin();
        isExited[1] = true;
    }
    for (int i = 2; i <= n; ++i) {
        int num, position;
        cin >> num >> position;
        if (position == 0) {
            pos[i] = Queue.insert(pos[num], i);
        } else {
            auto nextIter = next(pos[num]);
            pos[i] = Queue.insert(nextIter, i);
        }
        isExited[i] = true;
    }

    int m;
    cin >> m;
    for (int k = 0; k < m; ++k) {
        int number;
        cin >> number;
        if (isExited[number]) {
            Queue.erase(pos[number]);
            isExited[number] = false;
        }
    }

    for (int val : Queue) {
        cout << val << " ";
    }
}
