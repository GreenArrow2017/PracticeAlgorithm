//
// Created by GreenArrow on 2020/2/8.
//

#include <cstdio>

int main() {
    int L, M;
    scanf("%d %d", &L, &M);

    int result[100010];
    int index = 0;

    while (L != 0 && M != 0) {
        int arr[L + 1];
        for (int i = 0; i <= L; i++) {
            arr[i] = 1;
        }
        int left, right;
        for (int j = 0; j < M; ++j) {
            scanf("%d %d", &left, &right);
            for (int i = left; i <= right; i++) {
                arr[i] = 0;
            }
        }
        int count = 0;
        for (int k = 0; k <= L; ++k) {
            if (arr[k] != 0) {
                count++;
            }
        }
        result[index++] = count;
        scanf("%d %d", &L, &M);

    }

    for (int l = 0; l < index; ++l) {
        printf("%d\n", result[l]);
    }

}