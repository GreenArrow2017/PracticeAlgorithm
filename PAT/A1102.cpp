//
// Created by GreenArrow on 2020/3/14.
//
#include <iostream>
#include <queue>

using namespace std;

typedef struct treeNode {
    int val;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
    int parent = -1;
} *TreeNode, treeNode;

int string2Number(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        sum = sum * 10 + (s[i] - '0');
    }
    return sum;
}

void inOrder(TreeNode root, vector<int> &sequences) {
    if (root) {
        inOrder(root->leftChild, sequences);
        sequences.push_back(root->val);
        inOrder(root->rightChild, sequences);
    }
}

void postExchange(TreeNode root) {
    if (root) {
        postExchange(root->leftChild);
        postExchange(root->rightChild);

        TreeNode temp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = temp;
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
        if (cur->leftChild) {
            Queue.push(cur->leftChild);
        }
        if (cur->rightChild) {
            Queue.push(cur->rightChild);
        }
    }

    for (int i = 0; i < sequences.size(); ++i) {
        cout << sequences[i];
        if (sequences.size() - 1 != i) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    treeNode array[n];
    for (int i = 0; i < n; ++i) {
        array[i].val = i;
        string left, right;
        cin >> left >> right;
        if (left == "-") {
            array[i].leftChild = nullptr;
        } else {
            array[i].leftChild = &array[string2Number(left)];
            array[string2Number(left)].parent = i;
        }
        if (right == "-") {
            array[i].rightChild = nullptr;
        } else {
            array[i].rightChild = &array[string2Number(right)];
            array[string2Number(right)].parent = i;
        }
    }

    TreeNode root = nullptr;

    for (int j = 0; j < n; ++j) {
        if (array[j].parent == -1) {
            root = &array[j];
            break;
        }
    }
    postExchange(root);
    levelOrder(root);
    vector<int> sequences;
    inOrder(root, sequences);
    for (int i = 0; i < sequences.size(); ++i) {
        cout << sequences[i];
        if (sequences.size() - 1 != i) {
            cout << " ";
        }
    }
}



