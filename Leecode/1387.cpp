//
// Created by GreenArrow on 2020/8/4.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:

    int number[1000010];

    int getRoad(int numb) {
        if (numb == 1) {
            number[1] = 0;
            return number[1];
        }
        if (number[numb] != -1) {
            return number[numb];
        }
        int num = numb;
        if (num % 2 == 0) {
            num /= 2;
            if (number[num] == -1)
                number[numb] = getRoad(num) + 1;
            else
                number[numb] = number[num] + 1;
            return number[numb];
        } else {
            num = num * 3 + 1;
            if (number[num] == -1)
                number[numb] = getRoad(num) + 1;
            else
                number[numb] = number[num] + 1;
            return number[numb];
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> result;
        for (int i = lo; i <= hi; i++) {
            number[i] = getRoad(i);
            result.emplace_back(number[i], i);
        }

        sort(result.begin(), result.end());
        return result[k - 1].second;
    }

    Solution() {
        fill(number, number + 1000010, -1);
    }
};


int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int lo = stringToInteger(line);
        getline(cin, line);
        int hi = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().getKth(lo, hi, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}