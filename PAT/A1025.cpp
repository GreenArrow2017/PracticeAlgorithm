//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class student {
private:
    string id;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
public:
    string getId() {
        return id;
    }

    void setId(string id) {
        student::id = id;
    }

    int getScore() {
        return score;
    }

    void setScore(int score) {
        student::score = score;
    }

    int getFinalRank() {
        return final_rank;
    }

    void setFinalRank(int finalRank) {
        final_rank = finalRank;
    }

    int getLocationNumber() {
        return location_number;
    }

    void setLocationNumber(int locationNumber) {
        location_number = locationNumber;
    }

    int getLocalRank() {
        return local_rank;
    }

    void setLocalRank(int localRank) {
        local_rank = localRank;
    }

    void print() {
        cout << id << " " << score << " " << final_rank << " " << location_number << " " << local_rank << endl;
    }

    void printRank() {
        cout << id << " " << final_rank << " " << location_number << " " << local_rank << endl;
    }
};

bool cmp(student a, student b) {
    if (a.getScore() != b.getScore())
        return a.getScore() > b.getScore();
    else
        return a.getId() < b.getId();
}

int main() {
    int n;
    cin >> n;
    student stu[30010];
    int index = 0;
    for (int i = 0; i < n; ++i) {

        int m1;
        cin >> m1;

        for (int j = 0; j < m1; ++j) {
            string id;
            cin >> id;
            int score;
            cin >> score;
            stu[index].setId(id);
            stu[index].setScore(score);
            stu[index].setLocationNumber(i + 1);
            index++;
        }

        sort(stu + index - m1, stu + index, cmp);


        int rank = 1;
        for (int k = index - m1; k < index; ++k) {
            if (k == index - m1) {
                stu[index - m1].setLocalRank(rank++);
                continue;
            } else if (stu[k].getScore() == stu[k - 1].getScore()) {
                stu[k].setLocalRank(stu[k - 1].getLocalRank());
                rank++;
            } else
                stu[k].setLocalRank(rank++);
        }

//        for (int l = index - m1; l < index; ++l) {
//            stu[l].print();
//        }
    }

    sort(stu, stu + index, cmp);
    int rank = 1;
    stu[0].setFinalRank(rank++);
    for (int l = 1; l < index; ++l) {
        if (stu[l].getScore() == stu[l - 1].getScore()) {
            stu[l].setFinalRank(stu[l - 1].getFinalRank());
            rank++;
        } else
            stu[l].setFinalRank(rank++);
    }

    cout << index << endl;

    for (int m = 0; m < index; ++m) {
        stu[m].printRank();
    }
}
