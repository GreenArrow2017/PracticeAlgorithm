//
// Created by GreenArrow on 2020/3/14.
//
#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

typedef struct treeNode {
    vector<int> childen;
    int parent = -1;
} *TreeNode, treeNode;

double minDepth = INT_MAX;
int minNumber = INT_MAX;

void BFS(int root, int depth, treeNode *array) {

    if (depth > minDepth && minNumber > 0) {
        return;
    }

    if (array[root].childen.size() == 0) {
        if (depth < minDepth) {
            minDepth = depth;
            minNumber = 1;
        } else if (depth == minDepth) {
            minNumber++;
        }
        return;
    }
    for (int i = 0; i < array[root].childen.size(); ++i) {
        BFS(array[root].childen[i], depth + 1, array);
    }
}

int main() {
    int n;
    double price;
    double r;
    cin >> n >> price >> r;
    treeNode array[100010];
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int next;
            cin >> next;
            array[next].parent = i;
            array[i].childen.push_back(next);
        }
    }

    int root = -1;
    for (int k = 0; k < n; ++k) {
        if (array[k].parent == -1) {
            root = k;
            break;
        }
    }

    BFS(root, 0, array);

    for (int l = 0; l < minDepth; ++l) {
        price = price * ((100 + r) / 100);
    }

    printf("%.4lf %d", price, minNumber);

}
