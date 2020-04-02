//
// Created by GreenArrow on 2020/3/30.
//
#include <iostream>
#include <map>
#include <vector>

#define MAX 10000
using namespace std;

vector<vector<int>> station_cross;

void
DFS(vector<vector<int>> stations_lines, vector<map<int, int>> stations_index, vector<vector<bool>> stations_visited,
    int line, int start, int end, vector<int> curent) {
    curent.push_back(start);
    stations_visited[line][start] = true;
    if (start == end) {
        vector<int> path;
        path.assign(curent.begin(), curent.end());
        station_cross.push_back(path);
        return;
    }

}

int main() {
    vector<vector<int>> stations_lines;
    vector<map<int, int>> stations_index;
    vector<vector<bool>> stations_visited;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {

        vector<int> line;
        stations_lines.push_back(line);
        map<int, int> station_index;
        stations_index.push_back(station_index);
        vector<bool> station_visited;
        stations_visited.push_back(station_visited);

        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int stationNumber;
            cin >> stationNumber;
            stations_lines[i].push_back(stationNumber);
            stations_index[i][stationNumber] = j;
            stations_visited[i].push_back(false);
        }
    }
}
