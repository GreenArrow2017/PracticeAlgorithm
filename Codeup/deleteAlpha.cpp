#include<cstdio>
#include<cstring> //编译错误，往往是数组开的不够大

int compare(char a, char b) {
    if (a >= 'A' && a <= 'Z') {
        if (a == b) return 1;
        else return 0;
    } else {
        a = a - 'a' + 'A';
        if (a == b)return 1;
        else return 0;
    }
}                                     //注:将字符串中的In、IN、iN、in删除。
char DeleStr[1005];
char InStr[1005];

int main() {
    gets(DeleStr);
    int lenD = strlen(DeleStr);
    int i;
    for (i = 0; i < lenD; i++) {
        if (DeleStr[i] >= 'A' && DeleStr[i] <= 'Z')continue;
        else DeleStr[i] = DeleStr[i] - 'a' + 'A';
    }                          //将需删除的字符串一律变成大写；
    int lenI, j;
    while (gets(InStr) != NULL) {
        lenI = strlen(InStr);
        i = 0;
        j = 0;
        while (i < lenI && j < lenD) {
            if (compare(InStr[i], DeleStr[j])) {
                i++;
                j++;
                if (j == lenD)j = 0;          //当成功找到一组时，跳过，继续下一次查找
            } else {
                i = i - j + 1;
                if (InStr[i - 1] != ' ')printf("%c", InStr[i - 1]);  //打印指针前一项
                j = 0;
            }
        }
        if (i == lenI)printf("\n");
    }
    return 0;
}