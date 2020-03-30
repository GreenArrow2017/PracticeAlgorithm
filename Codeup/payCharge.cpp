//
// Created by GreenArrow on 2020/2/16.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        double sum = 0;
        if (n == 0)
            return 0;
        if (n <= 4) {
            sum += 10;
        } else if (n <= 8) {
            sum += 10 + (n - 4) * 2;
        } else if (n > 8) {

            while (n >= 8) {
                sum += 18;
                n -= 8;
            }


            if (n <= 4) {
                sum += 2.4 * n;
            } else {
                sum += 10 + (n - 4) * 2;
            }



        }
        if (sum - (int) sum == 0) printf("%d\n", (int) sum);
        else printf("%.1lf\n", sum);
    }
}