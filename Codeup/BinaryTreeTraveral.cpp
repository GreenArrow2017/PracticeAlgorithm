//
// Created by GreenArrow on 2020/2/23.
//

#include <iostream>

using namespace std;

string s;
int index_s;
typedef struct node {
    char val;
    struct node *left;
    struct node *right;
} *TreeNode;

TreeNode createPre(TreeNode root) {
    char number;
    number = s[index_s++];
    if (number == '#') {
        return nullptr;
    } else {
        root = new struct node;
        root->val = number;
        root->left = createPre(root->left);
        root->right = createPre(root->right);
        return root;
    }
}

void inOrder(TreeNode root) {
    if (root) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

int main() {
    while (cin >> s) {
        index_s = 0;
        TreeNode root = createPre(root);
        inOrder(root);
        cout << endl;
    }
}