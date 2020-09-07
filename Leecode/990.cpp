
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    int father[50];

    bool equationsPossible(vector<string> &equations) {

        for (int i = 0; i < 50; i++) {
            father[i] = i;
        }

        vector<string> inequality;
        for (int i = 0; i < equations.size(); i++) {
            string s = equations[i];
            string opera = s.substr(1, 2);
            if (opera == "!=") {
                inequality.push_back(s);
                continue;
            }
            int x = (s[0] - 'a');
            int y = (s[s.length() - 1] - 'a');
            connected(x, y);
        }

        for (int i = 0; i < inequality.size(); i++) {
            string s = inequality[i];
            int x = (s[0] - 'a');
            int y = (s[s.length() - 1] - 'a');
            if (search(x) == search(y)) {
                return false;
            }
        }
        return true;

    }

    void connected(int a, int b) {
        int x = search(a), y = search(b);
        if (x != y) {
            father[x] = y;
        }
    }

    int search(int root) {
        int son, temp;
        son = root;
        while (root != father[root]) {
            root = father[root];
        }
        while (son != root) {
            temp = father[son];
            father[son] = root;
            son = temp;
        }
        return root;
    }
};

int main(){
    Solution solution;
    vector<string> test = {"a==b","b!=a"};
    cout << solution.equationsPossible(test);
}