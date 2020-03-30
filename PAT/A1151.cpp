//
// Created by GreenArrow on 2020/3/15.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int preOrder[n];
    int inOrder[n];

    map<int, int> positionPre, positionIn;

    for (int i = 0; i < n; ++i) {
        cin >> inOrder[i];
        positionIn[inOrder[i]] = i;
    }

    for (int j = 0; j < n; ++j) {
        cin >> preOrder[j];
        positionPre[preOrder[j]] = j;
    }

    for (int k = 0; k < m; ++k) {

        int a, b;
        cin >> a >> b;

        int aIndex = -1;
        int bIndex = -1;
        int aPreIndex = -1;
        int bPreIndex = -1;

        if (positionIn.count(a)) {
            aIndex = positionIn[a];
        }
        if (positionIn.count(b)) {
            bIndex = positionIn[b];
        }

        if (aIndex == -1 && bIndex == -1) {
            cout << "ERROR: " << a << " and " << b << " are not found." << endl;
            continue;
        } else if (aIndex != -1 && bIndex == -1) {
            cout << "ERROR: " << b << " is not found." << endl;
            continue;
        } else if (aIndex == -1) {
            cout << "ERROR: " << a << " is not found." << endl;
            continue;
        }

        if (a == b) {
            cout << a << " is an ancestor of " << b << "." << endl;
            continue;
        }


        for (int i = 0; i < n; ++i) {
            int temp = preOrder[i];
            int inPosition = positionIn[temp];

            if (temp == a) {
                cout << a << " is an ancestor of " << b << "." << endl;
                break;
            } else if(temp == b){
                cout << b << " is an ancestor of " << a << "." << endl;
                break;
            }

            if(inPosition > aIndex && inPosition < bIndex){
                cout << "LCA of " << a << " and " << b << " is " << temp << "." << endl;
                break;
            } else if(inPosition > bIndex && inPosition < aIndex){
                cout << "LCA of " << a << " and " << b << " is " << temp << "." << endl;
                break;
            }
        }

//        map<int, bool> map_match;
//
//        int first, second;
//
//        if (aIndex > bIndex) {
//            first = bIndex;
//            second = aIndex;
//        } else {
//            first = aIndex;
//            second = bIndex;
//        }
//
//        for (int j = first; j <= second; ++j) {
//            map_match[inOrder[j]] = true;
//        }
//
//        for (int l = 0; l <= aPreIndex && l <= bPreIndex; ++l) {
//            if (map_match[preOrder[l]]) {
//                if (preOrder[l] != a && preOrder[l] != b) {
//                    cout << "LCA of " << a << " and " << b << " is " << preOrder[l] << "." << endl;
//                    break;
//                } else if (preOrder[l] == a) {
//                    cout << a << " is an ancestor of " << b << "." << endl;
//                    break;
//
//                } else if (preOrder[l] == b) {
//                    cout << b << " is an ancestor of " << a << "." << endl;
//                    break;
//
//                }
//            }
//        }

    }
}
