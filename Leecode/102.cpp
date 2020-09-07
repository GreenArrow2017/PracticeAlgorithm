//
// Created by GreenArrow on 2020/7/29.
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
    vector<vector<int>> levelOrder(TreeNode *root) {

        vector<vector<int>> result;


        if(root == NULL){
            return result;
        }
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            TreeNode *currentNode = current.first;
            int depth = current.second;

            if (result.size() >= depth + 1) {
                result[depth].push_back(currentNode->val);
            } else {
                vector<int> *n = new vector<int>(0);
                result.push_back(*n);
                result[depth].push_back(currentNode->val);
            }

            if (currentNode->left) {
                q.push({currentNode->left, depth + 1});
            }
            if (currentNode->right) {
                q.push({currentNode->right, depth + 1});
            }
        }
        return result;
    }
};