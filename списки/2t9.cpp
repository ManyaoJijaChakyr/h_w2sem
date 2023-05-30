#include <iostream>      
#include <cmath>      
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) { //������� �������� � ����� ������
    list* r = new list; //������� ����� �������
    r->inf = x;
    r->next = NULL; //������ ���������
    if (!h && !t) { //���� ������ ����
        r->prev = NULL; //������ �������
        h = r; //��� ������
    }
    else {
        t->next = r; //r - ��������� ��� ������
        r->prev = t; //����� - ���������� ��� r
    }
    t = r; //r ������ �����
}

void print(list* h, list* t) { //������ ��������� ������
    list* p = h; //�������� �� ������
    while (p) { //���� �� ����� �� ����� ������
        cout << p->inf << " ";
        p = p->next; //������� � ���������� ��������
    }
}

list* find(list* h, list* t, int x) { //������ ��������� ������
    list* p = h; //�������� �� ������
    while (p) { //���� �� ����� �� ����� ������
        if (p->inf == x) break; // ���� �����, ���������� ����
            p = p->next; //������� � ���������� ��������
    }
    return p; //���������� ���������
}

void insert_after(list*& h, list*& t, list* r, int y) { //��������� ����� r
    list* p = new list; //������� ����� �������
    p->inf = y;
    if (r == t) { //���� ��������� ����� ������
        p->next = NULL; //����������� ��-� - ���������
        p->prev = r; //��������� ����� r
        r->next = p;
        t = p; //������ ����� - p
    }
    else { //��������� � �������� ������
        r->next->prev = p; //��� ���������� �� r ��-�� ���������� - p
        p->next = r->next; //��������� �� p - ��������� �� r
        p->prev = r; //p ��������� ����� r
        r->next = p;
    }
}

int del_node(list*& h, list*& t, list* r) { //������� ����� r   
    int x = r->next->inf; //���������� ��������� �������
    if (r == h && r == t) //������������ ������� ������   
        h = t = NULL;
    else if (r == h) { //������� ������ ������   
        h = h->next; //�������� ������   
        h->prev = NULL;
    }
    else if (r == t) { //������� ����� ������   
        t = t->prev; //�������� �����   
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev; //��� ���������� �� r ���������� ���������� r->prev   
        r->prev->next = r->next; //��� ����������� �� r ��������� ���������� r->next   
    }
    delete r; //������� r   
    return x; //���������� ��������� �������
}

void del_list(list*& h, list*& t) { //������� ������
    while (h) { //���� ������ �� ����
        list* p = h; //��������� �� ������
        h = h->next; //��������� ������
        h->prev = NULL; //��������
        delete p; //������� p
    }
}

int main() {
    int n, first = 0, cnt = 1, max = -1;
    list* head = NULL, * tail = NULL;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) { // ������ �������� � ����������
        int x;
        cin >> x;
        push(head, tail, x);
        if (cnt > 0) { // ������� ������ �������
           first = x;
           cnt-- ;
        }
        if (x > max) { // ������� ������������ �������
            max = x;
            cnt = 1;
        }
    }
    list* p = head;
    while (p) {
        list* r = p;
        if (p->inf == first) {
            insert_after(head, tail, r, max); // ����� ������� ������� ������� �������� ��������� ������������
        }
        p = p->next;
    }
    print(head, tail); // ������� �� ����� ������
    del_list(head, tail); // ������� ������
    return 0;
}