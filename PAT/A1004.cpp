//
// Created by GreenArrow on 2020/3/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 1010
using namespace std;

class treeNode {
public:
    int val;

    vector<treeNode *> children;

    int depth = 0;

    treeNode() {}

    treeNode(int val) : val(val) {}

};

int depth[MAX] = {0};

int levelOrder(treeNode *root) {
    int max = 0;
    queue<treeNode *> Queue;
    Queue.push(root);
    root->depth = 0;
    while (!Queue.empty()) {
        treeNode *cur = Queue.front();
        Queue.pop();
        if (!cur->children.size())
            depth[cur->depth]++;
        for (int i = 0; i < cur->children.size(); ++i) {
            cur->children[i]->depth = cur->depth + 1;
            Queue.push(cur->children[i]);
            if (cur->children[i]->depth > max) {
                max = cur->children[i]->depth;
            }
        }
    }
    return max;
}

int main() {
    int n, m;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    cin >> m;

    treeNode nodes[MAX];
    int father[MAX];
    for (int i = 0; i < MAX; ++i) {
        nodes[i] = treeNode(i);
        father[i] = -1;
    }
    for (int j = 0; j < m; ++j) {
        int fa;
        cin >> fa;
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i) {
            int index_;
            cin >> index_;
            nodes[fa].children.push_back(&nodes[index_]);
            father[index_] = fa;
        }
    }

    treeNode *root = &nodes[1];

    int Depth = levelOrder(root);

    for (int l = 0; l <= Depth; ++l) {
        cout << depth[l];
        if (l != Depth) {
            cout << " ";
        }
    }

}
/**
72 34
01 5 26 4 66 11 31
26 5 57 60 14 17 25
04 2 69 20
57 4 35 13 16 45
66 3 41 36 56
69 3 37 2 7
41 3 58 38 65
35 4 46 68 59 61
11 2 15 44
14 1 18
37 1 6
13 2 30 67
30 1 34
46 3 42 27 62
18 2 72 71
42 3 29 51 53
31 1 12
12 2 54 63
15 5 5 52 47 21 64
17 4 8 23 19 49
08 1 24
23 1 9
52 2 39 3
24 1 48
48 1 10
54 1 70
71 1 55
06 1 43
64 1 33
39 1 50
70 1 22
20 1 40
25 1 32
40 1 28
 **/