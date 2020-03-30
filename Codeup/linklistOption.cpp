//
// Created by GreenArrow on 2020/2/17.
//
#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
    int size = 0;
} LNode, *linklist;

LNode *create(int n) {
    LNode *head;
    LNode *p;
    head = new LNode;
    head->next = nullptr;
    p = head;
    for (int i = 0; i < n; ++i) {
        LNode *q;
        int num;
        cin >> num;
        q = new LNode;
        q->next = nullptr;
        q->data = num;

        q->next = p->next;
        p->next = q;

        head->size++;
    }
    return head;
}

void print(LNode *head) {
    linklist p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int get(linklist head, int n, bool &flag) {
    int size = head->size;
    if (size < n || n <= 0) {
        flag = false;
        return -1;
    }
    linklist p = head;
    while (n--) {
        p = p->next;
    }
    flag = true;
    return p->data;
}

string insert(linklist head, int n, int num) {
    int size = head->size;
    if (size + 1 < n || n <= 0) {
        return "insert fail";
    }
    linklist p = head;
    n--;
    while (n--) {
        p = p->next;
    }


    linklist q = new LNode;
    q->next = nullptr;
    q->data = num;

    q->next = p->next;
    p->next = q;

    head->size++;

    return "insert OK";
}

string del(linklist head, int n) {
    int size = head->size;
    if (size < n || n <= 0) {
        return "delete fail";
    }
    linklist p = head->next;
    linklist q = head;
    n--;
    while (n--) {
        p = p->next;
        q = q->next;
    }

    q->next = p->next;

    head->size--;
    delete p;

    return "delete OK";
}


bool show(linklist head) {
    if (head->size == 0) {
        return false;
    }

    linklist p = head->next;
    while (p) {
        cout << p->data;
        if (p->next != nullptr) {
            cout << " ";
        }
        p = p->next;
    }
    cout << endl;
    return true;
}

int main() {
    int n;
    cin >> n;

    linklist head = create(n);
    string s;
    int number;
    cin >> number;
    cin.ignore();
    for (int i = 0; i < number; i++) {
        cin >> s;
        if (s == "get") {
            int m;
            cin >> m;
            cin.ignore();
            bool success = true;
            int num = get(head, m, success);
            if (success) {
                cout << num << endl;
            } else {
                cout << "get fail" << endl;
            }
        } else if (s == "insert") {
            int m, num;
            cin >> m >> num;
            cin.ignore();
            cout << insert(head, m, num) << endl;
        } else if (s == "delete") {
            int m;
            cin >> m;
            cin.ignore();
            cout << del(head, m) << endl;
        } else if (s == "show") {
            if (!show(head))
                cout << "Link list is empty" << endl;
        }

    }

}

