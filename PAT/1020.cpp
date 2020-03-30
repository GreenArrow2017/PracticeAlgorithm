//
// Created by GreenArrow on 2020/2/16.
//
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

class moomCake {
private:
    double num;
    double score;
    double onlyOne;
public:
    double getNum() const {
        return num;
    }

    void setNum(double num) {
        moomCake::num = num;
    }

    double getScore() const {
        return score;
    }

    void setScore(double score) {
        moomCake::score = score;
    }

    double getOnlyOne() const {
        return onlyOne;
    }

    void setOnlyOne(double onlyOne) {
        moomCake::onlyOne = onlyOne;
    }

    void print() {
        cout << "stock: " << num << " price: " << score << " OnlyOne: " << onlyOne << endl;
    }
};

int cmp(moomCake a, moomCake b) {
    return a.getOnlyOne() > b.getOnlyOne();
}

int main() {
    double sum;
    int n;
    cin >> n >> sum;
    cin.ignore();
    moomCake moonCake[n];
    for (int i = 0; i < n; ++i) {
        double num;
        cin >> num;
        moonCake[i].setNum(num);
    }
    cin.ignore();
    for (int j = 0; j < n; ++j) {
        double score;
        cin >> score;
        moonCake[j].setScore(score);
    }

    for (int k = 0; k < n; ++k) {
        moonCake[k].setOnlyOne(moonCake[k].getScore() / moonCake[k].getNum());
    }

    sort(moonCake, moonCake + n, cmp);

//    for (int l = 0; l < n; ++l) {
//        moonCake[l].print();
//    }


    double price = 0;

    for (int l = 0; l < n; ++l) {
        if (sum >= moonCake[l].getNum()) {
            sum -= moonCake[l].getNum();
            price += moonCake[l].getScore();
        } else {
            price += (moonCake[l].getOnlyOne() * sum);
            sum = 0;
        }

        if (sum == 0) {
            break;
        }
    }

    printf("%.2lf", price);
}
