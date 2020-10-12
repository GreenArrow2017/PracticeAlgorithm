//
// Created by GreenArrow on 2020/10/5.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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

    int countor[10] = {0};

    int pseudoPalindromicPaths(TreeNode *root) {
        return dfs(root);
    }

    int check_pesudo() {
        int odd = 0;
        for (int i = 0; i <= 9; i++) {
            if (countor[i] & 1) {
                odd++;
            }
        }
        if (odd <= 1) {
            return 1;
        }
        return 0;
    }

    int dfs(TreeNode *root) {

        if (!root) {
            return 0;
        }
        countor[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            int ret = check_pesudo();
            return ret;
        }
        int ret = 0;
        if (root->left) {
            ret += dfs(root->left);
        }
        if (root->right) {
            ret += dfs(root->right);
        }
        countor[root->val]--;
        return ret;
    }
};