//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char s[3000];
    while (gets(s) != NULL) {
        char c;
        c = getchar();
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] != c) {
                cout << s[i];
            }
        }
        cout << endl;
        getchar();
    }
}

