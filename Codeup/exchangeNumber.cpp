//
// Created by GreenArrow on 2020/2/11.
//

/**
 * 进制转换
 */

#include <iostream>

using namespace std;

int main() {
    long a, b;
    string s;
    while (cin >> a >> s >> b) {
        long sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                sum = ((s[i] - '0') + a * sum);
            else if (s[i] >= 'A' && s[i] <= 'F')
                sum = ((s[i] - 'A') + a * sum + 10);
            else if (s[i] >= 'a' && s[i] <= 'f')
                sum = ((s[i] - 'a') + a * sum + 10);
        }

        char arr[2000], index = 0;
        do {
            int p = sum % b;
            arr[index++] = ((p < 10) ? (p + '0') : ((p - 10) + 'A'));
            sum /= b;
        } while (sum > 0);

        for (int j = index-1; j >= 0; --j) {
            cout << arr[j];
        }
        cout << endl;
    }
}

