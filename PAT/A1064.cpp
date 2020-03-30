//
// Created by GreenArrow on 2020/3/13.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct node {
    int val;
    int leftNumber, rightNumber;
} *Node, node;

int getNumbers(node *nodes, int index, int n) {
    if (index <= n) {
        nodes[index].leftNumber = getNumbers(nodes, index * 2, n);
        nodes[index].rightNumber = getNumbers(nodes, 2 * index + 1, n);
        return nodes[index].leftNumber + nodes[index].rightNumber + 1;
    } else {
        return 0;
    }
}

void setValue(node *nodes, int l, int r, int *arr, int index, int n) {
    if (index <= n) {
        nodes[index].val = arr[nodes[index].leftNumber + l];
        if (nodes[index].leftNumber > 0)
            setValue(nodes, l, nodes[index].leftNumber, arr, index * 2, n);
        if (nodes[index].rightNumber > 0)
            setValue(nodes, r - nodes[index].rightNumber + 1, r, arr, index * 2 + 1, n);
    }
}

int num = 1;

void inOrder(int *arr, int n, int index, node *nodes) {
    if (index <= n) {
        inOrder(arr, n, 2 * index, nodes);
        nodes[index].val = arr[num++];
        inOrder(arr, n, 2 * index + 1, nodes);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n * 2];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    node nodes[n * 2];

    //getNumbers(nodes, 1, n);

    sort(arr + 1, arr + n + 1);


    inOrder(arr, n, 1, nodes);
    //setValue(nodes, 1, n, arr, 1, n);
    for (int j = 1; j <= n; ++j) {
        cout << nodes[j].val;
        if (j != n) {
            cout << " ";
        }
    }
}