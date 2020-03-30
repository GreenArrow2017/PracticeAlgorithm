//
// Created by GreenArrow on 2020/3/13.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
    int parent = -1;
} *TreeNode, treeNode;

TreeNode buildBinaryTree(int n, treeNode *array) {
    for (int i = 0; i < n; ++i) {
        int left, right;
        cin >> left >> right;

        if (left != -1) {
            array[left].parent = i;
            array[i].left = &array[left];
        } else {
            array[i].left = nullptr;
        }
        if (right != -1) {
            array[right].parent = i;
            array[i].right = &array[right];
        } else {
            array[i].right = nullptr;
        }
    }

    int index = -1;
    for (int j = 0; j < n; ++j) {
        if (array[j].parent == -1) {
            index = j;
            break;
        }
    }
    return &array[index];
}

int index_treeNode = 0;

void inOrder(int *arr, TreeNode root) {
    if (root) {
        inOrder(arr, root->left);
        root->val = arr[index_treeNode++];
        inOrder(arr, root->right);
    }
}

void levelOrder(TreeNode root) {
    queue<TreeNode> Queue;
    vector<int> sequences;
    Queue.push(root);
    while (!Queue.empty()) {
        TreeNode cur = Queue.front();
        Queue.pop();
        sequences.push_back(cur->val);
        if (cur->left) {
            Queue.push(cur->left);
        }
        if (cur->right) {
            Queue.push(cur->right);
        }
    }

    for (int i = 0; i < sequences.size(); ++i) {
        cout << sequences[i];
        if (i != sequences.size() - 1) {
            cout << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    treeNode array[n];
    TreeNode root = buildBinaryTree(n, array);

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n);

    inOrder(numbers, root);
    levelOrder(root);
}
