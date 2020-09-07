//
// Created by GreenArrow on 2020/6/11.
//

#ifndef PRACTICEALGORITHM_ASTAR_H
#define PRACTICEALGORITHM_ASTAR_H

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class node {
private:
    int x, y;
    node *parent;
    double G;
    double H;
    double F;

public:
    node(int x, int y, node *parent) {
        this->x = x;
        this->y = y;
        this->parent = parent;
        G = 0;
        H = 0;
        F = 0;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        node::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        node::y = y;
    }

    node *getParent() const {
        return parent;
    }

    void setParent(node *parent) {
        node::parent = parent;
    }

    double getG() const {
        return G;
    }

    void setG(double g) {
        G = g;
    }

    double getH() const {
        return H;
    }

    void setH(double h) {
        H = h;
    }

    double getF() const {
        return F;
    }

    void setF(double f) {
        F = f;
    }


};

class map {
public:

    int direction[8][2] = {{0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0},
                           {1,  1},//右上
                           {1,  -1},//左下
                           {-1, 1},//右下
                           {-1, -1}};//左上

    int nRow;
    int nColumn;
    pair<int, int> beginning;
    pair<int, int> ending;
    vector<pair<int, int>> walls;
    vector<string> maps;
    vector<bool> visited_open;
    vector<bool> visited_end;
    //F G node
    vector<node *> openList;
    vector<node *> endList;

    vector<pair<int, int>> paths;

    void generateMap() {
        vector<string> results;
        results.resize(nRow);
        visited_open.resize(nRow * nColumn);
        visited_end.resize(nRow * nColumn);
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                results[i][j] = '.';
            }
        }
        for (int i = 0; i < walls.size(); i++) {
            results[walls[i].first][walls[i].second] = '#';
        }
        results[beginning.first][beginning.second] = '@';
        results[ending.first][ending.second] = '@';
        maps = results;
    }

    void showMaps() {
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                cout << maps[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void showMapsWithPaths() {
        vector<string> map_copy;
        map_copy.assign(maps.begin(), maps.end());
        for (int i = 0; i < paths.size(); i++) {
            map_copy[paths[i].first][paths[i].second] = '>';
        }
        map_copy[ending.first][ending.second] = '@';
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                cout << map_copy[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void showPathsHadCalculate() {
        vector<string> map_copy;
        map_copy.assign(maps.begin(), maps.end());

        for (int i = 0; i < endList.size(); i++) {
            map_copy[endList[i]->getX()][endList[i]->getY()] = '*';
        }
        for (int i = 0; i < openList.size(); i++) {
            map_copy[openList[i]->getX()][openList[i]->getY()] = '*';
        }


        for (int i = 0; i < paths.size(); i++) {
            map_copy[paths[i].first][paths[i].second] = '>';
        }
        map_copy[ending.first][ending.second] = '@';
        map_copy[beginning.first][beginning.second] = '@';


        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                cout << map_copy[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void AStarAlgorithm() {
        node *begin = new node(beginning.first, beginning.second, nullptr);
        begin->setF(0);
        begin->setG(0);
        begin->setH(0);
        //起始点丢进openlist里面,更新最小点
        openList.push_back(begin);
        visited_open[begin->getX() * nColumn + begin->getY()] = true;

        while (!openList.empty()) {
            int index = getLowestF();
            node *current = openList[index];

            //cout << current->getX() << " " << current->getY() << endl;

            openList.erase(openList.begin() + index);

            endList.push_back(current);
            visited_end[current->getX() * nColumn + current->getY()] = true;
            if (current->getX() == ending.first && current->getY() == ending.second) {
                return;
            }

            addPoint(current);
        }
    }


    void addPoint(node *current) {
        //判断上下左右能不能走
        for (int i = 0; i < 4; i++) {
            int x_next = current->getX() + direction[i][0];
            int y_next = current->getY() + direction[i][1];
            if (inSide(x_next, y_next) && maps[x_next][y_next] != '#') {
                if (!visited_end[x_next * nColumn + y_next]) {
                    //从来没有访问过
                    if (!visited_open[x_next * nColumn + y_next]) {
                        node *next = new node(x_next, y_next, current);
                        double next_G = current->getG() + 10;
                        double next_H = abs(x_next - ending.first) * 10 + abs(y_next - ending.second) * 10;
                        double next_F = next_G + next_H;
                        next->setG(next_G);
                        next->setH(next_H);
                        next->setF(next_G + next_H);

                        openList.push_back(next);

                        visited_open[x_next * nColumn + y_next] = true;


                    }
                        //已经在open里面了,是否更新G值
                    else {
                        double new_G = current->getG() + 10;
                        node *a = findQueue(x_next, y_next);
                        if (a->getG() > new_G) {
                            a->setG(new_G);
                            a->setF(a->getH() + a->getG());
                            a->setParent(current);
                        }
                    }
                }
            }
        }
        for (int i = 4; i < 8; i++) {
            int x_next = current->getX() + direction[i][0];
            int y_next = current->getY() + direction[i][1];
            if (inSide(x_next, y_next) && triangleWall(current, i) && maps[x_next][y_next] != '#') {
                if (!visited_end[x_next * nColumn + y_next]) {
                    if (!visited_open[x_next * nColumn + y_next]) {
                        node *next = new node(x_next, y_next, current);
                        double next_G = current->getG() + 14;
                        double next_H = abs(x_next - ending.first) * 10 + abs(y_next - ending.second) * 10;
                        double next_F = next_G + next_H;
                        next->setG(next_G);
                        next->setF(next_F);
                        next->setH(next_H);

                        openList.push_back(next);

                        visited_open[x_next * nColumn + y_next] = true;


                    } else {
                        double new_G = current->getG() + 14;
                        node *a = findQueue(x_next, y_next);
                        if (a->getG() > new_G) {
                            a->setG(new_G);
                            a->setF(a->getH() + a->getG());
                            a->setParent(current);
                        }
                    }
                }
            }
        }
    }

    bool triangleWall(node *current, int direct) {
        if (direct == 4 || direct == 6) {
            if (direct == 4) {
                if (maps[current->getX()][current->getY() + 1] == '#') {
                    return false;
                }
                if (maps[current->getX() + 1][current->getY()] == '#') {
                    return false;
                }
            }
            if (direct == 6) {
                if (maps[current->getX()][current->getY() + 1] == '#') {
                    return false;
                }
                if (maps[current->getX() - 1][current->getY()] == '#') {
                    return false;
                }
            }
        }

        if (direct == 5 || direct == 7) {
            if (direct == 5) {
                if (maps[current->getX()][current->getY() - 1] == '#') {
                    return false;
                }
                if (maps[current->getX() + 1][current->getY()] == '#') {
                    return false;
                }
            }
            if (direct == 7) {
                if (maps[current->getX()][current->getY() - 1] == '#') {
                    return false;
                }
                if (maps[current->getX() - 1][current->getY()] == '#') {
                    return false;
                }
            }
        }
        return true;
    }

    int getLowestF() {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < openList.size(); i++) {
            if (min > openList[i]->getF()) {
                min = openList[i]->getF();
                index = i;
            }
        }
        return index;
    }

    bool inSide(int x, int y) {
        return x >= 0 && x < nRow && y >= 0 && y < nColumn;
    }

    node *findQueue(int x, int y) {
        for (int i = 0; i < openList.size(); i++) {
            if (openList[i]->getX() == x && openList[i]->getY() == y) {
                return openList[i];
            }
        }
        return nullptr;
    }

    void calculatePath() {
        if (endList[endList.size() - 1]->getX() == ending.first &&
            endList[endList.size() - 1]->getY() == ending.second) {

            node *current = endList[endList.size() - 1];
            while (current->getParent() != nullptr) {
                paths.push_back({current->getX(), current->getY()});
                current = current->getParent();
            }

            reverse(paths.begin(), paths.end());
        }
    }


};

#endif //PRACTICEALGORITHM_ASTAR_H
