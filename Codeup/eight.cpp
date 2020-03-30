//
// Created by GreenArrow on 2020/2/11.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int arr[1000];
        int index = 0;
        do{
            arr[index++] = n%8;
            n /= 8;
        }while (n > 0);
        for (int i = index-1; i >= 0 ; --i) {
            cout << arr[i];
        }
        cout << endl;
    }

}