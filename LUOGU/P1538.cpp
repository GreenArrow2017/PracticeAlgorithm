#include <cstdio>
#include <cstring>
int k, l;
char c[256];
int main(){
    scanf ("%d\n%s", &k, c);
    l=std::strlen(c);
    //====== 数字顶部
    for (int i=0; i<l; i++){
        putchar (' ');
        //前面有一个空格
        for (int j=0; j<k; j++)
            putchar ("- -- -----"[c[i]-'0']);
        printf (l-1!=i?"  ":"\n");
        //如果最后一个数，回车，否则两个空格
    }
    //====== 数字上半
    for (int j=0; j<k; j++){
        for (int i=0; i<l; i++){
            putchar ("|   ||| ||"[c[i]-'0']);
            for (int jj=0; jj<k; jj++)
                putchar (' ');
            putchar ("|||||  |||"[c[i]-'0']);
            putchar (l-1!=i?' ':'\n');
        }
    }
    //====== 数字中间
    //只是修改了顶部的字串
    for (int i=0; i<l; i++){
        putchar (' ');
        for (int j=0; j<k; j++)
            putchar ("  ----- --"[c[i]-'0']);
        printf (l-1!=i?"  ":"\n");
    }
    //====== 数字下半
    //修改了上半的字串
    for (int j=0; j<k; j++){
        for (int i=0; i<l; i++){
            putchar ("| |   | | "[c[i]-'0']);
            for (int jj=0; jj<k; jj++)
                putchar (' ');
            putchar ("|| |||||||"[c[i]-'0']);
            putchar (l-1!=i?' ':'\n');
        }
    }
    //====== 数字底部，同中间
    for (int i=0; i<l; i++){
        putchar (' ');
        for (int j=0; j<k; j++)
            putchar ("- -- -- --"[c[i]-'0']);
        printf (l-1!=i?"  ":"\n");
    }
    return 0;
}