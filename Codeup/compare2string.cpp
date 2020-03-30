//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {

            string a, b;
            cin >> a >> b;
            if (a.length() > b.length()) {
                cout << a << " is longer than " << b << endl;
            } else if(a.length() == b.length())
                cout << a << " is equal long to " << b << endl;
            else if(a.length() < b.length())
                cout << a << " is shorter than " << b << endl;

        }
    }
}
