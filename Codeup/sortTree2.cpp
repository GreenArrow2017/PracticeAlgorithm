//
// Created by GreenArrow on 2020/2/23.
//
#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *TreeNode, Node;

TreeNode create(TreeNode root, int num) {
    if (!root) {
        root = new Node;
        root->data = num;
        root->left = root->right = nullptr;
        return root;
    }

    if (root->data > num) {
        root->left = create(root->left, num);
    } else if (root->data < num) {
        root->right = create(root->right, num);
    }

    return root;
}

void getPreOrderSequence(TreeNode root, vector<int> &squence) {
    if (root) {
        squence.push_back(root->data);
        getPreOrderSequence(root->left, squence);
        getPreOrderSequence(root->right, squence);
    }
}

void getInOrderSequence(TreeNode root, vector<int> &sequence) {
    if (root) {
        getInOrderSequence(root->left, sequence);
        sequence.push_back(root->data);
        getInOrderSequence(root->right, sequence);
    }
}

void print_test(vector<int> test) {
    for (int i = 0; i < test.size(); ++i) {
        cout << test[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    while (cin >> n) {
        cin.ignore();
        if (n == 0) {
            return 0;
        }

        string s;
        cin >> s;
        cin.ignore();

        TreeNode root = nullptr;
        for (int i = 0; i < s.length(); ++i) {
            root = create(root, s[i] - '0');
        }

        vector<int> preSequence;
        getPreOrderSequence(root, preSequence);

        vector<int> inSequence;
        getInOrderSequence(root, inSequence);

//        print_test(preSequence);
//        print_test(inSequence);

        for (int j = 0; j < n; ++j) {

            string str;
            cin >> str;
            cin.ignore();

            TreeNode u = nullptr;
            for (int i = 0; i < str.length(); ++i) {
                u = create(u, str[i] - '0');
            }

            vector<int> nowPreSequence;
            getPreOrderSequence(u, nowPreSequence);

            vector<int> nowInSequence;
            getInOrderSequence(u, nowInSequence);

//            print_test(nowPreSequence);
//            print_test(nowInSequence);

            if (preSequence == nowPreSequence && inSequence == nowInSequence) {
                cout << "YES" << endl;
            } else
                cout << "NO" << endl;

        }

    }
}
