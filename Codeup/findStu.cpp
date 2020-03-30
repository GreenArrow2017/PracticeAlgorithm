//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if(n == 0){
            return 0;
        }
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int num;
        cin >> num;
        int index = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == num) {
                index++;
            }
        }
        cout << index << endl;
    }
}