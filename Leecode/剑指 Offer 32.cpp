//
// Created by GreenArrow on 2020/7/26.
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

    class TreeAndDepth {
    public:
        TreeNode *node;
        int Depth;
    };

    vector<vector<int>> levelOrder(TreeNode *root) {




        vector<vector<int>> result;

        if(root == nullptr){
            return result;
        }

        TreeAndDepth *treeAndDepth = new TreeAndDepth;
        treeAndDepth->node = root;
        treeAndDepth->Depth = 0;

        queue<TreeAndDepth *> q;

        q.push(treeAndDepth);

        while (!q.empty()) {
            TreeAndDepth *current = q.front();
            q.pop();
            if (result.size() < current->Depth + 1) {
                vector<int> p;
                p.push_back(current->node->val);
                result.push_back(p);
            } else {
                result[current->Depth].push_back(current->node->val);
            }

            if(current->node->left){
                TreeAndDepth * left = new TreeAndDepth;
                left->node = current->node->left;
                left->Depth = current->Depth + 1;
                q.push(left);
            }

            if(current->node->right){
                TreeAndDepth * right = new TreeAndDepth;
                right->node = current->node->right;
                right->Depth = current->Depth + 1;
                q.push(right);
            }
        }

        return result;
    }
};