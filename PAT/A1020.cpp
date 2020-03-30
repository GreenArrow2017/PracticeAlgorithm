//
// Created by GreenArrow on 2020/2/21.
//

#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
} node;

node *create(int postl, int postr, int inl, int inr, int *post, int *in) {

    if (postl > postr) {
        return nullptr;
    }

    node *root = new node;

    root->data = post[postr];

    int index = 0;
    for (int i = inl; i <= inr; ++i) {
        if (in[i] == post[postr]) {
            index = i;
            break;
        }
    }

    int leftTreeNumber = index - inl;
    int rightTreeNumber = inr - index;

    root->left = create(postl, postl + leftTreeNumber - 1, inl, index - 1, post, in);
    root->right = create(postl + leftTreeNumber, postr - 1, index + 1, inr, post, in);

    return root;


}

void levelOrder(node *root) {
    queue<node *> Queue;
    Queue.push(root);
    int index = 0;
    int arr[10010];
    while (!Queue.empty()) {
        node *next = Queue.front();
        arr[index++] = next->data;
        Queue.pop();
        if (next != nullptr && next->left) {
            Queue.push(next->left);
        }
        if (next != nullptr && next->right) {
            Queue.push(next->right);
        }
    }

    for (int i = 0; i < index; ++i) {
        cout << arr[i];
        if (i != index - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int postOrder[n], inOrder[n];
    for (int i = 0; i < n; ++i) {
        cin >> postOrder[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> inOrder[j];
    }

    node *root = create(0, n - 1, 0, n - 1, postOrder, inOrder);


    levelOrder(root);
}