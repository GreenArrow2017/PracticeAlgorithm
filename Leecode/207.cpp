//
// Created by GreenArrow on 2020/8/4.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    class node {
    public:
        int input = 0;
        int output = 0;
    };

    vector<node> nodes;
    vector<vector<int>> graph;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

        nodes.resize(numCourses);
        graph.resize(numCourses);
        int N = numCourses;
        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int w = prerequisites[i][1];
            graph[v].push_back(w);
            nodes[v].output++;
            nodes[w].input++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (nodes[i].input == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            N--;
            if (!N) {
                return true;
            }
            for (int i = 0; i < graph[v].size(); i++) {
                int w = graph[v][i];
                nodes[v].output--;
                nodes[w].input--;
                if (nodes[w].input == 0) {
                    q.push(w);
                }
            }
        }

        if(!N){
            return true;
        }
        return false;

    }
};