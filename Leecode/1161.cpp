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

    vector<int> depths;
    vector<int> depths_num;

    int maxLevelSum(TreeNode *root) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode *current = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (depths.size() < depth + 1) {
                depths.push_back(0);
                depths_num.push_back(0);
            }
            depths[depth] += current->val;
            depths_num[depth]++;

            if (current->left) {
                q.push({current->left, depth + 1});
            }
            if (current->right) {
                q.push({current->right, depth + 1});
            }
        }

        int index = -1;
        int max = INT_MIN;
        for (int i = 0; i < depths.size(); i++) {
            if (max < depths[i]) {
                max = depths[i];
                index = i;
            }
        }

        return index + 1;
    }
};