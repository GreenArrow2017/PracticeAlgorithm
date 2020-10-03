//
// Created by GreenArrow on 2020/10/3.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<int> maxValues;

    vector<int> largestValues(TreeNode *root) {

        queue<pair<TreeNode *, int>> queues;
        queues.push({root, 0});

        if(!root){
            return maxValues;
        }

        while (!queues.empty()) {
            TreeNode *current = queues.front().first;
            int depth = queues.front().second;
            queues.pop();

            if (maxValues.size() < depth + 1) {
                maxValues.push_back(current->val);
            } else {
                maxValues[depth] = maxValues[depth] > current->val ? maxValues[depth] : current->val;
            }

            if (current->left) {
                queues.push({current->left, depth + 1});
            }
            if (current->right) {
                queues.push({current->right, depth + 1});
            }
        }

        return maxValues;

    }
};
