//
// Created by GreenArrow on 2020/3/6.
//
#include <iostream>
#include <cmath>

#define MAX 1048
using namespace std;

typedef struct treeNode {
    struct treeNode *right;
    struct treeNode *left;
    char classify;
} *TreeNode, treeNode;

char judgeClass(int l, int r, int *array) {
    bool flagOne = false;
    bool flagZero = false;
    for (int i = l; i <= r; ++i) {
        if (array[i] == 0) {
            flagZero = true;
            if (flagOne) {
                break;
            }
        } else if (array[i] == 1) {
            flagOne = true;
            if (flagZero) {
                break;
            }
        }
    }

    if (flagOne && flagZero) {
        return 'F';
    } else if (flagOne) {
        return 'I';
    } else if (flagZero) {
        return 'B';
    }
}

TreeNode createBinaryTree(int l, int r, int *array, char parent) {

    if (l == r) {
        TreeNode u = new treeNode;
        u->right = u->left = nullptr;
        if (array[l] == 0) {
            u->classify = 'B';
        } else
            u->classify = 'I';
        return u;
    }

    int mid = (l + r) / 2;
    TreeNode root = new treeNode;
    if (parent == 'B') {
        root->classify = 'B';
    } else if (parent == 'I') {
        root->classify = 'I';
    } else
        root->classify = judgeClass(l, r, array);
    root->left = createBinaryTree(l, mid, array, root->classify);
    root->right = createBinaryTree(mid + 1, r, array, root->classify);
    return root;
}

void postOrder(TreeNode root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->classify;
    }
}

int main() {
    int n;
    cin >> n;
    int array[MAX];
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        array[i] = (s[i] - '0');
    }

    TreeNode root = createBinaryTree(0, s.length() - 1, array, 'O');
    postOrder(root);
}