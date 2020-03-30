//
// Created by GreenArrow on 2020/2/24.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *TreeNode, Node;

void preOrder(TreeNode root, vector<int> &preSequence) {
    if (root) {
        preSequence.push_back(root->data);
        preOrder(root->left, preSequence);
        preOrder(root->right, preSequence);
    }
}

void preOrderMirror(TreeNode root, vector<int> &preSequenceMirror) {
    if (root) {
        preSequenceMirror.push_back(root->data);
        preOrderMirror(root->right, preSequenceMirror);
        preOrderMirror(root->left, preSequenceMirror);
    }
}

void postOrder(TreeNode root, vector<int> &postSequence) {
    if (root) {
        postOrder(root->left, postSequence);
        postOrder(root->right, postSequence);
        postSequence.push_back(root->data);
    }
}

void postOrderMirror(TreeNode root, vector<int> &postSequenceMirror) {
    if (root) {
        postOrderMirror(root->right, postSequenceMirror);
        postOrderMirror(root->left, postSequenceMirror);
        postSequenceMirror.push_back(root->data);
    }
}

TreeNode insert(TreeNode root, int num) {
    if (!root) {
        root = new Node;
        root->data = num;
        root->left = root->right = nullptr;
        return root;
    }

    if (root->data > num) {
        root->left = insert(root->left, num);
    } else if (root->data <= num) {
        root->right = insert(root->right, num);
    }
    return root;
}

int main() {

    int n;
    cin >> n;
    cin.ignore();
    TreeNode root = nullptr;
    vector<int> preOriginal;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        preOriginal.push_back(num);
        root = insert(root, num);
    }

    vector<int> preOrderSequence, preOrderMirrorSequence, postOrderSequence, postOrderMirrorSequence;
    preOrder(root, preOrderSequence);
    preOrderMirror(root, preOrderMirrorSequence);
    postOrder(root, postOrderSequence);
    postOrderMirror(root, postOrderMirrorSequence);

    if (preOrderSequence == preOriginal) {
        cout << "YES" << endl;
        for (int i = 0; i < postOrderSequence.size(); ++i) {
            cout << postOrderSequence[i];
            if (i < postOrderSequence.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else if (preOrderMirrorSequence == preOriginal) {
        cout << "YES" << endl;
        for (int i = 0; i < postOrderMirrorSequence.size(); ++i) {
            cout << postOrderMirrorSequence[i];
            if (i < postOrderMirrorSequence.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}