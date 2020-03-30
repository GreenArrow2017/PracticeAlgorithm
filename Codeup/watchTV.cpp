//
// Created by GreenArrow on 2020/2/16.
//

#include <iostream>
#include <algorithm>

using namespace std;

class partion {
private:
    double begin;
    double end;
public:
    double getBegin() const {
        return begin;
    }

    void setBegin(double begin) {
        partion::begin = begin;
    }

    double getEnd() const {
        return end;
    }

    void setEnd(double end) {
        partion::end = end;
    }

    void print() {
        cout << "begin: " << begin << " end: " << end << endl;
    }
};

int cmp(partion a, partion b) {
    if (a.getEnd() != b.getEnd())
        return a.getEnd() < b.getEnd();
    return a.getBegin() > b.getBegin();
}

int main() {
    int n;
    while (cin >> n) {

        if (n == 0)
            return 0;

        partion part[n];

        for (int i = 0; i < n; ++i) {

            double begin, end;
            cin >> begin >> end;
            cin.ignore();

            part[i].setBegin(begin);
            part[i].setEnd(end);

        }

        sort(part, part + n, cmp);


//        for (int k = 0; k < n; ++k) {
//            part[k].print();
//        }

        int num = 1;
        double pre = part[0].getEnd();
        for (int j = 1; j < n; ++j) {
            if (part[j].getBegin() >= pre) {
                pre = part[j].getEnd();
                num++;
            }
        }

        cout << num << endl;
    }
}