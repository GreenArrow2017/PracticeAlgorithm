//
// Created by GreenArrow on 2020/3/8.
//
#include <iostream>
#include <algorithm>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>

#define boy true
#define girl false
#define MAX 10010
using namespace std;

class node {
public:
    int ID;
    bool gender = boy;

    node(int ID, bool gender) {
        this->ID = ID;
        this->gender = gender;
    }

    node() {}
};

class relationShip {
public:
    int a, b;

    relationShip(int a, int b) {
        this->a = a;
        this->b = b;
    }
};

int string2int(string s) {
    int sign = 1;
    int index = 0;
    if (s[0] == '-') {
        sign = -1;
        index++;
    }
    int sum = 0;
    for (int i = index; i < s.length(); ++i) {
        sum = sum * 10 + (s[i] - '0');
    }
    return sum;
}

bool cmp(relationShip a, relationShip b) {
    return a.a != b.a ? a.a < b.a : a.b < b.b;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<node> Nodes[MAX];
    map<int, bool> map_relation;

    for (int i = 0; i < m; ++i) {
        string id1, id2;
        cin >> id1 >> id2;

        if (id1.length() == id2.length()) {
            int id1_int = string2int(id1);
            bool gender1 = (id1[0] != '-');
            node id1Node(id1_int, gender1);

            int id2_int = string2int(id2);
            bool gender2 = (id2[0] != '-');
            node id2Node(id2_int, gender2);

            Nodes[id1_int].push_back(id2Node);
            Nodes[id2_int].push_back(id1Node);

        }
        map_relation[abs(string2int(id1) * 10000 + abs(string2int(id2)))] = true;
        map_relation[abs(string2int(id2) * 10000 + abs(string2int(id1)))] = true;

    }

    int k;
    cin >> k;
    for (int l = 0; l < k; ++l) {
        int a, b;
        cin >> a >> b;
        vector<relationShip> ans;
        for (int i = 0; i < Nodes[abs(a)].size(); ++i) {
            for (int j = 0; j < Nodes[abs(b)].size(); ++j) {
                if (Nodes[abs(a)][i].ID == abs(b) || Nodes[abs(b)][j].ID == abs(a))
                    continue;
                if (map_relation[abs(Nodes[abs(a)][i].ID) * 10000 + abs(Nodes[abs(b)][j].ID)]) {
                    ans.push_back(relationShip(abs(Nodes[abs(a)][i].ID), abs(Nodes[abs(b)][j].ID)));
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans.size() << endl;
        for (int i1 = 0; i1 < ans.size(); ++i1) {
            printf("%04d %04d\n", ans[i1].a, ans[i1].b);
        }
    }

}

