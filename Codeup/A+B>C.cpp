//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string results[n];
        int index = 0;
        for (int i = 0; i < n; ++i) {
            long long A, B, C;
            cin >> A >> B >> C;
            string result;
            if (A + B > C) {
                result = "true";
            } else {
                result = "false";
            }
            results[index++] = result;
        }
        for (int j = 0; j < index; ++j) {
            cout << "Case #" << j + 1 << ": " << results[j] << endl;
        }
    }
}
