//
// Created by GreenArrow on 2020/9/26.
//

#include <iostream>
#include <vector>
#include <map>
#include<ctime>

using namespace std;

class FutoshikiPuzzle {
public:

    class node {
    public:
        //当前位置的值
        int val = 0;
        //候选队列，false代表可以选择
        bool digits[10] = {false, false, false, false, false, false, false, false, false, false};
    };

    //地图
    vector<vector<node>> maps;
    //限制
    vector<pair<pair<int, int>, pair<int, int>>> less_constraints;
    int nRow, nColumn;

    void initial() {
        vector<vector<int>> copy_map = {{6, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 7, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 5, 8},
                                        {0, 0, 0, 0, 0, 0, 0, 8, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 2, 4}};
        nRow = copy_map.size();
        nColumn = copy_map[0].size();

        maps.resize(nRow);

        //复制到真实地图上
        for (int i = 0; i < nRow; i++) {
            maps[i].resize(nColumn);
            for (int j = 0; j < nColumn; j++) {
                maps[i][j].val = copy_map[i][j];
            }
        }



        //添加限制
        addConstraints(0, 0, 1, 0);
        addConstraints(0, 6, 0, 5);
        addConstraints(0, 7, 0, 8);
        addConstraints(1, 3, 1, 2);
        addConstraints(0, 4, 1, 4);
        addConstraints(2, 6, 1, 6);
        addConstraints(1, 4, 1, 5);
        addConstraints(3, 0, 2, 0);
        addConstraints(3, 1, 2, 1);
        addConstraints(2, 2, 3, 2);
        addConstraints(2, 2, 2, 3);
        addConstraints(2, 6, 2, 5);
        addConstraints(2, 7, 2, 8);
        addConstraints(2, 3, 1, 3);
        addConstraints(4, 1, 3, 1);
        addConstraints(3, 2, 4, 2);
        addConstraints(3, 3, 4, 3);
        addConstraints(4, 5, 3, 5);
        addConstraints(3, 5, 3, 6);
        addConstraints(3, 6, 2, 6);
        addConstraints(4, 7, 3, 7);
        addConstraints(3, 8, 4, 8);
        addConstraints(4, 2, 4, 1);
        addConstraints(4, 4, 4, 5);
        addConstraints(4, 5, 4, 6);
        addConstraints(4, 8, 4, 7);
        addConstraints(4, 6, 5, 6);
        addConstraints(5, 0, 5, 1);
        addConstraints(5, 4, 5, 5);
        addConstraints(5, 6, 5, 5);
        addConstraints(5, 7, 5, 6);
        addConstraints(6, 6, 6, 5);
        addConstraints(6, 0, 7, 0);
        addConstraints(6, 1, 7, 1);
        addConstraints(7, 3, 6, 3);
        addConstraints(7, 4, 6, 4);
        addConstraints(8, 5, 7, 5);
        addConstraints(7, 5, 7, 6);
        addConstraints(7, 6, 7, 7);
        addConstraints(7, 8, 8, 8);
        addConstraints(8, 1, 8, 0);
        addConstraints(8, 2, 8, 1);
        addConstraints(8, 4, 8, 3);

        //根据已经填写的数字开始删除各个位置的候选值
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (maps[i][j].val != 0)
                    vector<pair<pair<int, int>, int>> catches = check(i, j);
            }
        }
    }

    void addConstraints(int x, int y, int x1, int y1) {
        less_constraints.push_back({{x,  y},
                                    {x1, y1}});
    }

    //删除候选值
    vector<pair<pair<int, int>, int>> check(int x, int y) {
        //缓存，如果失败可能需要回溯
        vector<pair<pair<int, int>, int>> catches;
        //纵向横向删除候选值：
        for (int i = 0; i < nRow; i++) {
            //如果本来就是false，那就没必要加入缓存了
            if (!maps[i][y].digits[maps[x][y].val]) {
                maps[i][y].digits[maps[x][y].val] = true;
                //意思是在[i,y]格子的候选者中删除了maps[x][y].val候选者
                catches.push_back({{i, y}, maps[x][y].val});
            }

            if (!maps[x][i].digits[maps[x][y].val]) {
                maps[x][i].digits[maps[x][y].val] = true;
                catches.push_back({{x, i}, maps[x][y].val});
            }
        }

        //删除关于限制的候选值
        for (int i = 0; i < less_constraints.size(); i++) {
            if (x == less_constraints[i].first.first && y == less_constraints[i].first.second) {
                for (int j = maps[x][y].val; j >= 1; j--) {
                    if (!maps[less_constraints[i].second.first][less_constraints[i].second.second].digits[j]) {
                        maps[less_constraints[i].second.first][less_constraints[i].second.second].digits[j] = true;
                        catches.push_back({{less_constraints[i].second.first, less_constraints[i].second.second}, j});
                    }
                }
            }

            if (x == less_constraints[i].second.first && y == less_constraints[i].second.second) {
                for (int j = maps[x][y].val; j <= 9; j++) {
                    if (!maps[less_constraints[i].first.first][less_constraints[i].first.second].digits[j]) {
                        maps[less_constraints[i].first.first][less_constraints[i].first.second].digits[j] = true;
                        catches.push_back({{less_constraints[i].first.first, less_constraints[i].first.second}, j});
                    }
                }
            }
        }
        return catches;
    }

    bool search(int x, int y) {
        if (maps[x][y].val == 0) {
            for (int i = 1; i < 10; i++) {
                //还在队列中没有被访问过
                if (!maps[x][y].digits[i]) {
                    maps[x][y].val = i;
                    //返回缓存，缓存存储了三个特征，横坐标，纵坐标，删除的值。恢复只需要把候选队列中的值变为true即可。
                    vector<pair<pair<int, int>, int>> catches = check(x, y);
                    if (x == 8 && y == 8) {
                        return true;
                    }
                    int next_x, next_y;
                    if (y != 8) {
                        next_x = x;
                        next_y = y + 1;
                    } else {
                        next_x = x + 1;
                        next_y = 0;
                    }


                    if (search(next_x, next_y)) {
                        return true;
                    }
                    //查找失败，需要回退到上一版本。这里回退比较简单，只需要设置true即可
                    pull_back(catches);
                    maps[x][y].val = 0;
                }
            }
        } else {
            //当前位置已经填上，只需要跳过即可
            if (x == 8 && y == 8) {
                return true;
            }
            int next_x, next_y;
            if (y != 8) {
                next_x = x;
                next_y = y + 1;
            } else {
                next_x = x + 1;
                next_y = 0;
            }


            if (search(next_x, next_y)) {
                return true;
            }
        }
        return false;
    }

    //倒退。根据缓存倒退上一版本
    void pull_back(vector<pair<pair<int, int>, int>> catches) {
        for (int i = 0; i < catches.size(); i++) {
            int x = catches[i].first.first;
            int y = catches[i].first.second;
            int digit = catches[i].second;
            maps[x][y].digits[digit] = false;
        }
    }

    void show() {
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                cout << maps[i][j].val << " ";
            }
            cout << endl;
        }
        cout << "======================" << endl;
    }


};

int main() {
    FutoshikiPuzzle *futoshikiPuzzle = new FutoshikiPuzzle();
    //初始化
    futoshikiPuzzle->initial();
    //显示空表
    futoshikiPuzzle->show();
    //记录时间
    clock_t start, end;
    start = clock();
    //开始搜索
    futoshikiPuzzle->search(0, 0);
    end = clock();

    //显示最终结果
    futoshikiPuzzle->show();

    cout << "FC Time cost : " << (double) (end - start) / CLOCKS_PER_SEC << " s" << endl;
}