//
// Created by GreenArrow on 2020/7/27.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int depth = 0;
    int sums[1000] = {0};

    class TreeAndDepth {
    public:
        TreeNode *tree;
        int depth;

        TreeAndDepth(TreeNode *tree, int Depth) {
            this->tree = tree;
            this->depth = Depth;
        }
    };

    int deepestLeavesSum(TreeNode *root) {

        TreeAndDepth *node = new TreeAndDepth(root, 0);

        queue<TreeAndDepth *> q;

        q.push(node);
        while (!q.empty()) {
            TreeAndDepth *current = q.front();
            q.pop();
            sums[current->depth] += current->tree->val;
            depth = current->depth;
            if (current->tree->left) {
                TreeAndDepth *left = new TreeAndDepth(current->tree->left, current->depth + 1);
                q.push(left);
            }
            if(current->tree->right){
                TreeAndDepth *right = new TreeAndDepth(current->tree->right, current->depth + 1);
                q.push(right);
            }
        }
        return sums[depth];
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

        int ret = Solution().deepestLeavesSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}