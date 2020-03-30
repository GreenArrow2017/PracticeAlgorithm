//
// Created by GreenArrow on 2020/2/19.
//
#include <cstdio>

int chess[100][100] = {0};
int count_queen = 0;

bool check(int column, int index, int n) {

    //check column
    for (int i = index - 1; i >= 0; --i) {
        if (chess[i][column] == 1) {
            return false;
        }
    }

    for (int i = index - 1, j = column - 1; i >= 0 && j >= 0; --i, --j) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    for (int i = index - 1, j = column + 1; i >= 0 && j < n; --i, ++j) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    return true;

}

void findQueen(int index, int n) {

    if (index >= n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (chess[i][j] == 1) {
                    count_queen++;
                    printf("%d ", j + 1);
                }
            }
        }
        printf("\n");
        return;
    }

    for (int column = 0; column < n; ++column) {

        if (check(column, index, n)) {
            chess[index][column] = 1;
            findQueen(index + 1, n);
            chess[index][column] = 0;
        }

    }

}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {

        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                chess[i][j] = 0;
            }
        }

        count_queen = 0;

        findQueen(0, n);

        if (count_queen == 0) {
            printf("no solute!\n");
        }
    }
}
