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
    head = new LNode;
    head->next = nullptr;
    head->data = 0;
    head->size = 0;

    linklist p = head;
    linklist u;

    while (n--) {

        int element;
        cin >> element;
        u = new LNode;
        u->data = element;
        u->next = nullptr;

        p->next = u;
        p = p->next;
        p->next = nullptr;

        head->size++;
    }
}

void print(linklist head) {
    linklist p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteDuplication(linklist &head) {
    linklist p, q;
    p = q = head;
    p = q->next;
    while (p && p->next) {
        if (p->data == p->next->data) {
            linklist u = p->next;
            p->next = u->next;
            delete u;
            head->size--;
        } else {
            p = p->next;
        }
    }
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
        deleteDuplication(head);
        print(head);
    }

}

