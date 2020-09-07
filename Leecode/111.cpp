//
// Created by GreenArrow on 2020/8/21.
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


//Definition for a binary tree node.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int minDepth(TreeNode *root) {

        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode *current = q.front().first;
            int depth = q.front().second;
            if (current->left == NULL && current->right == NULL) {
                return depth;
            }
            q.pop();

            if (current->left) {
                q.push({current->left, depth + 1});
            }
            if (current->right) {
                q.push({current->right, depth + 1});
            }
        }
        return -1;

    }
};