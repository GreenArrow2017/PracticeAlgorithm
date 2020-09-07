#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<int> count;
    vector<int> ret;

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels);
    void bfs(int curPos,string& labels,vector<vector<int>>& graph);
};

vector<int> Solution::countSubTrees(int n, vector<vector<int>>& edges, string labels)
{
    vector<vector<int>> graph(n,vector<int>());
    for(int i = 0;i < n-1;i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    visited.assign(n,false);
    count.assign(26,0);
    ret.assign(n,0);

    bfs(0,labels,graph);

    return ret;
}

void Solution::bfs(int curPos,string& labels,vector<vector<int>>& graph)
{
//    cout<<curPos<<endl;
    visited[curPos] = true;
    int preCount = count[labels[curPos]-'a'];
    count[labels[curPos]-'a']++;

    for(int i = 0;i < graph[curPos].size();i++)
    {
        int pos = graph[curPos][i];
        if(visited[pos])    continue;
        bfs(pos,labels,graph);
    }
    ret[curPos] = count[labels[curPos] - 'a'] - preCount;
    return;
}
