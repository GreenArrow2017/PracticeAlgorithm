//
// Created by GreenArrow on 2020/2/5.
//

#include <iostream>

using namespace std;


int Alphe2Number(string s) {
    for (int i = 0, j = s.length()-1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    int index = 1;
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        num += ((s[i] - '0') * index);
        index *= 10;
    }
    return num;
}

int main() {

    int n;
    cin >> n;
    cin.ignore();
    int min = 0;
    string min_name = "";
    string min_number = "";
    int max = 0;
    string max_name = "";
    string max_number = "";
    for (int i = 0; i < n; i++) {
        string info[3];
        string s;
        getline(cin, s);
        int index = 0;
        int k = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ' ') {
                info[k++] = s.substr(index, j - index);
                index = j + 1;
            }
        }
        info[k] = s.substr(index, s.length() - index + 1);
        //cout << "name:" << info[0] << " number:" << info[1] << " score:" << Alphe2Number(info[2]) << endl;

        if (i == 0) {
            min_name = info[0];
            min_number = info[1];
            min = Alphe2Number(info[2]);
            max_name = info[0];
            max_number = info[1];
            max = Alphe2Number(info[2]);
        } else{
            if (min > Alphe2Number(info[2])){
                min_name = info[0];
                min_number = info[1];
                min = Alphe2Number(info[2]);
            }
            if (max < Alphe2Number(info[2])){
                max_name = info[0];
                max_number = info[1];
                max = Alphe2Number(info[2]);
            }
        }
    }

    cout << max_name << " " << max_number << endl << min_name << " " << min_number;

    return 0;
}

