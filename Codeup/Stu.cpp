//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

class stu {
public:
    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        stu::number = number;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        stu::name = name;
    }

    string getSex() const {
        return sex;
    }

    void setSex(string sex) {
        stu::sex = sex;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        stu::age = age;
    }

private:
    int number;
    string name;
    string sex;
    int age;


};

int main() {

    int n;
    while (cin >> n) {
        for (int k = 0; k < n; k++) {


            int num = 0;
            cin >> num;
            stu student[num];
            for (int i = 0; i < num; ++i) {
                int num;
                string name;
                string sex;
                int age;
                cin >> num >> name >> sex >> age;
                student[i].setNumber(num);
                student[i].setName(name);
                student[i].setSex(sex);
                student[i].setAge(age);
            }
            int x;
            cin >> x;
            for (int j = 0; j < num; ++j) {
                if (student[j].getNumber() == x) {
                    cout << student[j].getNumber() << " " << student[j].getName() << " " << student[j].getSex() << " "
                         << student[j].getAge() << endl;
                }
            }


        }
    }

}