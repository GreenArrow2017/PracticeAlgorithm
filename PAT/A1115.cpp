//
// Created by GreenArrow on 2020/3/15.
//
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 100010
using namespace std;

typedef struct treeNode {
    int val;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
    int depth = 0;
} *TreeNode, treeNode;

int depth[MAX] = {0};
int maxDepth = -1;

TreeNode insert(TreeNode root, int num) {
    if (root) {
        if (root->val < num) {
            root->rightChild = insert(root->rightChild, num);
        } else {
            root->leftChild = insert(root->leftChild, num);
        }
        return root;
    } else {
        root = new treeNode;
        root->val = num;
        root->leftChild = root->rightChild = nullptr;
        return root;
    }
}

void level(TreeNode root) {
    fill(depth, depth + MAX, 0);
    queue<TreeNode> Queue;
    Queue.push(root);
    while (!Queue.empty()) {
        TreeNode cur = Queue.front();
        Queue.pop();
        depth[cur->depth]++;
        maxDepth = ((maxDepth > cur->depth) ? maxDepth : cur->depth);
        if (cur->leftChild) {
            cur->leftChild->depth = cur->depth + 1;
            Queue.push(cur->leftChild);
        }
        if (cur->rightChild) {
            cur->rightChild->depth = cur->depth + 1;
            Queue.push(cur->rightChild);
        }
    }
}

int main() {
    int n;
    cin >> n;
    TreeNode root = nullptr;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        root = insert(root, num);
    }

    level(root);

    cout << depth[maxDepth] << " + " << depth[maxDepth - 1] << " = " << depth[maxDepth] + depth[maxDepth - 1];

}