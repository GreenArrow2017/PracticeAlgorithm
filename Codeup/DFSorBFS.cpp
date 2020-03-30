//
// Created by GreenArrow on 2020/2/19.
//
#include <iostream>
#include <queue>

using namespace std;
#define max 8

class coordinate {
private:
    int x;
    int y;
public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        coordinate::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        coordinate::y = y;
    }
};

void print(bool visited[max][max]) {
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            if (!visited[i][j]) {
                cout << ".";
            } else
                cout << "@";
        }
        cout << endl;
    }
}

bool checkNext(char maze[max][max], bool (&visited)[max][max], coordinate next) {

    if (next.getX() >= 0 && next.getX() < max && next.getY() >= 0 && next.getY() < max) {
        if (!visited[next.getX()][next.getY()]) {
            if (((maze[next.getX()][next.getY()] != 'S' &&
                  maze[next.getX()][next.getY()] == '.')) || (maze[next.getX()][next.getY()] == 'U')) {
                return true;
            }
        }
    }
    return false;
}

void BFS(char maze[max][max], bool (&visited)[max][max], coordinate begin, coordinate end, bool &flag) {
    if (begin.getX() == end.getX() && begin.getY() == end.getY()) {
        flag = true;
        return;
    }

    coordinate next;


    if (flag) {
        return;
    }

    //down
    next.setX(begin.getX() + 1);
    next.setY(begin.getY());
    if (checkNext(maze, visited, next) && (!visited[next.getX()][next.getY()])) {
        visited[next.getX()][next.getY()] = true;
        BFS(maze, visited, next, end, flag);
        visited[next.getX()][next.getY()] = false;
    }

    //up
    next.setX(begin.getX() - 1);
    next.setY(begin.getY());
    if (checkNext(maze, visited, next) && (!visited[next.getX()][next.getY()])) {
        visited[next.getX()][next.getY()] = true;
        BFS(maze, visited, next, end, flag);
        visited[next.getX()][next.getY()] = false;
    }

    //left
    next.setX(begin.getX());
    next.setY(begin.getY() - 1);
    if (checkNext(maze, visited, next) && (!visited[next.getX()][next.getY()])) {
        visited[next.getX()][next.getY()] = true;
        BFS(maze, visited, next, end, flag);
        visited[next.getX()][next.getY()] = false;
    }

    //right
    next.setX(begin.getX());
    next.setY(begin.getY() + 1);
    if (checkNext(maze, visited, next) && (!visited[next.getX()][next.getY()])) {
        visited[next.getX()][next.getY()] = true;
        BFS(maze, visited, next, end, flag);
        visited[next.getX()][next.getY()] = false;
    }

}

int main() {
    int n;
    char maze[max][max];
    while (cin >> n) {

        cin.ignore();

        for (int i = 0; i < n; ++i) {

            coordinate begin, end;
            bool visited[max][max] = {false};

            for (int j = 0; j < max; ++j) {
                for (int k = 0; k < max; ++k) {

                    cin >> maze[j][k];
                    if (maze[j][k] == 'A') {
                        begin.setX(j);
                        begin.setY(k);
                    }
                    if (maze[j][k] == 'U') {
                        end.setX(j);
                        end.setY(k);
                    }

                }
            }


            bool flag = false;


            BFS(maze, visited, begin, end, flag);
            if (flag) {
                cout << "Case #" << i + 1 << ": " << "Yes" << endl;
            } else
                cout << "Case #" << i + 1 << ": " << "No" << endl;

        }
    }
}