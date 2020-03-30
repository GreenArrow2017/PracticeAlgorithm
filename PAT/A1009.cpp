//
// Created by GreenArrow on 2020/3/12.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define MAX 1010
#define MAX_Result 2010
using namespace std;

typedef struct node {
    int exponent;
    double coefficient;
} *Node, node;

int cmp(node a, node b) {
    return a.exponent > b.exponent;
}

int main() {
    int n;
    cin >> n;
    double first[MAX];
    vector<int> firsts;
    fill(first, first + MAX, 0);
    for (int i = 0; i < n; ++i) {
        int exponent;
        double coefficient;
        cin >> exponent >> coefficient;
        first[exponent] = coefficient;
        firsts.push_back(exponent);
    }

    int m;
    cin >> m;
    double second[MAX];
    vector<int> seconds;
    fill(second, second + MAX, 0);
    for (int j = 0; j < m; ++j) {
        int exponent;
        double coefficient;
        cin >> exponent >> coefficient;
        second[exponent] = coefficient;
        seconds.push_back(exponent);
    }

    double result[MAX_Result];
    int max = 0;
    fill(result, result + MAX_Result, 0);
    for (int i = 0; i < firsts.size(); ++i) {
        int expFirst = firsts[i];
        for (int j = 0; j < seconds.size(); ++j) {
            int expSecond = seconds[j];
            int expNext = expFirst + expSecond;
            max = ((max > expNext) ? max : expNext);
            double results = first[expFirst] * second[expSecond];
            result[expNext] = result[expNext] + results;
        }
    }


    vector<node> nodes;
    for (int k = 0; k <= max; ++k) {
        if (result[k] != 0) {
            node node1;
            node1.exponent = k;
            node1.coefficient = result[k];
            nodes.push_back(node1);
        }
    }

    if (nodes.size() == 0) {
        cout << 0;
        return 0;
    }

    cout << nodes.size() << " ";

    sort(nodes.begin(), nodes.end(), cmp);

    for (int l = 0; l < nodes.size(); ++l) {
        cout << nodes[l].exponent << " ";
        printf("%.1lf", nodes[l].coefficient);
        if (l != nodes.size() - 1) {
            cout << " ";
        }
    }
}
