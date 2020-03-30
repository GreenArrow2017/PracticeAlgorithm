//
// Created by GreenArrow on 2020/3/16.
//
#include <iostream>
#include <climits>
#include <algorithm>
#include <sstream>

#define MAX 202
using namespace std;

/**
 * TS simple cycle 1
 * Not a TS cycle  2
 * TS cycle        3
 */
int chess[MAX][MAX];
int visited[MAX];

int getClassification(int vertex_n, int n, int *array, int &classification) {
    int pre = array[0];
    int sum = 0;
    int result = 0;
    for (int i = 1; i < n; ++i) {
        if (chess[pre][array[i]] != INT_MAX) {
            sum += chess[pre][array[i]];
            pre = array[i];
        } else {
            result = INT_MAX;
            classification = 2;
            return result;
        }
    }


    if (array[0] != array[n - 1]) {
        classification = 2;
        result = sum;
        return result;
    }

    bool flag2 = false;
    for (int j = 1; j <= vertex_n; ++j) {
        if (visited[j] == 0) {
            classification = 2;
            result = sum;
            return result;
        }

        if (visited[j] >= 2) {
            if (j == array[0] && visited[j] > 2) {
                flag2 = true;
            }

            if (j != array[0] && visited[j] > 1) {
                flag2 = true;
            }
        }

    }

    if (flag2) {
        classification = 3;
        result = sum;
        return result;
    }

    classification = 1;

    result = sum;
    return result;


}

int main() {
    int vertex_n, n;
    cin >> vertex_n >> n;
    for (int i = 0; i < MAX; ++i) {
        fill(chess[i], chess[i] + MAX, INT_MAX);
    }
    for (int j = 0; j < n; ++j) {
        int a, b, weight;
        cin >> a >> b >> weight;
        chess[a][b] = weight;
        chess[b][a] = weight;
    }

    int k;
    cin >> k;

    int min = INT_MAX;
    int path = -1;
    for (int l = 0; l < k; ++l) {

        int m;
        cin >> m;
        int array[m];
        fill(visited, visited + vertex_n + 1, 0);
        for (int i = 0; i < m; ++i) {
            cin >> array[i];
            visited[array[i]]++;
        }

        int classification = 0;

        int result = getClassification(vertex_n, m, array, classification);

        string s;

        if (classification == 1) {
            s = "TS simple cycle";
        } else if (classification == 2) {
            s = "Not a TS cycle";
        } else if (classification == 3) {
            s = "TS cycle";
        }

        string number;

        if (result != INT_MAX) {
            stringstream ss;
            ss << result;
            number = ss.str();
        }

        cout << "Path " << l + 1 << ": " << ((result == INT_MAX) ? "NA" : number) << " (" << s << ")" << endl;

        if (classification == 1 || classification == 3) {
            if (min > result) {
                min = result;
                path = l + 1;
            }
        }

    }

    cout << "Shortest Dist(" << path << ") = " << min << endl;
}
