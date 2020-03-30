//
// Created by GreenArrow on 2020/3/3.
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;


class map_string {
public:
    string origin;
    string exchange;

    map_string(string origin, string exchange) {
        this->origin = origin;
        this->exchange = exchange;
    }

    map_string() {

    }
};

map<string, int> visited;
queue<string> Queue;
vector<map_string> map_strings;

bool canChange(string cur, string origin, vector<int> &mark) {
    for (int i = 0; i < cur.length(); ++i) {

        int index = i;
        int mark_ = i;
        bool isOK = true;
        int j;
        for (j = 0; j < origin.length() && index < cur.length(); ++j, ++index) {
            if (cur[index] != origin[j]) {
                isOK = false;
                break;
            }
        }
        if (isOK && j == origin.length()) {
            mark.push_back(mark_);
        }
    }
    return mark.size() > 0;
}

vector<string> change(string cur, map_string origin_map, vector<int> marks) {

    vector<string> strings;
    for (int i = 0; i < marks.size(); ++i) {
        int mark = marks[i];
        string head = cur.substr(0, mark);
        string body = origin_map.exchange;
        string tile = cur.substr(mark + origin_map.origin.length(), cur.length() - (mark + origin_map.origin.length()));
        string next = head + body + tile;
        strings.push_back(next);
    }
    return strings;
}

int BFS(string begin, string end) {
    Queue.push(begin);
    visited[begin] = 1;
    while (!Queue.empty()) {
        string cur = Queue.front();
        //cout << cur << endl;
        Queue.pop();
        if (cur == end) {
            return visited[cur];
        }
        for (int i = 0; i < map_strings.size(); ++i) {
            string origin = map_strings[i].origin;
            map_string origin_map = map_strings[i];
            vector<int> mark;
            if (canChange(cur, origin, mark)) {
                vector<string> nexts = change(cur, origin_map, mark);
                for (int j = 0; j < nexts.size(); ++j) {
                    string next = nexts[j];
                    if (!visited[next]) {
                        visited[next] = visited[cur] + 1;
                        Queue.push(next);
                    }
                }

            }
        }
    }
    return -1;
}

int main() {
    string begin, end;
    cin >> begin >> end;
    string a, b;
    while (cin >> a >> b) {
        map_string mapString(a, b);
        map_strings.push_back(mapString);
    }


    int result = BFS(begin, end);
    if (result == -1) {
        cout << "NO ANSWER!" << endl;
    } else if (result - 1 > 10) {
        cout << "NO ANSWER!" << endl;
    } else
        cout << result - 1 << endl;

}
