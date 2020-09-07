//
// Created by GreenArrow on 2020/7/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:

    int move[2][2] = {
            {0,  1},
            {1,  0},
    };

    bool inside(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    class cordinate {
    public:
        int x;
        int y;

        cordinate(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    int uniquePaths(int m, int n) {
        vector<vector<bool>> maps;
        for (int i = 0; i < m; i++) {
            vector<bool> element;
            maps.push_back(element);
            for (int j = 0; j < n; j++) {
                maps[i].push_back(false);
            }
        }
        cordinate beginning(0, 0);
        cordinate ending(m - 1, n - 1);

        int count = 0;
        calculate(beginning, ending, maps, m, n, count);
        return count;

    }

    void calculate(cordinate beginning, cordinate ending, vector<vector<bool>> &maps, int m, int n, int &count) {
        maps[beginning.x][beginning.y] = true;
        //cout << beginning.x << " " << beginning.y << endl;
        if (ending.x == beginning.x && ending.y == beginning.y) {
            count++;
            maps[beginning.x][beginning.y] = false;
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (inside(beginning.x + move[i][0], beginning.y + move[i][1], m, n) &&
                !maps[beginning.x + move[i][0]][beginning.y + move[i][1]]) {
                cordinate next(beginning.x + move[i][0], beginning.y + move[i][1]);
                calculate(next, ending, maps, m, n, count);
            }
        }
        maps[beginning.x][beginning.y] = false;
    }


};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}