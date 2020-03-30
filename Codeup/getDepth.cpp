//
// Created by GreenArrow on 2020/2/23.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef struct node {

    bool flag = false;
    int depth;
} *TreeNode;

int insert(TreeNode *trees, int n) {
    n--;
    int max = 1;
    while (n--) {
        int parentRoot = 0, sonRoot = 0;
        cin >> parentRoot >> sonRoot;
        cin.ignore();
        trees[sonRoot]->flag = true;
        trees[sonRoot]->depth = trees[parentRoot]->depth + 1;
        if (max < trees[sonRoot]->depth) {
            max = trees[sonRoot]->depth;
        }
    }
    return max;
}

int main() {

    int n;
    while (cin >> n) {
        cin.ignore();
        int num = pow(2, n) - 1;
        TreeNode trees[num + 1];

        for (int i = 0; i <= num; ++i) {
            trees[i] = new struct node;
        }

        trees[1]->flag = true;
        trees[1]->depth = 1;

        cout << insert(trees, n) << endl;

    }

}