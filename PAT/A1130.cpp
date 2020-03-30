//
// Created by GreenArrow on 2020/3/27.
//
#include <iostream>
#include <map>
#include <algorithm>

#define MAX 101
using namespace std;

typedef struct treeNode {
    string val;
    struct treeNode *left = nullptr;
    struct treeNode *right = nullptr;
} treeNode, *TreeNode;

int father[MAX] = {-1};
treeNode nodes[MAX];
string result;


void inOrder(TreeNode root, TreeNode parent) {
    if (root) {
        if ((root->left != nullptr || root->right != nullptr) && root != parent)
            result += "(";
        inOrder(root->left, parent);
        result += root->val;
        inOrder(root->right, parent);
        if ((root->left != nullptr || root->right != nullptr) && root != parent)
            result += ")";
    }
}

int main() {
    fill(father, father + MAX, -1);
    int n;
    cin >> n;
    if (n == 1) {
        string parent;
        int left, right;
        cin >> parent >> left >> right;
        cout << parent;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        string parent;
        int left, right;
        cin >> parent >> left >> right;
        nodes[i].val = parent;
        left--;
        right--;
        if (left >= -1) {
            father[left] = i;
            nodes[i].left = &nodes[left];
        } else {
            nodes[i].left = nullptr;
        }
        if (right >= -1) {
            father[right] = i;
            nodes[i].right = &nodes[right];
        } else
            nodes[i].right = nullptr;
    }

    int rootIndex = -1;
    for (int j = 0; j < n; ++j) {
        if (father[j] == -1) {
            rootIndex = j;
            break;
        }
    }

    TreeNode root = &nodes[rootIndex];

    inOrder(root, root);

    if (result.size() <= 2) {
        return 0;
    }

    cout << result;
}
