//
// Created by GreenArrow on 2020/8/2.
//
#include <iostream>

using namespace std;

class Solution {
public:

    class number {

    public:
        string integer;
        string decimal;
        string loop;
        int Integer;
        int Decimal;


        void toString() {
            cout << integer << " " << decimal << " " << loop << endl;
        }

        number(string integer, string decimal, string loop) {
            this->integer = integer;
            this->decimal = decimal;
            this->loop = loop;
        }

        number() {
        }
    };

    bool isRationalEqual(string S, string T) {
        number *sNum = separate(S);
        number *tNum = separate(T);
        transform2eight(sNum);
        transform2eight(tNum);
//        sNum->toString();
//        tNum->toString();

        loopIs9OrNot(sNum);
        loopIs9OrNot(tNum);

        return (sNum->Integer == tNum->Integer && sNum->Decimal == tNum->Decimal);

    }

    void loopIs9OrNot(number *&s) {

        if (s->loop.length() == 0) {
            s->Integer = str2int(s->integer);
            s->Decimal = str2int(s->decimal);

            return;
        }

        for (int i = 0; i < s->loop.length(); i++) {
            if (s->loop[i] != '9') {

                s->Integer = str2int(s->integer);
                s->Decimal = str2int(s->decimal);

                return;
            }
        }
        s->loop = "";
        s->Decimal = plusOne(s->decimal);

        if (s->Decimal > 99999999) {
            s->Decimal = 0;
            s->Integer = plusOne(s->integer);
        } else {
            s->Integer = str2int(s->integer);
        }
    }

    int plusOne(string str) {
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            result = result * 10 + (str[i] - '0');
        }
        return result + 1;
    }

    int str2int(string str) {
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            result = result * 10 + (str[i] - '0');
        }
        return result;
    }

    void transform2eight(number *&s) {
        if (s->decimal.length() + s->loop.length() < 8) {
            int differ = 8 - s->decimal.length() - s->loop.length();
            s->decimal += s->loop;
            if (s->loop.length() == 0) {
                for (int i = 0; i < differ; i++) {
                    s->decimal += '0';
                }
                return;
            }
            for (int i = 0; i < differ / s->loop.length(); i++) {
                s->decimal += s->loop;
            }
            for (int i = 0; i < differ % s->loop.length(); i++) {
                s->decimal += s->loop[i];
            }
        } else{
            s->decimal += s->loop;
        }
    }

    number *separate(string s) {
        int i = 0;
        number *num = new number();
        while (i < s.length() && s[i] != '.') {
            num->integer += s[i];
            i++;
        }
        i++;
        while (i < s.length() && s[i] != '(') {
            num->decimal += s[i];
            i++;
        }
        i++;
        while (i < s.length() && s[i] != ')') {
            num->loop += s[i];
            i++;
        }

        return num;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        getline(cin, line);
        string T = stringToString(line);

        bool ret = Solution().isRationalEqual(S, T);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
