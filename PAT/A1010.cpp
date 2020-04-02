#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstdio>

using namespace std;

long long int toN(int a[], int n, int radix) {
    long long int decimal = 0;
    for (int i = 0; i < n; i++) {
        decimal += a[i] * pow(radix, n - i - 1);
    }
    //cout<<decimal<<endl;
    return decimal;
}

long long int toN2(int a[], int n, int radix, long long int &compare) {
    long long int decimal = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        temp = decimal;
        decimal += a[i] * pow(radix, n - i - 1);
        if (decimal > compare || temp > decimal)//溢出判断
            return compare + 1;
    }
    //cout<<decimal<<endl;
    return decimal;
}

void toArray(string str, int a[], int &maxValue) {
    maxValue = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            a[i] = str[i] - '0';
        else
            a[i] = str[i] - 'a' + 10;
        //cout<<a[i]<<" ";
        maxValue = max(a[i], maxValue);
    }
    maxValue++;
}

int main() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2)
        swap(n1, n2);
    int a[n1.length()];
    int b[n2.length()];
    int minRadix = 0;
    toArray(n1, a, minRadix);
    long long int decimal = toN(a, n1.length(), radix);
    toArray(n2, b, minRadix);
    //cout<<minRadix<<endl;
    int flag = -1;
    long long int high = decimal > minRadix ? decimal : minRadix;
    int low = minRadix;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long int temp = toN2(b, n2.length(), mid, decimal);
        // cout<<mid<<endl;
        if (temp < decimal)
            low = mid + 1;
        else if (temp == decimal) {
            flag = mid;
            high = mid - 1;
        } else {
            high = mid - 1;
        }
    }

    if (flag == -1)
        cout << "Impossible";
    else
        cout << flag;
    return 0;
}