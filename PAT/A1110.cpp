//
// Created by GreenArrow on 2020/3/12.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define MAX 1000
using namespace std;
typedef struct node {
    int left = -1;
    int right = -1;
    int index = -1;
} *Node, node;

int string2number(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        sum = sum * 10 + (s[i] - '0');
    }
    return sum;
}

int level(node *array, int root, int *array_tree) {
    queue<int> Queue;
    Queue.push(root);
    array[root].index = 0;
    array_tree[array[root].index] = 1;
    vector<int> sequences;
    while (!Queue.empty()) {
        int cur = Queue.front();
        sequences.push_back(cur);
        Queue.pop();
        if (array[cur].left != -1) {
            Queue.push(array[cur].left);
            array_tree[array[cur].index * 2 + 1] = 1;
            array[array[cur].left].index = array[cur].index * 2 + 1;
        }
        if (array[cur].right != -1) {
            Queue.push(array[cur].right);
            array_tree[array[cur].index * 2 + 2] = 1;
            array[array[cur].right].index = array[cur].index * 2 + 2;
        }
    }

    return sequences[sequences.size() - 1];
}

int main() {
    int n;
    node array[MAX];
    int father[MAX] = {-1};
    fill(father, father + MAX, -1);
    map<int, int> nodes;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;
        if (left == "-") {
            array[i].left = -1;
        } else {
            array[i].left = string2number(left);
            father[array[i].left] = i;
        }
        if (right == "-") {
            array[i].right = -1;
        } else {
            array[i].right = string2number(right);
            father[array[i].right] = i;
        }
    }

    int root = -1;
    for (int j = 0; j < n; ++j) {
        if (father[j] == -1) {
            root = j;
        }
    }

    array[root].index = 0;

    vector<int> sequqence;
    int array_tree[MAX] = {0};
    int tile = level(array, root, array_tree);
    for (int k = 0; k < n; ++k) {
        if (!array_tree[k]) {
            cout << "NO" << " " << root;
            return 0;
        }
    }
    cout << "YES" << " " << tile;
}