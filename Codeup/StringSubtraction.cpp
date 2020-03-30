//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char str[10010];
    gets(str);
    int arr[2000] = {0};
    string s;
    getline(cin, s);

    for (int j = 0; j < s.length(); ++j) {
        s[j] = toupper(s[j]);
        arr[s[j]] = 1;
        s[j] = tolower(s[j]);
        arr[s[j]] = 1;
    }

    for (int i = 0; str[i] != '\0'; ++i) {
        if (arr[str[i]] == 0) {
            cout << str[i];
        }
    }
    cout << endl;

}