//
// Created by GreenArrow on 2020/6/11.
//

#include "Astar.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//
// map : vector<vector<string>>
// stone : #
// path : *
// start point and end point : @
//

int main() {
    map *m = new map();
    m->nRow = 20;
    m->nColumn = 20;
    m->beginning = {0, 0};
    m->ending = {13, 15};
    m->walls = {{1,  0},
                {2,  5},
                {5,  6},
                {13,  9},
                {13,  8},
                {12,  8},
                {11,  8},
                {10,  8},
                {9,  8},
                {8,  8},
                {7,  8},
                {6,  8},
                {5,  8},
                {4,  8},
                {3,  8},
                {11, 13},
                {10, 11},
                {12, 2}};

//    m->nRow = 6;
//    m->nColumn = 8;
//    m->beginning = {2, 2};
//    m->ending = {2, 6};
//    m->walls = {{1, 4},
//                {2, 4},
//                {3, 4}};


    m->generateMap();
    m->showMaps();
    cout << "====================================" << endl;
    m->AStarAlgorithm();
    m->calculatePath();
    m->showPathsHadCalculate();
    cout << "====================================" << endl;

    m->showMapsWithPaths();
    cout << "====================================" << endl;

}
