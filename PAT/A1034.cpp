//
// Created by GreenArrow on 2020/3/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

#define MAX 2001
using namespace std;

class edge {
public:
    int end;
    int weight;

    edge(int name, int weight) {
        this->end = name;
        this->weight = weight;
    }

    edge() {

    }
};

class result {
public:
    int name;
    int size;

    result(int name, int size) {
        this->name = name;
        this->size = size;
    }
};

int totalPhone[MAX] = {0};
map<int, vector<edge>> edges;
vector<int> graphs[MAX];
bool visited[MAX];
string name[MAX];
vector<result> results;
map<string, int> name2int;
int nameIndex = 0;

int cmp(result a, result b) {
    return name[a.name] < name[b.name];
}

int string2number(string s) {
    if (name2int.count(s) > 0) {
        return name2int[s];
    } else {
        name2int[s] = nameIndex;
        nameIndex++;
        return name2int[s];
    }
}

int addEdges(int v, int total) {

    for (int i = 0; i < edges[v].size(); ++i) {
        total += edges[v][i].weight;
    }

    return total;
}

void BFS(int v, int &size, int &total, vector<int> &gangs) {
    visited[v] = true;
    for (int i = 0; i < graphs[v].size(); ++i) {
        if (!visited[graphs[v][i]]) {

            gangs.push_back(graphs[v][i]);

            total = addEdges(graphs[v][i], total);

            size++;

            BFS(graphs[v][i], size, total, gangs);
        }
    }
}

int main() {
    int n;
    int K;

    cin >> n >> K;

    fill(visited, visited + MAX, true);


    for (int i = 0; i < n; ++i) {
        string A, B;
        int weight;
        cin >> A >> B >> weight;
        int ANumber = string2number(A), BNumber = string2number(B);

        name[ANumber] = A;
        name[BNumber] = B;

        visited[ANumber] = false;
        visited[BNumber] = false;

        graphs[ANumber].push_back(BNumber);
        graphs[BNumber].push_back(ANumber);

        if (edges.count(ANumber) == 0) {
            vector<edge> e;
            e.emplace_back(BNumber, weight);
            edges[ANumber] = e;
        } else {
            edges[ANumber].push_back(edge(BNumber, weight));
        }

        totalPhone[ANumber] += weight;
        totalPhone[BNumber] += weight;
    }

    int index_ = 0;

    for (int j = 0; j < MAX; ++j) {
        if (!visited[j]) {

            int size = 1, total = 0;
            vector<int> gangs;

            gangs.push_back(j);

            total += addEdges(j, total);

            BFS(j, size, total, gangs);

            if (total > K && size > 2) {
                index_++;
                int id;
                int max = INT_MIN;
                for (int i = 0; i < gangs.size(); ++i) {
                    if (totalPhone[gangs[i]] > max) {
                        max = totalPhone[gangs[i]];
                        id = gangs[i];
                    }
                }
                results.push_back(result(id, size));
            }


        }
    }

    sort(results.begin(), results.end(), cmp);

    cout << index_ << endl;
    for (int k = 0; k < results.size(); ++k) {
        cout << name[results[k].name] << " " << results[k].size << endl;
    }

}
