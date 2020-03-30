//
// Created by GreenArrow on 2020/2/23.
//

#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *TreeNode;

TreeNode insert(TreeNode root, int number) {
    if (!root) {
        root = new struct node;
        root->data = number;
        root->left = root->right = nullptr;
        return root;
    }


    if (root->data > number) {
        root->left = insert(root->left, number);
    } else if (root->data < number) {
        root->right = insert(root->right, number);
    }
    return root;
}

void preOrder(TreeNode root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {

    int n;
    while (cin >> n) {
        cin.ignore();
        TreeNode root = nullptr;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            root = insert(root, num);
        }

        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
    }

}