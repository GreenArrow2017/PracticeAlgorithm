//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

class rat {
private:
    int weight;
public:
    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        rat::weight = weight;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        rat::name = name;
    }

private:
    string name;

};

bool cmp(rat a, rat b) {
    return a.getWeight() > b.getWeight();
}

int main() {
    int n;
    while (cin >> n) {
        rat rat[n];
        for (int i = 0; i < n; ++i) {
            int weight;
            string name;
            cin >> weight >> name;
            rat[i].setWeight(weight);
            rat[i].setName(name);
        }
        sort(rat, rat + n, cmp);
        for (int j = 0; j < n; ++j) {
            cout << rat[j].getName() << endl;
        }
    }
}