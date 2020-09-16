//
// Created by GreenArrow on 2020/9/16.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        exchange(root);
        return root;
    }

    void exchange(TreeNode * root){
        if(root){
            exchange(root->left);
            exchange(root->right);
            TreeNode * temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }
};
