//
// Created by GreenArrow on 2020/2/16.
//

#include <iostream>

using namespace std;

int main(){
    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    for (int j = 1; j < 10; ++j) {
        if(arr[j] != 0){
            cout << j;
            arr[j]--;
            break;
        }
    }

    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < arr[k]; ++i) {
            cout << k;
        }
    }
    cout << endl;
}