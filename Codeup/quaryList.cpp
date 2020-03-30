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

linklist create(int n, int num, int &index) {
    linklist head = new LNode;
    linklist p, q;

    q = head;

    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;

        if (element == num) {
            index = i;
        }

        p = new LNode;
        p->next = nullptr;
        p->data = element;

        q->next = p;

        q = p;

        head->size++;
    }

    return head;

}

void insert(linklist head, int num) {
    linklist p = head->next;
    linklist q = head;
    while (p && p->data < num) {
        q = p;
        p = p->next;
    }

    linklist u = new LNode;
    u->next = nullptr;
    u->data = num;
    u->next = q->next;
    q->next = u;

    head->size++;
}

void print(linklist head) {
    linklist p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void swap(linklist head, int index) {
    linklist p, q;
    q = head;
    p = q->next;

    while (index--) {
        q = p;
        p = p->next;
    }

    linklist last = p->next;
    p->next = last->next;
    q->next = last;
    last->next = p;
}

int main() {
    int num;

    while (cin >> num) {
        cin.ignore();

        int n;
        cin >> n;
        cin.ignore();


        int index = -1;
        linklist head = create(n, num, index);

        if (index == -1) {
            cout << "no" << endl;
            insert(head, num);
        } else {
            cout << "yes" << endl;
            swap(head, index);
        }

        print(head);

    }
}

