//
// Created by GreenArrow on 2020/3/5.
//
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} *Node, node;

void create(Node &head, int n) {
    Node p = head;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            head = new node;
            head->data = i;
            head->next = nullptr;
            p = head;
        } else {
            Node u = new node;
            u->data = i;
            u->next = nullptr;
            p->next = u;
            p = u;
        }
    }
    p->next = head;
}

void print(Node head, int n) {
    Node p = head;
    for (int i = 0; i < n; i++) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int number;
    int n;
    cin >> n >> number;
    Node head;
    create(head, n);
    //print(head, n);

    int size = n;
    int index = 1;
    Node p, q;
    p = head;
    while (size) {
        q = p;
        p = p->next;
        index++;
        if (index == number) {
            q->next = p->next;
            size--;
            index = 1;
            cout << p->data << " ";
            delete p;
            p = q->next;
        }
    }

}