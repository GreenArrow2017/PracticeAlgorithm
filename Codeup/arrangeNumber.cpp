//
// Created by GreenArrow on 2020/2/18.
//

#include <iostream>

using namespace std;

int n;
int p[10010];
bool flag[10010] = {false};

void generate(int index) {

    if (index == n + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << p[i];
            if (i != n) {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!flag[i]) {
            p[index] = i;
            flag[i] = true;
            generate(index + 1);
            flag[i] = false;
        }
    }
}

int main() {

    while (cin >> n) {

        generate(1);

    }

}