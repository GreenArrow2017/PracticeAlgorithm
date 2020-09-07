//
// Created by GreenArrow on 2020/7/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    int array[100] = {0};
    bool visited[100] = {false};

    int getMin(int n, int array[100]) {
        int index = -1;
        int maxValue = INT_MAX;
        for (int i = 0; i < n; i++) {
            cout << i << " : " << array[i] << endl;
            if (maxValue > array[i]) {
                index = i;
                maxValue = array[i];
            } else if (maxValue == array[i] && index < i) {
                index = i;
            }
        }
        return index;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {

        int graph[100][100];

        for (int i = 0; i < n; i++) {
            fill(graph[i], graph[i] + n, 0);
            fill(array, array + n, 0);
        }


        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]][edges[i][1]] += edges[i][2];
            graph[edges[i][1]][edges[i][0]] += edges[i][2];
        }

        for (int i = 0; i < n; i++) {
            fill(visited, visited + 100, false);
            dfs(i, i, n, graph, distanceThreshold, 0);
            //cout << endl;
        }

        return getMin(n, array);

    }

    void dfs(int main, int v, int n, int graph[100][100], int distanceThreshold, int current) {
        visited[v] = true;
        //cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i] && current + graph[v][i] <= distanceThreshold) {
                array[main]++;
                dfs(main, i, n, graph, distanceThreshold, current + graph[v][i]);
            }
        }
    }
};