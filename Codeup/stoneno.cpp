//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int win(string a, string b) {
    if (a == "C" && b == "C") {
        return 0;
    } else if (a == "C" && b == "J") {
        return 1;
    } else if (a == "C" && b == "B") {
        return 2;
    } else if (a == "J" && b == "C") {
        return 2;
    } else if (a == "J" && b == "J") {
        return 0;
    } else if (a == "J" && b == "B") {
        return 1;
    } else if (a == "B" && b == "C") {
        return 1;
    } else if (a == "B" && b == "J") {
        return 2;
    } else if (a == "B" && b == "B") {
        return 0;
    }
}

int main() {
    int n;
    while (cin >> n) {
        int first = 0;
        int second = 0;
        int fair = 0;
        int BCJ_first[3] = {0};
        int BCJ_second[3] = {0};
        for (int i = 0; i < n; ++i) {
            string A, B;
            cin >> A >> B;
            int result = win(A, B);
            if (result == 1) {
                first++;
                if (A == "B") {
                    BCJ_first[0]++;
                } else if (A == "C") {
                    BCJ_first[1]++;
                } else if (A == "J") {
                    BCJ_first[2]++;
                }
            } else if (result == 2) {
                second++;
                if (B == "B") {
                    BCJ_second[0]++;
                } else if (B == "C") {
                    BCJ_second[1]++;
                } else if (B == "J") {
                    BCJ_second[2]++;
                }
            } else
                fair++;
        }

        cout << first << " " << fair << " " << n - first - fair << endl;
        cout << second << " " << fair << " " << n - second - fair << endl;
        int minA = 0, minB = 0;
        for (int i = 1; i < 3; i++) {

            if (BCJ_first[minA] < BCJ_first[i]) {
                minA = i;
            }
            if (BCJ_second[minB] < BCJ_second[i]) {
                minB = i;
            }

        }
        if(minA == 0){
            cout << "B"<<" ";
        } else if(minA == 1){
            cout << "C" << " ";
        }else if(minA == 2){
            cout << "J" << " ";
        }

        if(minB == 0){
            cout << "B";
        } else if(minB == 1){
            cout << "C";
        }else if(minB == 2){
            cout << "J";
        }

    }
}