//
// Created by GreenArrow on 2020/3/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 101
using namespace std;

typedef struct treeNode {
    int val;
    int depth = 0;
    vector<treeNode *> children;

    treeNode(int val) {
        this->val = val;
        children.clear();
    }

    treeNode() {}
} treeNode, *TreeNode;

treeNode arr[MAX];
int father[MAX];
int depth[MAX] = {0};

int maxDepth = -1;
int max_ = -1;

void BFS(TreeNode root) {
    root->depth = 1;
    queue<TreeNode> Queue;
    Queue.push(root);
    while (!Queue.empty()) {
        TreeNode cur = Queue.front();
        Queue.pop();
        depth[cur->depth]++;
        if (max_ < depth[cur->depth]) {
            max_ = depth[cur->depth];
            maxDepth = cur->depth;
        }
        for (int i = 0; i < cur->children.size(); ++i) {
            Queue.push(cur->children[i]);
            cur->children[i]->depth = cur->depth + 1;
        }
    }
}

int main() {
    fill(father, father + MAX, -1);
    fill(depth, depth + MAX, 0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int fa, num;
        cin >> fa >> num;
        arr[fa].val = fa;
        for (int j = 0; j < num; ++j) {
            int child;
            cin >> child;
            arr[child].val = child;
            father[child] = fa;
            arr[fa].children.push_back(&arr[child]);
        }
    }

    TreeNode root = nullptr;
    for (int k = 1; k <= N; ++k) {
        if (father[k] == -1) {
            root = &arr[k];
            break;
        }
    }

    BFS(root);

    cout << max_ << " " << maxDepth;
}