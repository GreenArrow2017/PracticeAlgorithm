//
// Created by GreenArrow on 2020/8/11.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    class nodes {
    public:
        vector<int> nodes;
        string tips;
    };

    vector<nodes> graphs;
    map<int, nodes *> maps;

    int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {

        int n = routes.size() + 2;
        

    }

    vector<int> vectors_set_union(vector<int> v1, vector<int> v2) {
        vector<int> v;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));//求交集
        return v;
    }

};

