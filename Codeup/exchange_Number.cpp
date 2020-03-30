#include <cstdio>

int main() {
    int a[10];
    while (~scanf("%d", &a[0])) {
        int max = 0, min = 0;
        for (int i = 1; i < 10; i++) {
            scanf("%d", &a[i]);
            if (a[max] < a[i])
                max = i;
            if (a[min] > a[i])
                min = i;
        }
        int temp = a[0];
        a[0] = a[min];
        a[min] = temp;
        if (max == 0)
            max = min;
        temp = a[9];
        a[9] = a[max];
        a[max] = temp;
        for (int i = 0; i < 10; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}