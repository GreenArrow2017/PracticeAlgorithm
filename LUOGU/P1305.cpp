//
// Created by GreenArrow on 2020/3/7.
//
#include <iostream>
#include <map>

using namespace std;

typedef struct treeNode {
    char val;
    struct treeNode *left;
    struct treeNode *right;
} *TreeNode, treeNode;

map<char, TreeNode> treeNode_map;

void preOrder(TreeNode root) {
    if (root) {
        cout << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    int n;
    cin >> n;
    TreeNode root = new treeNode;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (i == 0) {
            root->val = s[0];
            treeNode_map[root->val] = root;
            if (s[1] == '*') {
                root->left = nullptr;
            } else {
                TreeNode leftTree = new treeNode;
                leftTree->val = s[1];
                leftTree->left = leftTree->right = nullptr;
                root->left = leftTree;
                treeNode_map[leftTree->val] = leftTree;
            }
            if (s[2] == '*') {
                root->right = nullptr;
            } else {
                TreeNode rightTree = new treeNode;
                rightTree->val = s[2];
                rightTree->left = rightTree->right = nullptr;
                root->right = rightTree;
                treeNode_map[rightTree->val] = rightTree;
            }
        }
        TreeNode u = treeNode_map[s[0]];
        if (s[1] == '*') {
            u->left = nullptr;
        } else {
            TreeNode node = new treeNode;
            node->val = s[1];
            node->left = node->right = nullptr;
            u->left = node;
            treeNode_map[node->val] = node;
        }
        if (s[2] == '*') {
            u->right = nullptr;
        } else {
            TreeNode node = new treeNode;
            node->val = s[2];
            node->left = node->right = nullptr;
            u->right = node;
            treeNode_map[node->val] = node;
        }
    }

    preOrder(root);
}
