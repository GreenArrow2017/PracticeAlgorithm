//
// Created by GreenArrow on 2020/3/15.
//
#include <iostream>
#include <vector>

using namespace std;

typedef struct treeNode {
    int val;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
} *TreeNode, treeNode;

bool flag = true;

TreeNode create(int preL, int preR, int postL, int postR, int *preSequences, int *postSequences) {
    if (preL > preR) {
        return nullptr;
    }
    TreeNode root = new treeNode;
    root->val = preSequences[preL];
    root->leftChild = root->rightChild = nullptr;
    if (preL == preR) {
        return root;
    }

    int k = 0;
    for (int i = preL + 1; i <= preR; ++i) {
        if (preSequences[i] == postSequences[postR - 1]) {
            k = i;
            break;
        }
    }

    if (k - preL > 1) {
        root->leftChild = create(preL + 1, k - 1, postL, postL + k - preL - 2, preSequences, postSequences);
        root->rightChild = create(k, preR, postL + k - preL - 1, postR - 1, preSequences, postSequences);
    } else {
        flag = false;
        root->leftChild = create(k, preR, postL + k - preL - 1, postR - 1, preSequences, postSequences);
    }
    return root;
}

vector<int> inPrint;

void inOrder(TreeNode root) {
    if (root) {
        inOrder(root->leftChild);
        inPrint.push_back(root->val);
        inOrder(root->rightChild);
    }
}

int main() {
    int n;
    cin >> n;
    int preSequences[n + 1];
    int postSequences[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> preSequences[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> postSequences[j];
    }

    TreeNode root = create(0, n - 1, 0, n - 1, preSequences, postSequences);

    inOrder(root);

    if (flag) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;

    for (int k = 0; k < inPrint.size(); ++k) {
        cout << inPrint[k];
        if (k != inPrint.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}