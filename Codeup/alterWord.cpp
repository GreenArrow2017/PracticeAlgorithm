//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>

using namespace std;

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int seperate(string s, string *arr) {
    int index = 0;
    string word = "";
    for (int i = 0; i < s.length(); ++i) {
        if (isAlpha(s[i])) {
            word += s[i];
        } else if (s[i] == ' ') {
            arr[index++] = word;
            word = "";
        }
    }
    arr[index++] = word;

    return index;
}


int main() {
    string s;
    while (getline(cin, s)) {
        string original;
        string alter;
        cin >> original >> alter;
        cin.ignore();
        string arr[200];
        int n = seperate(s, arr);
        for (int i = 0; i < n; ++i) {
            if (arr[i] == original) {
                arr[i] = alter;
            }
        }
        for (int j = 0; j < n; ++j) {
            cout << arr[j];
            if (j != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

}
