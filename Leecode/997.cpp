//
// Created by GreenArrow on 2020/7/28.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

class node{
public:
    int x = 0;
    int y = 0;
    node(){cout << "create" << endl;}
    ~node(){cout << "delete" << endl;}
};


int main() {

    vector<node*> nodes;
    for(int i = 0;i < 3;i++){
        node p;
        nodes.push_back(&p);
    }

    nodes[0]->x++;

    for(int i = 0;i < 3;i++){
        cout << nodes[i]->x << endl;
    }

}