//
// Created by GreenArrow on 2020/9/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<bool> visited;

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();
        visited.resize(n);
        dfs(0, rooms);
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }

    void dfs(int v, vector<vector<int>> &rooms) {
        visited[v] = true;
        for(int i = 0;i < rooms[v].size();i++){
            if(!visited[rooms[v][i]]){
                dfs(rooms[v][i], rooms);
            }
        }
    }


};