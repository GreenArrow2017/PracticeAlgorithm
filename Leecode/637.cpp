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

    vector<double> depths;
    vector<double> depths_num;

    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<TreeNode *, double>> q;
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

        vector<double> results;

        results.resize(depths.size());

        for(int i = 0;i < depths.size();i++){
            results[i] = (double)depths[i] / (double)depths_num[i];
        }

        return results;

    }
};