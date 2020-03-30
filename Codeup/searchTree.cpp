//
// Created by GreenArrow on 2020/2/23.
//

#include <iostream>

using namespace std;

int getNumber(int *depths, int *trees, int depth, int n) {

    int sum = 0;

    for (int i = 1; i <= (n / 2); ++i) {
        int left = 2 * i;
        if (left <= n) {
            depths[left] = depths[i] + 1;
        }
        int right = 2 * i + 1;
        if (right <= n) {
            depths[right] = depths[i] + 1;
        }
    }

    for (int j = 1; j <= n; ++j) {

        if (depths[j] == depth) {
            cout << trees[j] << " ";
            sum++;
        }

    }

    if (sum == 0) {
        cout << "EMPTY";
    }

    cout << endl;

    return sum;
}

int main() {
    int n;
    while (cin >> n) {
        cin.ignore();
        if(n == 0){
            return 0;
        }
        int depths[n + 1];
        int trees[n + 1];
        for (int j = 1; j <= n; ++j) {
            depths[j] = 0;
            cin >> trees[j];
        }
        int depth;
        depths[1] = 1;
        cin >> depth;

        getNumber(depths, trees, depth, n);
    }
}

