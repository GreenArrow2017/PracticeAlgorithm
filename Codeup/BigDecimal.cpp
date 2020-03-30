#include<stdio.h>
#include<string.h>
const int maxn = 40;

char mod(char str[])       //模拟辗转相除法求出每一个余数 
{
    int div,temp=0;
    for(int i=0;i<strlen(str);i++)
    {
        div=((str[i]-'0')+temp*10)/2;   //求出每一轮的被除数
        temp=((str[i]-'0')+temp*10)%2;
        str[i]=div+'0';                     //将每一位对应的商放回数组对应的位上,全为0时表示已经结束
    }
    return temp+'0';
}

int isEmpty(char str[])            //  判断所给数组是否已经全部除完 
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]!='0')
        {
            return 0;
        }
    }
    if(i==strlen(str))
        return 1;
}

int main()
{
    int i=0;
    char str[200],result[200]="";
    while(scanf("%s",str)!=EOF)
    {
        i=0;
        do
        {
            result[i++]=mod(str);
        }while(!isEmpty(str));
        result[i]='\0' ;   //注意要把最后一个字符设为'\0'表示这个字符串已经结束,不然可能会连续输出上一次位清空的数据
        for(i=strlen(result)-1;i>=0;i--)
            printf("%c",result[i]);
        printf("\n");
    }
    return 0;
}