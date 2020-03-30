//
// Created by GreenArrow on 2020/2/20.
//
#include <iostream>
#include <queue>
#include <map>

#define column 4
#define row 2
#define A 0
#define B 1
#define C 2
using namespace std;


map<string, int> visited;
char cube[row][column];


void print_test();

typedef struct Node {
    int time;
    string s = "";
} node;
map<string, node> time_;

int m[101][101][101];

class map_ABC {
public:
    string s;
    char c;

    bool operator<(const map_ABC &o) const {
        return s != o.s || c != o.c;
    }
};

map<map_ABC, map_ABC> step;

string AChange() {
    for (int j = 0; j < column; ++j) {
        char temp = cube[0][j];
        cube[0][j] = cube[1][j];
        cube[1][j] = temp;
    }
    string s = "";

    for (int i = 0; i < row; ++i) {
        if (i == 0)
            for (int j = 0; j < column; ++j) {
                s += cube[i][j];
            }
        else
            for (int j = column - 1; j >= 0; --j) {
                s += cube[i][j];
            }
    }

    return s;
}

string BChange() {
    for (int i = 0; i < row; ++i) {
        char temp = cube[i][3];
        for (int j = column - 1; j >= 0; --j) {
            cube[i][j] = cube[i][j - 1];
        }
        cube[i][0] = temp;
    }

    string s = "";

    for (int i = 0; i < row; ++i) {
        if (i == 0)
            for (int j = 0; j < column; ++j) {
                s += cube[i][j];
            }
        else
            for (int j = column - 1; j >= 0; --j) {
                s += cube[i][j];
            }
    }

    return s;
}

string CChange() {
    char temp = cube[0][1];
    cube[0][1] = cube[1][1];
    cube[1][1] = cube[1][2];
    cube[1][2] = cube[0][2];
    cube[0][2] = temp;
    //print_test();
    string s = "";

    for (int i = 0; i < row; ++i) {
        if (i == 0)
            for (int j = 0; j < column; ++j) {
                s += cube[i][j];
            }
        else
            for (int j = column - 1; j >= 0; --j) {
                s += cube[i][j];
            }
    }

    return s;
}

void print_test() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cout << cube[i][j] << " ";
        }
        cout << endl;
    }
}

void change(string s) {
    int index = 0;
    for (int i = 0; i < row; ++i) {
        if (i == 0)
            for (int j = 0; j < column; ++j) {
                cube[i][j] = s[index++];
            }
        else {
            for (int j = column - 1; j >= 0; --j) {
                cube[i][j] = s[index++];
            }
        }
    }
}

int bfs(string begin, string end, map_ABC &result) {

    time_[begin].time = 0;

    map_ABC preMap;
    preMap.s = begin;
    preMap.c = 'O';

    queue<map_ABC> Queue;
    Queue.push(preMap);
    visited[begin] = 1;


    while (!Queue.empty()) {
        map_ABC pre = Queue.front();
        Queue.pop();


        if (pre.s == end) {
            result = pre;
            cout << time_[end].time << endl;

            int index = 0;
            for (int i = 0; i < time_[end].s.length(); ++i) {
                cout << time_[end].s[i];
                index++;
                if (index == 60) {
                    cout << endl;
                    index = 0;
                }
            }

            return time_[end].time;
        }

        for (int i = 0; i < 3; ++i) {
            if (i == A) {
                change(pre.s);
                string s = AChange();
                if (!visited[s]) {
                    visited[s] = 1;

                    time_[s].time = time_[pre.s].time + 1;
                    time_[s].s = time_[pre.s].s + 'A';

                    map_ABC mapAbc;
                    mapAbc.s = s;
                    mapAbc.c = 'A';

                    Queue.push(mapAbc);
                    step[mapAbc] = pre;

                    //cout << "A" << endl;
                }
            } else if (i == B) {
                change(pre.s);
                string s = BChange();
                if (!visited[s]) {
                    visited[s] = 1;

                    time_[s].time = time_[pre.s].time + 1;
                    time_[s].s = time_[pre.s].s + 'B';

                    map_ABC mapAbc;
                    mapAbc.s = s;
                    mapAbc.c = 'B';

                    Queue.push(mapAbc);
                    step[mapAbc] = pre;
                    //cout << "B" << endl;
                }
            } else if (i == C) {
                change(pre.s);
                string s = CChange();
                if (!visited[s]) {
                    visited[s] = 1;

                    time_[s].time = time_[pre.s].time + 1;
                    time_[s].s = time_[pre.s].s + 'C';

                    map_ABC mapAbc;
                    mapAbc.s = s;
                    mapAbc.c = 'C';

                    Queue.push(mapAbc);
                    step[mapAbc] = pre;
                    //cout << "C" << endl;
                }
            }
        }
    }

    return -1;
}

void print_path(map_ABC result) {
//    while (result.c != 'O') {
//        cout << result.c;
//        result = step[result];
//    }
    cout << result.c << endl;
    cout << step.count(result) << endl;
}

int main() {

    string begin = "12345678";
    string end = "";

    for (int i = 0; i < row * column; ++i) {
        char c;
        cin >> c;
        end += c;
    }

    map_ABC mapAbc;

    bfs(begin, end, mapAbc);

    //cout << mapAbc.s << endl;

    //print_path(mapAbc);
/*
    BCABCCB
*/
//    BChange();
//    CChange();
//    AChange();
//    BChange();
//    CChange();
//    CChange();
//    BChange();
//    print_test();
}