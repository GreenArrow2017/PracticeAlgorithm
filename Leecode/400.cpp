//
// Created by GreenArrow on 2020/7/28.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

//1-9  10-99 99-10+1 = 90 100-999 999-100 +1 = 900 9, 190, 2700
//2324 1

class Solution {
public:
    int findNthDigit(int n) {

        if (n < 10) {
            return n;
        }

        long long sum = 0;
        int index = 0;
        int digits = 1;
        int base = 9;

        while (n - sum > 0) {
            n -= sum;
            index++;
            //cout << sum << endl;
            sum = (9 * pow(10, index - 1)) * index;
        }


        int position = n % index;
        n /= index;

        n = (int) pow(10, index - 1) + n - 1;

        if (position == 0) {
            return n % 10;
        } else {
            string str = int2string(n + 1);

            char number = str[position - 1];

            return (number - '0');
        }

    }

    string int2string(int n) {
        string result;
        while (n >= 10) {
            result = (char) ((n % 10) + '0') + result;
            n /= 10;
        }
        result = (char) (n + '0') + result;
        return result;
    }

};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().findNthDigit(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
