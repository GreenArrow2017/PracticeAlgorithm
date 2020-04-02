//
// Created by GreenArrow on 2020/4/2.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student {
    string id;
    int A;
    int rankA;
    int C;
    int rankC;
    int M;
    int rankM;
    int E;
    int rankE;
    int origin;

    student(string id, int C, int M, int E) {
        this->id = id;
        this->C = C;
        this->M = M;
        this->E = E;
        this->A = (C + M + E) / 3;
    }
};

int cmp(student A, student B) {
    return A.origin < B.origin;
}

int cmpA(student A, student B) {
    return A.A > B.A;
}

int cmpC(student A, student B) {
    return A.C > B.C;
}

int cmpM(student A, student B) {
    return A.M > B.M;
}

int cmpE(student A, student B) {
    return A.E > B.E;
}

void setRankA(vector<student> &students) {
    int rank = 1;
    if (students.size() == 0)
        return;
    students[0].rankA = rank;
    for (int i = 1; i < students.size(); ++i) {
        if (students[i].A == students[i - 1].A) {
            students[i].rankA = students[i - 1].rankA;
            rank++;
        } else {
            students[i].rankA = ++rank;
        }
    }
}

void setRankM(vector<student> &students) {
    int rank = 1;
    if (students.size() == 0)
        return;
    students[0].rankM = rank;
    for (int i = 1; i < students.size(); ++i) {
        if (students[i].M == students[i - 1].M) {
            students[i].rankM = students[i - 1].rankM;
            rank++;
        } else {
            students[i].rankM = ++rank;
        }
    }
}

void setRankC(vector<student> &students) {
    int rank = 1;
    if (students.size() == 0)
        return;
    students[0].rankC = rank;
    for (int i = 1; i < students.size(); ++i) {
        if (students[i].C == students[i - 1].C) {
            students[i].rankC = students[i - 1].rankC;
            rank++;
        } else {
            students[i].rankC = ++rank;
        }
    }
}

void setRankE(vector<student> &students) {
    int rank = 1;
    if (students.size() == 0)
        return;
    students[0].rankE = rank;
    for (int i = 1; i < students.size(); ++i) {
        if (students[i].E == students[i - 1].E) {
            students[i].rankE = students[i - 1].rankE;
            rank++;
        } else {
            students[i].rankE = ++rank;
        }
    }
}

int main() {
    vector<student> students;
    map<string, int> visited;
    int n, M;
    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        int c, m, e;
        string id;
        cin >> id >> c >> m >> e;
        student s(id, c, m, e);
        s.origin = i;
        students.push_back(s);
        visited[id] = i;
    }


    sort(students.begin(), students.end(), cmpA);
    setRankA(students);

    sort(students.begin(), students.end(), cmpC);
    setRankC(students);

    sort(students.begin(), students.end(), cmpM);
    setRankM(students);

    sort(students.begin(), students.end(), cmpE);
    setRankE(students);

    sort(students.begin(), students.end(), cmp);

    for (int j = 0; j < M; ++j) {
        string s;
        cin >> s;
        if (visited.count(s) <= 0) {
            cout << "N/A" << endl;
        } else {
            student stu = students[visited[s]];
            string method = "A";
            int rank = stu.rankA;
            if (stu.rankC < rank) {
                method = "C";
                rank = stu.rankC;
            }
            if (stu.rankM < rank) {
                method = "M";
                rank = stu.rankM;
            }

            if (stu.rankE < rank) {
                method = "E";
                rank = stu.rankE;
            }

            cout << rank << " " << method << endl;
        }
    }
}