//
// Created by GreenArrow on 2020/8/28.
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
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode *current = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (result.size() < depth + 1) {
                vector<int> n;
                result.push_back(n);
            }
            result[depth].push_back(current->val);

            if (current->left)
                q.push({current->left, depth + 1});
            if (current->right)
                q.push({current->right, depth + 1});
        }
        result.assign(result.rbegin(), result.rend());
        return result;
    }
};