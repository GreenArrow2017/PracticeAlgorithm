//
// Created by GreenArrow on 2020/3/19.
//
#include <iostream>
#include <vector>
#include <cstdio>

#define MAX 100000
using namespace std;

class treeNode {
public:
    int val;
    vector<treeNode *> children;
};

int father[MAX] = {-1};
treeNode nodes[MAX];
int number[MAX] = {-1};

double total = 0;

void DFS(treeNode *root, double price, double r) {
    if (number[root->val] != -1 && root->children.size() == 0) {
        total += number[root->val] * price;
        return;
    }

    for (int i = 0; i < root->children.size(); ++i) {
        DFS(root->children[i], price * ((100 + r) / 100), r);
    }
}


int main() {
    fill(father, father + MAX, -1);
    fill(number, number + MAX, -1);
    int n;
    double price, r;
    cin >> n >> price >> r;
    for (int i = 0; i < n; ++i) {
        nodes[i].val = i;
        int num;
        cin >> num;

        if (num == 0) {
            cin >> number[i];
            continue;
        }

        for (int j = 0; j < num; ++j) {
            int a;
            cin >> a;
            nodes[i].children.push_back(&nodes[a]);
            father[a] = i;
        }
    }

    vector<treeNode *> roots;

    for (int k = 0; k < n; ++k) {
        if (father[k] == -1) {
            roots.push_back(&nodes[k]);
        }
    }

    for (int l = 0; l < roots.size(); ++l) {
        DFS(roots[l], price, r);
    }

    printf("%.1lf", total);

}
