//
// Created by GreenArrow on 2020/2/8.
//

#include <iostream>

using namespace std;


string getTime(char s) {
    string result = "";
    if (s >= '0' && s <= '9') {
        result.append("0");
        result += s;
        return result;
    } else {
        if (s == 'A')
            return "10";
        else if (s == 'B')
            return "11";
        else if (s == 'C')
            return "12";
        else if (s == 'D')
            return "13";
        else if (s == 'E')
            return "14";
        else if (s == 'F')
            return "15";
        else if (s == 'G')
            return "16";
        else if (s == 'H')
            return "17";
        else if (s == 'I')
            return "18";
        else if (s == 'J')
            return "19";
        else if (s == 'K')
            return "20";
        else if (s == 'L')
            return "21";
        else if (s == 'M')
            return "22";
        else if (s == 'N')
            return "23";
    }


}

string getDay(char s) {
    if (s == 'A')
        return "MON";
    else if (s == 'B')
        return "TUE";
    else if (s == 'C')
        return "WED";
    else if (s == 'D')
        return "THU";
    else if (s == 'E')
        return "FRI";
    else if (s == 'F')
        return "SAT";
    else if (s == 'G')
        return "SUN";
}

int main() {
    string D1, D2;
    string T1, T2;
    cin >> D1 >> D2 >> T1 >> T2;
    string DAY = "";
    string TIME = "";
    int length = (D1.length() > D2.length()) ? D2.length() : D1.length();
    for (int i = 0; i < length; ++i) {
        if (D1[i] == D2[i] && D1[i] >= 'A' && D1[i] <= 'G' && DAY == "") {
            DAY = getDay(D1[i]);
        }
        else if (D1[i] == D2[i] && ((D1[i] >= 'A' && D1[i] <= 'N') || (D1[i] >= '0' && D1[i] <= '9')) && DAY != "") {
            TIME = getTime(D1[i]);
            break;
        }
    }
    int len = (T1.length() > T2.length()) ? T2.length() : T1.length();


    int index = 0;
    for (int j = 0; j < len; ++j) {
        if ((T1[j] == T2[j]) && ((T1[j] >= 'a' && T1[j] <= 'z') || (T1[j] >= 'A' && T1[j] <= 'Z'))) {
            index = j;
            break;
        }
    }

    cout << DAY << " " << TIME << ":" << ((index > 9) ? "" : "0") << index;
}
