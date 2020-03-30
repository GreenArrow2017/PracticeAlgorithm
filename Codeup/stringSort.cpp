//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
   char arr[250];
    while(gets(arr)){
        sort(arr, arr+strlen(arr));
        puts(arr);
    }
}