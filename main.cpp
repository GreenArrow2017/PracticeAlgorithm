#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> X = {1, 2, 3, 4};
    vector<int> Y = {1, 2, 3, 4};
    vector<int> Z = {1, 2, 3, 4};
    vector<int> W = {1, 2, 3, 4, 5};

    vector<bool> X_flag = {false, false, false, false};
    vector<bool> Y_flag = {false, false, false, false};
    vector<bool> Z_flag = {false, false, false, false};
    vector<bool> W_flag = {false, false, false, false, false};

    for (int i = 0; i < X.size(); i++) {
        for(int j = 0;j < Y.size();j++){
            for(int k = 0;k < Z.size();k++){
                for(int l = 0;l < W.size();l++){
                    if(X[i] == Y[j] + Z[k] && W[l])
                }
            }
        }
    }
}