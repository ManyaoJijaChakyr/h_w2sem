#include <iostream>           
#include <cmath>      
#include <algorithm>
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

void bubble_sort(list*& h, list*& t) {
    if (!h || !h->next) return; //���� ������ ���� ��� ������� �� ������ ��������, �� ���������� �� ���������      
    list* p, * q, * r;
    bool flag;
    do {
        flag = false; //���� ����������      
        p = h;
        while (p->next) {
            q = p->next;
            if (p->inf > q->inf) { //���� ��������� ������������      
                r = q->next;
                if (p->prev) p->prev->next = q;  //���� ��� �� ������ �������      
                else h = q; //���� ��� ������ �������, �� q ���������� �������      
                q->prev = p->prev; //��������� ��������      
                q->next = p;
                p->prev = q;
                p->next = r;
                if (r) r->prev = p;
                if (t == p) t = q; //���� p - �����, �� q ���������� ������� 
                p = q; //p ������ ����� q      
                flag = true; //������������ ����      
            }
            else p = q; //��������� � ��������� ���� ���������      
        }
    } while (flag); //���� �� ���� ������������, �� ���������� ���������      
}

int main() {
    int n;
    list* head = NULL, * tail = NULL;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) { // ������ �������� � ����������     
        int x;
        cin >> x;
        push(head, tail, x);
    }
    bubble_sort(head, tail); //��������� ������ ���������
    print(head, tail); // ������� �� ����� ��������������� ������ 
    return 0;
}