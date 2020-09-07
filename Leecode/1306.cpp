//
// Created by GreenArrow on 2020/8/10.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> dis;
    vector<bool> visited;

    bool canReach(vector<int> &arr, int start) {


        int min = 0, max = arr.size();

        dis.resize(max);

        visited.resize(max);

        fill(visited.begin(), visited.end(), false);

        fill(dis.begin(), dis.end(), INT_MAX);

        vector<vector<int>> Graph(max);


        for (int i = 0; i < arr.size(); i++) {

            if (i + arr[i] >= 0 && i + arr[i] < max) {
                Graph[i].push_back(i + arr[i]);
            }
            if (i - arr[i] >= 0 && i - arr[i] < max) {
                Graph[i].push_back(i - arr[i]);
            }
        }


        return dfs(start, max, Graph, arr);


    }

    bool dfs(int v, int n, vector<vector<int>> &Graph, vector<int> &arr) {
        visited[v] = true;
        for (int i = 0; i < Graph[v].size(); i++) {
            int w = Graph[v][i];

            if (!arr[w]) {
                return true;
            }

            if (!visited[w]) {
                if (dfs(w, n, Graph, arr)) {
                    return true;
                }
            }
        }
        visited[v] = false;
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int start = stringToInteger(line);

        bool ret = Solution().canReach(arr, start);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}