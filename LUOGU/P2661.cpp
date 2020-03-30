//
// Created by GreenArrow on 2020/2/29.
//
#include <iostream>
#include <climits>

#define MAX 200002
using namespace std;

int min = INT_MAX;
int father[MAX];
int d[MAX] = {0};

int findFather(int a) {
    while (father[a] != a) {
        a = father[a];
    }
    return a;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = father[faB];

    }
}

int main() {

    for (int i = 0; i < MAX; ++i) {
        father[i] = i;
    }

}
