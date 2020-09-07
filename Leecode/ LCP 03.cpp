//
// Created by GreenArrow on 2020/8/11.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class Solution {
public:


    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
        int x_size = 0, y_size = 0;
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'U') {
                y_size++;
            } else
                x_size++;
        }
        for (int i = 0; i < obstacles.size(); i++) {
            
        }
    }
};