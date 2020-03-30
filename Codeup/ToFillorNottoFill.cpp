#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

#define eps 1e-7
using namespace std;
struct Station {
    double p;
    int l;
};

int cmp(Station a, Station b) {
    return a.l < b.l;
}

int main() {
    double maxOil, Destination, Distance_perOil;
    Station sta[501];
    int num_gasStation;
    while (scanf("%lf %lf %lf %d", &maxOil, &Destination, &Distance_perOil, &num_gasStation) != EOF) {
        //数据整理
        for (int i = 0; i < num_gasStation; i++) {
            scanf("%lf %d", &sta[i].p, &sta[i].l);
        }
        sort(sta, sta + num_gasStation, cmp);
        sta[num_gasStation].l = Destination;
        sta[num_gasStation].p = 0;
        //计算最小代价
        double sum = 0, cur_remainOil = 0;
        int now = 0, unreachable = 0;
        double Distance_fullOil = maxOil * Distance_perOil;
        while (now < num_gasStation) {  //判断是否到达终点
            double expect_remainOil;
            if (fabs(sta[0].l) > eps) {
                printf("The maximum travel distance = 0.00\n");
                unreachable = 1;
                break;
            }
            //相邻油站 是否 跨度太长
            if ((sta[now + 1].l - sta[now].l) > Distance_fullOil) {
                printf("The maximum travel distance = %.2f\n", sta[now].l + Distance_fullOil);
                unreachable = 1;
                break;
            }
            //寻找 油价最便宜的油站
            int min = now;
            for (int i = now + 1; ((sta[i].l - sta[now].l) <= Distance_fullOil) && (i <= num_gasStation); i++) {
                if (sta[i].p < sta[now].p) {
                    min = i;
                    break;
                }
            }
            expect_remainOil = (sta[min].l - sta[now].l) / Distance_perOil;
            // 找不到，那么加满油
            if (min == now) { expect_remainOil = maxOil; }
            //判断加多少油
            double add_Oil = 0;
            if (cur_remainOil < expect_remainOil) { add_Oil = expect_remainOil - cur_remainOil; }
            //计算油钱
            sum += add_Oil * sta[now].p;
            //printf("expect_remainOil = %.2f, cur_remainOil = %.2f, add_Oil= %.2f, sum = %.2f", expect_remainOil, cur_remainOil, add_Oil, sum);
            //更新当前剩余油量
            cur_remainOil = cur_remainOil + add_Oil - (sta[now + 1].l - sta[now].l) / Distance_perOil;
            // printf("%.2f\n", cur_remainOil);
            now++;
        }
        //输出总油费
        if (unreachable == 0) printf("%.2f\n", sum);
    }
    return 0;
}