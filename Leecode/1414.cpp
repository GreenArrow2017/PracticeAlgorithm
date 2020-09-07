//
// Created by GreenArrow on 2020/7/25.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {

        int count = 0;

        vector<int> fibnaciArray;
        fibnaciArray.push_back(1);
        fibnaciArray.push_back(1);
        int index = 1;
        int current = 1;
        while (k > current) {
            current = fibnaciArray[index] + fibnaciArray[index - 1];
            fibnaciArray.push_back(current);
            index++;
        }

        for(int i = index-1;i >= 0;i--){
            if(k >= fibnaciArray[i]){
                k -= fibnaciArray[i];
                count++;
            }
        }

        return count;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int k = stringToInteger(line);

        int ret = Solution().findMinFibonacciNumbers(k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
