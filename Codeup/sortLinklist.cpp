//
// Created by GreenArrow on 2020/2/17.
//

#include <iostream>

using namespace std;

typedef struct LNode {
    int number;
    int score;
    int size = 0;
    struct LNode *next;
} *linklist;

void sortList(linklist head) {

}
void create(linklist &head, int n) {
    head = new LNode;
    head->next = nullptr;
    head->size = 0;
    for (int i = 0; i < n; ++i) {
        int number, score;
        cin >> number >> score;
        cin.ignore();

        linklist new_node = new LNode, q, p;
        new_node->number = number;
        new_node->score = score;

        p = head;
        q = p->next;
        while (q && q->number < new_node->number) {
            p = q;
            q = q->next;
        }
        new_node->next = p->next;
        p->next = new_node;

    }
}

void print(linklist head) {
    linklist p = head->next;
    while (p) {
        cout << p->number << " " << p->score << endl;
        p = p->next;
    }
}

int main() {

    int n, m;

    while (cin >> n >> m) {

        linklist head = nullptr;
        create(head, n+m);
        print(head);

    }
}

