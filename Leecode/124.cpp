//
// Created by GreenArrow on 2020/7/25.
//

/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {

        int value = INT_MIN;

        maxValue(root, value);

        return value;

    }

    int maxValue(TreeNode *root, int &value) {
        if (root == NULL) {
            return 0;
        }

        int left = max(maxValue(root->left, value), 0);
        int right = max(maxValue(root->right, value), 0);
        int rel = root->val + max(left, right);
        int lmr = root->val + left + right;
        value = max(value, max(rel, lmr));
        return rel;
    }


};

//#define MAX 1000
//map<int, int> node_value;
//int graph[MAX][MAX] = {0};

//class Solution {
//public:
//
//    class TreenodeAndIndex {
//    public:
//        TreeNode *root;
//        int parent;
//
//        TreenodeAndIndex(TreeNode *root_, int parent_) : root(root_), parent(parent_) {}
//
//        TreenodeAndIndex() {}
//    };
//
//    int maxPathSum(TreeNode *root) {
//        int maxValue = INT_MIN;
//
//        for (int i = 0; i < MAX; i++) {
//            fill(graph[i], graph[i] + MAX, 0);
//        }
//
//        int lenght = tree2graph(root);
//        bool visited[MAX];
//        fill(visited, visited + MAX, false);
//        for (int i = 0; i < lenght; i++) {
//            getMaxRout(lenght, i, visited, node_value[i], maxValue);
//        }
//        return maxValue;
//    }
//
//    void getMaxRout(int length, int v, bool *visited, int result, int &maxValue) {
//        visited[v] = true;
//        if (result > maxValue) {
//            maxValue = result;
//        }
//        for (int i = 0; i < length; i++) {
//            if (graph[v][i] && !visited[i]) {
//                getMaxRout(length, i, visited, result + node_value[i], maxValue);
//            }
//        }
//        visited[v] = false;
//    }
//
//    int tree2graph(TreeNode *root) {
//        int index = -1;
//
//
//        queue<TreenodeAndIndex> q;
//        TreenodeAndIndex node(root, index);
//        q.push(node);
//        while (!q.empty()) {
//            TreenodeAndIndex current;
//            current = q.front();
//            node_value[++index] = (current.root)->val;
//            q.pop();
//
//            if (current.parent != -1) {
//                graph[current.parent][index] = 1;
//                graph[index][current.parent] = 1;
//            }
//            if ((current.root)->right != nullptr) {
//                TreenodeAndIndex right((current.root)->right, index);
//                q.push(right);
//            }
//            if ((current.root)->left != nullptr) {
//                TreenodeAndIndex left((current.root)->left, index);
//                q.push(left);
//            }
//        }
//
//        return index + 1;
//
//    }
//};

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

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        int ret = Solution().maxPathSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
