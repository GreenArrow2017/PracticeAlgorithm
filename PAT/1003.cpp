//
// Created by GreenArrow on 2020/2/5.
//

#include <iostream>

using namespace std;
int num = 0;
string success[50];

bool notPAT(char c) {
    return (c != 'P' && c != 'A' && c != 'T');
}

int calculateA(string s) {
    int num = 0;
    for (char c : s) {
        if (c == 'A') {
            num++;
        }
    }
    return num;

}

int calculateP(string s) {
    int num = 0;
    for (char c : s) {
        if (c == 'P') {
            num++;
        }
    }
    return num;
}

int calculateT(string s) {
    int num = 0;
    for (char c : s) {
        if (c == 'T') {
            num++;
        }
    }
    return num;
}


bool OnlyPAT(const string &s) {
    for (char c : s) {
        if (notPAT(c)) {
            return false;
        }
    }
    if (calculateP(s) >= 2 || calculateT(s) >= 2) {
        return false;
    }
    return true;
}


bool OnlyA(string s) {
    for (char c : s) {
        if (c != 'A') {
            return false;
        }
    }
    return true;
}

bool isPAT(string s) {
    return s == "PAT";
}

void getSeperate(string s, string *result) {
    string x1 = "";
    string PAT = "";
    string x2 = "";
    //分割
    int P = 0, T = 0;
    bool flagP = false;
    bool flagT = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'P' && !flagP) {
            P = i;
            flagP = true;
        } else if (s[i] == 'T' && !flagT) {
            T = i;
            flagT = true;
        }
    }
    x1 = s.substr(0, P);
    PAT = s.substr(P, T - P + 1);
    x2 = s.substr(T + 1, s.length() - T);
    result[0] = x1;
    result[1] = PAT;
    result[2] = x2;
}

bool isLegal(string s) {
    if (!OnlyPAT(s)) {
        return 0;
    }
    string sep[3];
    getSeperate(s, sep);
    string x1 = sep[0];
    string PAT = sep[1];
    string x2 = sep[2];

    if ((calculateA(x1) * calculateA(PAT) == calculateA(x2)) && (calculateA(PAT) > 0)) {
        return true;
    }

    if (!(OnlyA(x1) && OnlyA(x2) && isPAT(PAT))) {
        if (num <= 0) {
            return false;
        }
        for (int i = 0; i < num; i++) {
            string su[3];
            getSeperate(success[i], su);
            if ((calculateA(PAT) > 0) && (x1 == su[0]) &&
                (calculateA(x1) * calculateA(PAT) == calculateA(x2))) {
                return true;
            }
        }
        return false;
    }
    return true;
}

void trim(string &s) {

    if (!s.empty()) {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

}

string change(int n) {
    return n == 1 ? "YES" : "NO";
}

int main() {
    string s[50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        trim(c);
        s[i] = c;
    }

    bool result[n];

    for (int j = 0; j < n; ++j) {
        result[j] = isLegal(s[j]);
        if (result[j]) {
            success[num++] = s[j];
        }
        cout << change(result[j]) << endl;
    }

    return 0;
}

