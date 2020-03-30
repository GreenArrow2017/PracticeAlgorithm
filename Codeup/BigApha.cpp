//
// Created by GreenArrow on 2020/2/11.
//

#include <iostream>

using namespace std;

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isSep(char c) {
    if (isAlpha(c) == false && c != '-') {
        return true;
    } else
        return false;
}

int main() {
    string s;
    while (cin >> s) {
        bool flag = true;
        for (int i = 0; i < s.length(); ++i) {
            if (isAlpha(s[i]) && flag) {
                s[i] = toupper(s[i]);
                flag = false;
            } else if (s[i]==' '||s[i]=='\t'||s[i]=='\r') {
                flag == true;

            }
            cout << s[i];
        }
        cout << " ";
    }
}
//if so, you already have a google account. you can sign in on the right-sdhjq.