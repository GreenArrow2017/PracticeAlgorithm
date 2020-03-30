//
// Created by GreenArrow on 2020/2/8.
//

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    int index = 0;
    int prime = 2;
    int arr[M + N];
    int k = 0;
    while (index <= M - 1) {
        if (isPrime(prime)) {
            if (index >= N - 1)
                arr[k++] = prime;
            index++;
        }
        prime++;
    }


    int num = 0;

    for (int i = 0; i < k; i++) {
        cout << arr[i];
        num ++;
        if (i != k - 1 && num != 10) {
            cout << " ";
        }
        if(num == 10){
            cout << endl;
            num = 0;
        }

    }
}


