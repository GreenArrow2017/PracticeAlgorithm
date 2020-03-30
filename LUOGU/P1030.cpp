//
// Created by GreenArrow on 2020/3/6.
//
#include <iostream>

using namespace std;

typedef struct treeNode {
    char val;
    struct treeNode *left;
    struct treeNode *right;
} *TreeNode, treeNode;

TreeNode createTree(int orderL, int orderR, int postL, int postR, string order, string post) {

    if (orderL == orderR) {
        TreeNode tree = new treeNode;
        tree->val = order[orderL];
        tree->left = tree->right = nullptr;
        return tree;
    } else if (orderL > orderR) {
        return nullptr;
    }

    char root = post[postR];

    TreeNode treeRoot = new treeNode;
    treeRoot->val = root;

    int index = -1;
    for (int i = orderL; i <= orderR; ++i) {
        if (order[i] == root) {
            index = i;
            break;
        }
    }

    int numberLeft = index - orderL;
    int numberRight = orderR - index;

    treeRoot->left = createTree(orderL, index - 1, postL, postL + numberLeft - 1, order, post);
    treeRoot->right = createTree(index + 1, orderR, postL + numberLeft, postR - 1, order, post);
    return treeRoot;
}

void preOrder(TreeNode root) {
    if (root) {
        cout << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    string order;
    string post;
    cin >> order;
    cin >> post;
    TreeNode root = createTree(0, order.length() - 1, 0, post.length() - 1, order, post);
    preOrder(root);
}