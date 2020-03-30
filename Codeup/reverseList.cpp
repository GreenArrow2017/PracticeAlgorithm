//
// Created by GreenArrow on 2020/2/18.
//

#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
    int size = 0;
} *linklist;

void create(linklist &head, int n) {
    linklist p, q;

    head = new LNode;
    head->next = nullptr;
    head->data = -1;
    head->size = 0;

    p = head;
    while (n--) {
        int element;
        cin >> element;

        cout << element << " ";

        q = new LNode;
        q->next = nullptr;
        q->data = element;

        q->next = p->next;
        p->next = q;

        head->size++;
    }
    cout << endl;
}

void print(linklist head) {
    linklist p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

int main() {
    int n;
    while (cin >> n) {

        if (n == 0) {
            cout << "list is empty" << endl;
            continue;
        }

        linklist head;
        create(head, n);
        print(head);

    }
}
