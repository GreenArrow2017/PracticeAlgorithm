//
// Created by GreenArrow on 2020/2/19.
//

#include <iostream>
#include <map>
#include <queue>

#define max 3
#define up 0
#define down 1
#define left 2
#define right 3
using namespace std;

map<string, int> visited;
char chess[max][max] = {0};
map<string, int> step;
queue<string> Queue;

void print_test(char chess[max][max]);

void change(string u, int &x, int &y) {
    int index = 0;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            chess[i][j] = u[index++];
            if (chess[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }

}

void input_panel(string &begin, string &end) {
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            char c;
            cin >> c;
            begin += c;
        }
    }

    for (int k = 0; k < max; ++k) {
        for (int i = 0; i < max; ++i) {
            char c;
            cin >> c;
            end += c;
        }
    }

    //cout << "begin : " << begin << endl;
    //cout << "end : " << end << endl;
}


bool canMove(int direction, string u) {
    int x, y;
    change(u, x, y);

    if (direction == up) {
        if (x <= 0) {
            return false;
        }
    } else if (direction == down) {
        if (x >= max - 1) {
            return false;
        }
    } else if (direction == left) {
        if (y <= 0) {
            return false;
        }
    } else if (direction == right) {
        if (y >= max - 1) {
            return false;
        }
    }
    return true;
}

string move(int direction) {
    int x, y;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            if (chess[i][j] == '0') {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (direction == up) {
        int next_x = x - 1;
        int next_y = y;

        char temp = chess[x][y];
        chess[x][y] = chess[next_x][next_y];
        chess[next_x][next_y] = temp;
    } else if (direction == down) {
        int next_x = x + 1;
        int next_y = y;

        char temp = chess[x][y];
        chess[x][y] = chess[next_x][next_y];
        chess[next_x][next_y] = temp;
    } else if (direction == left) {
        int next_x = x;
        int next_y = y - 1;

        char temp = chess[x][y];
        chess[x][y] = chess[next_x][next_y];
        chess[next_x][next_y] = temp;
    } else if (direction == right) {
        int next_x = x;
        int next_y = y + 1;

        char temp = chess[x][y];
        chess[x][y] = chess[next_x][next_y];
        chess[next_x][next_y] = temp;
    }

    string s = "";
    for (int k = 0; k < max; ++k) {
        for (int i = 0; i < max; ++i) {
            s += chess[k][i];
        }
    }
    return s;
}

int bfs(string begin, string end) {
    visited[begin] = 1;
    Queue.push(begin);
    step[begin] = 1;
    while (!Queue.empty()) {
        string n = Queue.front();
        Queue.pop();
        if (n == end) {
            return step[end];
        }
        for (int i = 0; i < 4; ++i) {
            if (canMove(i, n)) {
                string s = move(i);
                if (!visited[s]) {
                    visited[s] = 1;
                    Queue.push(s);
                    //print_test(chess);
                    step[s] = step[n] + 1;
                }
            }
        }
    }
}

int main() {

    string begin, end;
    input_panel(begin, end);
    cout << bfs(begin, end) << endl;
}

void print_test(char chess[max][max]) {
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
