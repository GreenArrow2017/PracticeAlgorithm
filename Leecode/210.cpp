//
// Created by GreenArrow on 2020/8/5.
//

#include <iostream>
#include <cstring>
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

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> result;
        vector<node> nodes(numCourses);
        int N = numCourses;
        queue<int> q;
        vector<vector<int>> Graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            nodes[prerequisites[i][0]].output++;
            nodes[prerequisites[i][1]].input++;
            Graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {

            if (nodes[i].input == 0) {
                q.push(i);
            }

        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            N--;
            result.push_back(current);
            for (int i = 0; i < Graph[current].size(); i++) {
                nodes[current].output--;
                nodes[Graph[current][i]].input--;
                if (nodes[Graph[current][i]].input == 0) {
                    q.push(Graph[current][i]);
                }
            }
        }

        if(!N){
            vector<int> newResult;
            newResult.assign(result.rbegin(), result.rend());
            return newResult;
        }
        result.clear();
        return result;
    }
};