//
// Created by GreenArrow on 2020/3/26.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
    int depth = 0;
} treeNode, *TreeNode;

vector<vector<int>> levelOrder;

TreeNode create(int inL, int inR, int postL, int postR, vector<int> inOrder, vector<int> postOrder) {

    TreeNode root = nullptr;

    root = new treeNode;

    if (inL > inR) {
        return nullptr;
    }

    if (inL == inR) {
        root->val = inOrder[inL];
        root->right = root->left = nullptr;
        return root;
    }

    int rootNum = postOrder[postR];
    int index = -1;
    for (int i = inL; i <= inR; ++i) {
        if (inOrder[i] == rootNum) {
            index = i;
            break;
        }
    }

    int leftNum = index - inL;
    root->val = rootNum;
    root->left = create(inL, index - 1, postL, postL + leftNum - 1, inOrder, postOrder);
    root->right = create(index + 1, inR, postL + leftNum, postR - 1, inOrder, postOrder);

    return root;
}

void print_order(vector<int> order) {
    for (int i = 0; i < order.size(); ++i) {
        cout << " " << order[i];
    }
}

void print_reOrder(vector<int> order) {
    for (int i = order.size() - 1; i >= 0; --i) {
        cout << " " << order[i];
    }
}


void inOrder_(TreeNode root) {
    if (root) {
        inOrder_(root->left);
        cout << root->val;
        inOrder_(root->right);
    }
}

void zlevel(TreeNode root) {
    queue<TreeNode> Queue;
    root->depth = 1;
    Queue.push(root);
    while (!Queue.empty()) {
        TreeNode cur = Queue.front();
        Queue.pop();
        if (levelOrder.size() < cur->depth + 1) {
            vector<int> newDepth;
            newDepth.push_back(cur->val);
            levelOrder.push_back(newDepth);
        } else {
            levelOrder[cur->depth].push_back(cur->val);
        }
        if (cur->left) {
            cur->left->depth = cur->depth + 1;
            Queue.push(cur->left);
        }
        if (cur->right) {
            cur->right->depth = cur->depth + 1;
            Queue.push(cur->right);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> inOrder(n, 0);
    vector<int> postOrder(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> inOrder[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> postOrder[j];
    }

    TreeNode root = create(0, n - 1, 0, n - 1, inOrder, postOrder);

    vector<int> m;
    levelOrder.push_back(m);

    zlevel(root);

    cout << levelOrder[1][0];

    if (levelOrder.size() >= 3) {
        for (int i = 2; i < levelOrder.size(); ++i) {
            if (i % 2 != 0) {
                print_reOrder(levelOrder[i]);
            } else {
                print_order(levelOrder[i]);
            }
        }
    }

}