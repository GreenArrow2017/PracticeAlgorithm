//
// Created by GreenArrow on 2020/3/8.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int n, m;
    int pre[10010];
    map<int, bool> isExist;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> pre[i];
        isExist[pre[i]] = true;
    }

    for (int j = 0; j < n; ++j) {

        int a, b;
        cin >> a >> b;
        int an;
        for (int i = 0; i < m; ++i) {
            an = pre[i];
            if (an >= a && an <= b)
                break;
            else if (an <= a && an >= b)
                break;
        }

        if (!isExist[a] && !isExist[b]) {
            cout << "ERROR: " << a << " and " << b << " are not found." << endl;
            continue;
        } else if (!isExist[a] && isExist[b]) {
            cout << "ERROR: " << a << " is not found." << endl;
            continue;
        } else if (isExist[a] && !isExist[b]) {
            cout << "ERROR: " << b << " is not found." << endl;
            continue;
        }


        if (an == a) {
            cout << an << " is an ancestor of " << b << "." << endl;
            continue;
        }

        if (an == b) {
            cout << an << " is an ancestor of " << a << "." << endl;
            continue;
        }

        cout << "LCA of " << a << " and " << b << " is " << an << "." << endl;

    }
}
