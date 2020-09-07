//
// Created by GreenArrow on 2020/8/2.
//

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:
    int numberOf2sInRange(int n) {



    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().numberOf2sInRange(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}