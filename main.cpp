#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        if(A.length() == 0 || B.length() == 0){
            return false;
        }
        for (int i = 0; i < A.length() - 1; i++) {
            for (int j = i + 1; j < A.length(); j++) {
                char a = A[i];
                A[i] = A[j];
                A[j] = a;
                if (A == B) {
                    return true;
                }
                a = A[i];
                A[i] = A[j];
                A[j] = a;
            }
        }
        return false;
    }
};

int main() {


}