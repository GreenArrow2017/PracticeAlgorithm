//
// Created by GreenArrow on 2020/8/30.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        vector<int> result;
        graph.resize(500);
        visited.resize(500);
        int start = target->val;
        createGraph(NULL, root);
        queue<pair<int, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            int current = q.front().first;
            int depth = q.front().second;
            visited[current] = true;
            q.pop();
            if (depth == K) {
                result.push_back(current);
            }
            if (depth > K) {
                continue;
            }
            for (int i = 0; i < graph[current].size(); i++) {
                if (!visited[graph[current][i]]) {
                    q.push({graph[current][i], depth + 1});
                }
            }
        }
        return result;
    }

    void createGraph(TreeNode *parent, TreeNode *root) {
        if (root == NULL) {
            return; 
        }
        if (parent) {
            graph[parent->val].push_back(root->val);
            graph[root->val].push_back(parent->val);
        }
        createGraph(root, root->left);
        createGraph(root, root->right);
    }
};