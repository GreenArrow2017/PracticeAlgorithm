#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
struct student {
    char num[10];
    char name[10];
    int score;
} stu[100010];

bool cmp1(student a, student b) {
    return strcmp(a.num, b.num) < 0;
}

bool cmp2(student a, student b) {
    if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
    else return strcmp(a.num, b.num) < 0;
}

bool cmp3(student a, student b) {
    if (a.score != b.score) return a.score < b.score;
    else return strcmp(a.num, b.num) < 0;
}

int main() {
    int m, n, count = 0;
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m == 0) break;
        int i;
        for (i = 0; i < m; i++) {
            scanf("%s %s %d", &stu[i].num, &stu[i].name, &stu[i].score);
        }
        switch (n) {
            case 1:
                sort(stu, stu + m, cmp1);
                break;
            case 2:
                sort(stu, stu + m, cmp2);
                break;
            case 3:
                sort(stu, stu + m, cmp3);
                break;
        }
        printf("Case %d:\n", ++count);
        for (i = 0; i < m; i++) {
            printf("%s %s %d\n", stu[i].num, stu[i].name, stu[i].score);
        }
    }
    return 0;
}