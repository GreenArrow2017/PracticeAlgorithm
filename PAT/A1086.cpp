//
// Created by GreenArrow on 2020/3/13.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct treeNode {
    int val;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
} *TreeNode, treeNode;

TreeNode create(int preL, int preR, int inL, int inR, int *preOrder, int *inOrder) {
    int rootNum = preOrder[preL];
    TreeNode root = new treeNode;
    root->val = rootNum;
    if (preL == preR) {
        root->val = rootNum;
        root->leftChild = root->rightChild = nullptr;
        return root;
    }

    if (preL > preR) {
        return nullptr;
    }

    int mid = -1;

    for (int i = inL; i <= inR; ++i) {
        if (inOrder[i] == rootNum) {
            mid = i;
            break;
        }
    }

    int leftNumber = mid - inL;
    int rightNumber = inR - mid;

    root->leftChild = create(preL + 1, preL + leftNumber, inL, mid - 1, preOrder, inOrder);
    root->rightChild = create(preR - rightNumber + 1, preR, mid + 1, inR, preOrder, inOrder);
    return root;
}

void postOrder(TreeNode root, vector<int> &sequences) {
    if (root) {
        postOrder(root->leftChild, sequences);
        postOrder(root->rightChild, sequences);
        sequences.push_back(root->val);
    }
}

int main() {
    int n;
    stack<int> Stack;
    cin >> n;

    int preOrder[n];
    int inOrder[n];

    int pre_index = 0;
    int in_index = 0;
    for (int i = 0; i < 2 * n; ++i) {
        string order;
        cin >> order;
        if (order == "Push") {
            int num;
            cin >> num;
            preOrder[pre_index++] = num;
            Stack.push(num);
        } else if (order == "Pop") {
            int cur = Stack.top();
            Stack.pop();
            inOrder[in_index++] = cur;
        }
    }

    TreeNode root = create(0, n - 1, 0, n - 1, preOrder, inOrder);
    vector<int> sequences;
    postOrder(root, sequences);
    for (int j = 0; j < sequences.size(); ++j) {
        cout << sequences[j];
        if (j != sequences.size() - 1) {
            cout << " ";
        }
    }
}
