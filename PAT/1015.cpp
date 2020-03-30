//
// Created by GreenArrow on 2020/2/8.
//

/**
 *  德才不低于80 > 才分不到德分到80 > 德才低于80，德分不低于才 > 到L线
 * @return
 */

#include <iostream>
#include <algorithm>

using namespace std;


class student {
private:
    long number;
    int virtue;
    int talent;
    bool visited = false;
public:

    bool isVisited() {
        return visited;
    }

    void setVisit(bool flag) {
        this->visited = flag;
    }


    long getNumber() {
        return number;
    }

    int getVirtue() {
        return virtue;
    }

    int getTalent() {
        return talent;
    }

    void setNumber(long num) {
        this->number = num;
    }

    void setVirtue(int vir) {
        this->virtue = vir;
    }

    void setTalent(int tal) {
        this->talent = tal;
    }

    void toString() {
        cout << this->number << " " << this->virtue << " " << this->talent << endl;
    }
};

bool getOut(student stu, int deadline) {
    if (stu.getTalent() < deadline && stu.getVirtue() < deadline) {
        stu.setVisit(true);
        return true;
    }
    return false;
}

bool isFirst(student stu, int heightline) {
    if (stu.isVisited())
        return false;
    if (stu.getTalent() >= heightline && stu.getVirtue() >= heightline) {
        stu.setVisit(true);
        return true;
    }
    return false;
}

bool isSecond(student stu, int heightline, int deadline) {
    if (stu.isVisited())
        return false;
    if (stu.getTalent() >= deadline && stu.getVirtue() >= deadline && stu.getTalent() < heightline &&
        stu.getVirtue() >= heightline) {
        stu.setVisit(true);
        return true;
    }
    return false;
}

bool isThird(student stu, int heightline, int deadline) {
    if (stu.isVisited())
        return false;
    if (stu.getTalent() >= deadline && stu.getVirtue() >= deadline && stu.getVirtue() >= stu.getTalent()) {
        stu.setVisit(true);
        return true;
    }
    return false;
}

bool isFourth(student stu, int heightline, int deadline) {
    if (stu.isVisited())
        return false;
    if (stu.getTalent() >= deadline && stu.getVirtue() >= deadline && stu.getVirtue() < stu.getTalent()) {
        stu.setVisit(true);
        return true;
    }
    return false;
}

bool cmp(student a, student b) {
    if ((a.getVirtue() + a.getTalent()) != (b.getVirtue() + b.getTalent()))
        return (a.getVirtue() + a.getTalent()) > (b.getVirtue() + b.getTalent());
    else {
        if (a.getVirtue() != b.getVirtue())
            return a.getVirtue() > b.getVirtue();
        else if (a.getVirtue() == b.getVirtue()) {
            return a.getNumber() < b.getNumber();
        }
    }
}

int main() {

    int num, deadline, hightline;
    cin >> num >> deadline >> hightline;
    student stu[num];
    cin.ignore();
    for (int i = 0; i < num; ++i) {
        long number;
        int virtue;
        int talent;
        cin >> number >> virtue >> talent;
        stu[i].setNumber(number);
        stu[i].setVirtue(virtue);
        stu[i].setTalent(talent);
    }

    student firstLeg[num];
    int first = 0;

    student secondLeg[num];
    int second = 0;

    student thirdLeg[num];
    int third = 0;

    student fourthLeg[num];
    int fourth = 0;

    for (int j = 0; j < num; ++j) {
        if (getOut(stu[j], deadline)) {
            continue;
        } else if (isFirst(stu[j], hightline)) {
            firstLeg[first++] = stu[j];
        } else if (isSecond(stu[j], hightline, deadline)) {
            secondLeg[second++] = stu[j];
        } else if (isThird(stu[j], hightline, deadline)) {
            thirdLeg[third++] = stu[j];
        } else if (isFourth(stu[j], hightline, deadline)) {
            fourthLeg[fourth++] = stu[j];
        }
    }

    sort(firstLeg, firstLeg + first, cmp);
    sort(secondLeg, secondLeg + second, cmp);
    sort(thirdLeg, thirdLeg + third, cmp);
    sort(fourthLeg, fourthLeg + fourth, cmp);

    cout << first + second + third + fourth << endl;

    for (int k = 0; k < first; ++k) {
        cout << firstLeg[k].getNumber() << " " << firstLeg[k].getVirtue() << " " << firstLeg[k].getTalent() << endl;
    }
    for (int k = 0; k < second; ++k) {
        cout << secondLeg[k].getNumber() << " " << secondLeg[k].getVirtue() << " " << secondLeg[k].getTalent() << endl;
    }
    for (int k = 0; k < third; ++k) {
        cout << thirdLeg[k].getNumber() << " " << thirdLeg[k].getVirtue() << " " << thirdLeg[k].getTalent() << endl;
    }
    for (int k = 0; k < fourth; ++k) {
        cout << fourthLeg[k].getNumber() << " " << fourthLeg[k].getVirtue() << " " << fourthLeg[k].getTalent() << endl;
    }
}
