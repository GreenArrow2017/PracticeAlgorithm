//
// Created by GreenArrow on 2020/3/9.
//
#include <iostream>
#include <vector>

using namespace std;

typedef struct user {
    string id;
    string account;
};

string change(string account) {
    bool flag = false;
    for (int i = 0; i < account.length(); ++i) {
        if (account[i] == '1') {
            account[i] = '@';
            flag = true;
        } else if (account[i] == '0') {
            account[i] = '%';
            flag = true;

        } else if (account[i] == 'l') {
            account[i] = 'L';
            flag = true;

        } else if (account[i] == 'O') {
            account[i] = 'o';
            flag = true;

        }
    }
    if (flag) {
        return account;
    } else
        return "";
}

int main() {
    int n;
    cin >> n;
    user users[n];
    vector<user> users_vector;
    for (int i = 0; i < n; ++i) {
        user u;
        cin >> u.id >> u.account;
        users[i] = u;
        string result = change(u.account);
        if (!result.empty()) {
            u.account = result;
            users_vector.push_back(u);
        }
    }


    if (users_vector.empty()) {
        if (n == 1)
            cout << "There is " << n << " account and no account is modified" << endl;
        else if (n >= 2)
            cout << "There are " << n << " accounts and no account is modified" << endl;
        return 0;
    }

    cout << users_vector.size() << endl;
    for (int j = 0; j < users_vector.size(); ++j) {
        cout << users_vector[j].id << " " << users_vector[j].account << endl;
    }

}