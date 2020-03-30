//
// Created by GreenArrow on 2020/3/14.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//typedef struct treeNode {
//    int val;
//    vector<struct treeNode *> children;
//    int parent = -1;
//} *TreeNode, treeNode;

double maxPrice = -1;
int maxNumber = -1;

//void BFS(TreeNode root, double currentPrice, double r, vector<int> path) {
//    if (root) {
//        path.push_back(root->val);
//        currentPrice = currentPrice * ((100 + r) / 100);
//        if (maxPrice < currentPrice) {
//            maxPrice = currentPrice;
//            maxNumber = path.size();
//        }
//        for (int i = 0; i < root->children.size(); ++i) {
//            BFS(root->children[i], currentPrice, r, path);
//        }
//    }
//}

vector<int> v[100010];

void bfs(int root, int depth) {
    if (v[root].size() == 0) {
        if (maxPrice < depth) {
            maxPrice = depth;
            maxNumber = 1;
        } else if (maxPrice == depth) {
            maxNumber++;
        }
        return;
    }
    for (int i = 0; i < v[root].size(); ++i) {
        bfs(v[root][i], depth + 1);
    }
}

int main() {
    int n;
    double price;
    double r;
    cin >> n >> price >> r;

//    treeNode array[n];


//    int root_index = 0;
//    for (int i = 0; i < n; ++i) {
//        array[i].val = i;
//        int parent;
//        cin >> parent;
//        if (parent == -1) {
//            root_index = i;
//        }
//        array[i].parent = parent;
//
//        if (parent != -1) {
//            array[parent].children.push_back(&array[i]);
//        }
//    }

//    TreeNode root = &array[root_index];
//
//    vector<int> path;
//
//    BFS(root, price, r, path);
//    for (int j = 0; j < maxNumber - 1; ++j) {
//        price *= ((100 + r) / 100);
//    }
    int root = -1;
    int array[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] == -1) {
            root = i;
        }
        if (array[i] != -1)
            v[array[i]].push_back(i);
    }



//    bool visited[n];
//
//    fill(visited, visited + n, false);

//    for (int j = 0; j < n; ++j) {
//        if (!visited[j]) {
//            int paths = 0;
//            int fa = array[j];
//            while (fa != -1) {
//                visited[fa] = true;
//                fa = array[fa];
//                paths++;
//            }
//            maxNumber = ((maxNumber > paths) ? maxNumber : paths);
//        }
//    }

    bfs(root, 0);

    for (int k = 0; k < maxPrice; ++k) {
        price *= ((100 + r) / 100);
    }

    printf("%.2lf %d", price, maxNumber);
}

