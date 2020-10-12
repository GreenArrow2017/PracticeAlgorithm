//
// Created by GreenArrow on 2020/10/12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        if (kthGrammar(N - 1, (K + 1) / 2)) {
            return K % 2;
        } else
            return 1 - K % 2;
    }
};
