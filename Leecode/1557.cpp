//
// Created by GreenArrow on 2020/9/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    class node {
    public:
        int input = 0;
        int output = 0;
    };

    vector<node *> nodes;

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        for (int i = 0; i < n; i++) {
            node *nod = new node();
            nodes.push_back(nod);
        }
        for (int i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]]->output++;
            nodes[edges[i][1]]->input++;
        }
        vector<int> results;
        for (int i = 0; i < n; i++) {
            if (nodes[i]->input == 0) {
                results.push_back(i);
            }
        }
        return results;
    }
};