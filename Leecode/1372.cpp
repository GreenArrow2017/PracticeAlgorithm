//
// Created by GreenArrow on 2020/9/12.
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
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLong = 0;

    int longestZigZag(TreeNode *root) {
        if (!root) {
            return 0;
        }

        dfs(root, 0, -1);
        dfs(root, 0, 1);
        return maxLong;
    }

//left = -1, right = 1
    void dfs(TreeNode *root, int depth, int leftOrRight) {
        maxLong = max(depth, maxLong);
        if (root) {
            if (leftOrRight == -1) {
                if (root->right)
                    dfs(root->right, depth + 1, -1 * leftOrRight);
                if (root->left)
                    dfs(root->left, 1, -1);
            }
            if (leftOrRight == 1) {
                if (root->left)

                    dfs(root->left, depth + 1, -1 * leftOrRight);
                if (root->right)

                    dfs(root->right, 1, 1);
            }
        }
    }
};