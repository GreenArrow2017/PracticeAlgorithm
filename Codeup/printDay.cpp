//
// Created by GreenArrow on 2020/2/11.
//

#include<cstdio>
bool leap(int year){
    return(year%4 == 0 && year%100 != 0 || year%400 == 0);
}
int main(){
    int month[13][2]={{0,0}, {31,31}, {28,29}, {31,31}, {30,30}, {31,31}, {30,30}, {31,31}, {31,31}, {30,30}, {31,31}, {30,30}, {31,31}};
    int y, m=1, d=0, n;
    while(scanf("%d%d", &y, &n)!=EOF){
        while(n>0){
            d++;
            if(d==month[m][leap(y)]+1){
                m++;
                d=1;
            }
            if(m==13){
                y++;
                m=1;
            }
            n--;
        }
        printf("%04d-%02d-%02d\n", y, m, d);
        m=1, d=0;
    }
    return 0;
}