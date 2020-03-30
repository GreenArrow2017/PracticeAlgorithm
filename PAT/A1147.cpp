//
// Created by GreenArrow on 2020/3/15.
//
#include <iostream>
#include <vector>

using namespace std;

bool isHeap(int *array, int n, bool maxHeap) {
    for (int i = 1; i <= n / 2; ++i) {
        int left = i * 2;
        int right = left + 1;
        if (left <= n) {
            if (maxHeap) {
                if (array[left] > array[i]) {
                    return false;
                }
            } else {
                if (array[left] < array[i]) {
                    return false;
                }
            }
        }

        if (right <= n) {
            if (maxHeap) {
                if (array[right] > array[i]) {
                    return false;
                }
            } else {
                if (array[right] < array[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void postOrder(int *array, int index, int n, vector<int> &sequences) {
    if (index <= n) {
        postOrder(array, 2 * index, n, sequences);
        postOrder(array, 2 * index + 1, n, sequences);
        sequences.push_back(array[index]);
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int array[m + 1];
        for (int j = 1; j <= m; ++j) {
            cin >> array[j];
        }

        bool isTree = isHeap(array, m, array[1] >= array[2]);
        if (isTree) {
            if (array[1] >= array[2]) {
                cout << "Max Heap" << endl;
            } else {
                cout << "Min Heap" << endl;
            }
        } else {
            cout << "Not Heap" << endl;
        }
        vector<int> sequences;
        postOrder(array, 1, m, sequences);
        for (int k = 0; k < sequences.size(); ++k) {
            cout << sequences[k];
            if (sequences.size() - 1 != k) {
                cout << " ";
            }
        }
        cout << endl;

    }

}
