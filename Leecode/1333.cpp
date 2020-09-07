//
// Created by GreenArrow on 2020/7/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(vector<int> a, vector<int> b) {
    if (a[1] != b[1]) {
        return a[1] > b[1];
    } else {
        return a[0] > b[0];
    }
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {

        vector<vector<int>> filters;

        for (vector<int> rest : restaurants) {
            if (rest[3] <= maxPrice && rest[4] <= maxDistance) {
                if (veganFriendly && rest[2]) {
                    filters.push_back(rest);
                } else if(!veganFriendly){
                    filters.push_back(rest);
                }
            }
        }

        sort(filters.begin(), filters.end(), compare);

        vector<int> results;
        for (vector<int> rest : filters) {
            results.push_back(rest[0]);
        }
        return results;
    }


};