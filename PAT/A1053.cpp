//
// Created by GreenArrow on 2020/3/13.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct treeNode {
    int val;
    int weight;
    vector<struct treeNode *> generator;
    int parent = -1;
} *TreeNode, treeNode;

map<int, bool> index_map;
vector<vector<int>> weights_path;

int cmp(TreeNode a, TreeNode b) {
    return a->weight < b->weight;
}

TreeNode createTree(int n, TreeNode *array, int allNodes) {
    for (int i = 0; i < n; ++i) {
        int index;
        int num;
        cin >> index >> num;
        index_map[index] = true;
        for (int j = 0; j < num; ++j) {
            int next;
            cin >> next;
            array[next]->parent = index;

            array[index]->generator.push_back(array[next]);

        }
        sort(array[index]->generator.rbegin(), array[index]->generator.rend(), cmp);

    }

    for (int k = 0; k < allNodes; ++k) {
        if (array[k]->parent == -1) {
            return array[k];
        }
    }
    return nullptr;
}

void findWeights(TreeNode root, int sum, vector<int> weightsAdd, int equalWeights) {
    if (sum > equalWeights) {
        return;
    } else if (sum < equalWeights) {
        sum += root->weight;
        weightsAdd.push_back(root->weight);
        if (sum == equalWeights) {

            if (!index_map[root->val]) {
                weights_path.push_back(weightsAdd);
                weightsAdd.clear();
            }
            return;
        }
        for (int i = 0; i < root->generator.size(); ++i) {
            TreeNode current = root->generator[i];
            findWeights(current, sum, weightsAdd, equalWeights);
        }
    }
}

int main() {
    int n;
    int nodes_number;
    int weights, weights_;
    cin >> n >> nodes_number >> weights_;

    TreeNode array[n];
    for (int i = 0; i < n; ++i) {
        index_map[i] = false;
        cin >> weights;
        array[i] = new treeNode;
        array[i]->val = i;
        array[i]->weight = weights;
    }

    TreeNode root = createTree(nodes_number, array, n);

    vector<int> collect;

    findWeights(root, 0, collect, weights_);

    for (int j = 0; j < weights_path.size(); ++j) {
        for (int i = 0; i < weights_path[j].size(); ++i) {
            cout << weights_path[j][i];
            if (i != weights_path[j].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
