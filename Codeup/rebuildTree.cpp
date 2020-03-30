//
// Created by GreenArrow on 2020/2/21.
//

#include <iostream>

using namespace std;

typedef struct node {
    char data;
    node *left;
    node *right;
} node;

node *create(int prel, int prer, int inl, int inr, string pre, string in) {

    if (prel > prer) {
        return nullptr;
    }

    node *root = new node;
    root->data = pre[prel];

    int index = 0;
    for (int i = 0; i < in.length(); ++i) {
        if (in[i] == pre[prel]) {
            index = i;
            break;
        }
    }

    int leftNumber = index - inl;
    int rightNumber = inr - index;

    root->left = create(prel + 1, prel + 1 + leftNumber - 1, inl, index - 1, pre, in);
    root->right = create(prel + 1 + leftNumber - 1 + 1, prer, index + 1, inr, pre, in);

    return root;

}

void postOrder(node *root) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        postOrder(root->left);
    }
    if (root->right) {
        postOrder(root->right);
    }
    cout << root->data;
}

int main() {
    string pre, in;
    while (cin >> pre >> in) {

        node *root = create(0, pre.length() - 1, 0, in.length() - 1, pre, in);
        postOrder(root);
        cout << endl;

    }
}
