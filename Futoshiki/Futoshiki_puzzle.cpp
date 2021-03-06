//
// Created by GreenArrow on 2020/9/14.
//

#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

class FutoshikiPuzzle {
public:
    vector<vector<int>> maps;
    vector<pair<pair<int, int>, pair<int, int>>> less_constraints;
    int nRow, nColumn;
    //表示第x行中某个数字是否存在
    int Count_RowNumbers[9][10];
    //表示第y列某个数字是否存在
    int Count_ColumnNumbers[9][10];

    void initial() {



        //初始地图
        maps = {{6, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 5, 8},
                {0, 0, 0, 0, 0, 0, 0, 8, 0},
                {0, 0, 0, 0, 0, 0, 0, 2, 4}};
        nRow = maps.size();
        nColumn = maps[0].size();


        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (maps[i][j] != 0) {
                    Count_RowNumbers[i][maps[i][j]]++;
                    Count_ColumnNumbers[j][maps[i][j]]++;
                }
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

    }

    void addConstraints(int x, int y, int x1, int y1) {
        less_constraints.push_back({{x,  y},
                                    {x1, y1}});
    }

    //检查当前位置是否可行
    bool check(int x, int y) {
        for (int i = 1; i < 10; i++) {
            if (Count_RowNumbers[x][i] > 1 || Count_ColumnNumbers[y][i] > 1) {
                return false;
            }
        }

        for (auto &less_constraint : less_constraints) {
            if (less_constraint.first.first == x && less_constraint.first.second == y) {
                if (maps[x][y] == 9) {
                    return false;
                }
                if (maps[less_constraint.second.first][less_constraint.second.second] > 0 &&
                    maps[less_constraint.second.first][less_constraint.second.second] <= maps[x][y]) {

                    return false;
                }
            }
        }

        for (auto &less_constraint : less_constraints) {
            if (less_constraint.second.first == x && less_constraint.second.second == y) {
                if (maps[x][y] == 1) {

                    return false;
                }
                if (maps[less_constraint.first.first][less_constraint.first.second] > 0 &&
                    maps[less_constraint.first.first][less_constraint.first.second] >= maps[x][y]) {

                    return false;
                }
            }
        }
        return true;
    }

    //显示图片
    void show() {
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                cout << maps[i][j] << " ";
            }
            cout << endl;
        }
        cout << "======================" << endl;
    }

    bool search(int x, int y) {

        if (maps[x][y] == 0) {
            for (int i = 1; i < 10; i++) {
                maps[x][y] = i;
                Count_RowNumbers[x][i]++;
                Count_ColumnNumbers[y][i]++;
                if (check(x, y)) {
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
                maps[x][y] = 0;
                Count_RowNumbers[x][i]--;
                Count_ColumnNumbers[y][i]--;
            }
        } else {
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
};

int main() {
    FutoshikiPuzzle *futoshikiPuzzle = new FutoshikiPuzzle();
    futoshikiPuzzle->initial();
    futoshikiPuzzle->show();
    clock_t start,end;
    start = clock();
    futoshikiPuzzle->search(0, 0);
    end = clock();
    futoshikiPuzzle->show();
    cout<< "BT Time cost : " <<(double)(end-start)/CLOCKS_PER_SEC << " s" << endl;
}