//
// Created by GreenArrow on 2020/3/3.
//
#include <iostream>
#include <vector>

#define MAX 110
using namespace std;
char chess[MAX][MAX];
bool isWords[MAX][MAX] = {false};
int n;


typedef struct node {
    int x, y;
} *Node, node;
vector<Node> words;

void changeStatus() {
    for (int i = 0; i < words.size(); i++) {
        Node word = words[i];
        isWords[word->x][word->y] = true;
        //cout << word->x << " " << word->y << endl;
    }

}

void print_test() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << isWords[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool moveOn(Node current, int direction, int index, string s, Node &move) {
    //往上走
    if (direction == 0) {
        if (current->x <= 0 || chess[current->x - 1][current->y] != s[index]) {
            return false;
        }
        move->x = current->x - 1;
        move->y = current->y;
        //往下走
    } else if (direction == 1) {
        if (current->x >= n || chess[current->x + 1][current->y] != s[index]) {
            return false;
        }
        move->x = current->x + 1;
        move->y = current->y;
        //往左走
    } else if (direction == 2) {
        if (current->y <= 0 || chess[current->x][current->y - 1] != s[index]) {
            return false;
        }
        move->y = current->y - 1;
        move->x = current->x;
        //往右走
    } else if (direction == 3) {
        if (current->y >= n || chess[current->x][current->y + 1] != s[index]) {
            return false;
        }
        move->y = current->y + 1;
        move->x = current->x;
        //往左上
    } else if (direction == 4) {
        if ((current->x <= 0 || current->y <= 0) || chess[current->x - 1][current->y - 1] != s[index]) {
            return false;
        }
        move->x = current->x - 1;
        move->y = current->y - 1;
        //往右上
    } else if (direction == 5) {
        if ((current->x <= 0 || current->y >= n) || chess[current->x - 1][current->y + 1] != s[index]) {
            return false;
        }
        move->x = current->x - 1;
        move->y = current->y + 1;
        //往左下
    } else if (direction == 6) {
        if ((current->x >= n || current->y <= 0) || chess[current->x + 1][current->y - 1] != s[index]) {
            return false;
        }
        move->x = current->x + 1;
        move->y = current->y - 1;
    } else if (direction == 7) {
        if ((current->x >= n || current->y >= n) || chess[current->x + 1][current->y + 1] != s[index]) {
            return false;
        }
        move->x = current->x + 1;
        move->y = current->y + 1;
    }
    return true;
}

void getWords(int column, int row, string s) {
    Node begin = new node;
    begin->x = column;
    begin->y = row;
    //8个方向
    for (int i = 0; i < 8; ++i) {
        Node first = new node;
        first->x = column;
        first->y = row;
        words.push_back(first);
        Node move = new node;
        int index = 0;
        while (moveOn(begin, i, index + 1, s, move)) {
            index++;
            words.push_back(move);
            if (index == s.length() - 1) {
                changeStatus();
                break;
            }
            vector<Node> newNode = words;
            begin->x = move->x;
            begin->y = move->y;
            move = new node;
        }
        begin->x = column;
        begin->y = row;
        words.clear();
        //print_test();
    }
}

void checkWords(int n, string s) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (chess[i][j] == 'y') {
                getWords(i, j, s);
            }
        }
    }
}

int main() {
    cin >> n;
    string s = "yizhong";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> chess[i][j];
        }
    }

    checkWords(n, s);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (isWords[k][i]) {
                cout << chess[k][i];
            } else
                cout << "*";
        }
        cout << endl;
    }
}

