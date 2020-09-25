//
// Created by GreenArrow on 2020/9/25.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0){
            return nullptr;
        }
        return createTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *createTree(vector<int> &inorder, vector<int> &postorder, int inL, int inR, int postL, int postR) {

        if(inL > inR){
            return nullptr;
        }

        int root_index = postorder[postR];
        int in_index = -1;
        for (int i = inL; i <= inR; i++) {
            if (inorder[i] == root_index) {
                in_index = i;
            }
        }
        int num = in_index - inL;
        TreeNode *r = new TreeNode(root_index);
        if (inL == inR) {
            return r;
        }
        r->left = createTree(inorder, postorder, inL, in_index - 1, postL, postL + num - 1);
        r->right = createTree(inorder, postorder, in_index + 1, inR, postL + num, postR - 1);
        return r;
    }
};
