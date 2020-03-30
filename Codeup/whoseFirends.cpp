//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        int books[m];
        int boys[n];
        for (int i = 0; i < m; ++i) {
            books[i] = 0;
        }
        for (int j = 0; j < n; ++j) {
            int s;
            cin >> s;
            boys[j] = s;
            books[s-1] ++;
        }

        for (int k = 0; k < n; ++k) {
            if(books[boys[k]-1] > 1){
                cout << books[boys[k]-1]-1 << endl;
            } else{
                cout << "BeiJu" << endl;
            }
        }
    }
}

