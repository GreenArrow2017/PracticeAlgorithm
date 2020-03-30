//
// Created by GreenArrow on 2020/3/2.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int max_index = 0;
map<string, int> count_string;

bool isContained(string s, string result) {
    int length = (s.length() > result.length() ? result.length() : s.length());
    for (int i = 0; i < length; ++i) {

    }
}

void inject(string result, vector<string> strings) {
    for (int i = 0; i < strings.size(); ++i) {
        string s = strings[i];
        if (count_string[s] == 2 || isContained(s, result)) {
            continue;
        }

    }
}

int main() {
    int n;
    vector<string> strings;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strings.push_back(s);
        count_string[s] = 0;
    }

    char head;
    cin >> head;

    for (int j = 0; j < strings.size(); ++j) {
        if (head == strings[j][0]) {
            string result = "";
            result = strings[j];
            count_string[strings[j]]++;
            max_index = ((max_index > result.length()) ? max_index : result.length());
        }
    }
}