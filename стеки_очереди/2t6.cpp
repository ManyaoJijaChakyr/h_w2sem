#include<iostream>      
#include <cmath>      
using namespace std;   
   
struct queue {   
    int inf;   
    queue* next;   
};   
   
void push(queue*& h, queue*& t, int x) { //������� �������� � �������   
    queue* r = new queue; //������� ����� �������   
    r->inf = x;   
    r->next = NULL; //������ ���������   
    if (!h && !t) { //���� ������� �����   
        h = t = r; //��� � ������ � �����   
    }   
    else {   
        t->next = r; //r - ��������� ��� ������   
        t = r; //������ r - �����   
    }   
}   
   
int pop(queue*& h, queue*& t) { //�������� �������� �� �������   
    queue* r = h; //������� ��������� �� ������   
    int i = h->inf; //��������� �������� ������   
    h = h->next; //�������� ��������� �� ��������� �������   
    if (!h) //���� ������� ��������� ������� �� �������   
        t = NULL;   
    delete r; //������� ������ �������   
    return i;   
}   

int main() {   
    int n, max = -1, cnt = 0, last_even = -1;   
    queue* head = NULL, * tail = NULL;
    queue* head1 = NULL, * tail1 = NULL;
    cout << "n = ";   
    cin >> n;   
    for (int i = 0; i < n; i++) {   
        int x;   
        cin >> x;   
        push(head, tail, x); 
        if (x > max) {   
            max = x;   
            cnt = 1;   
        }   
        else if (x == max) {   
            cnt++;   
        }   
        if (x % 2 == 0) {   
            last_even = x;   
        } 
    }   
    while (head) {   
        int x = pop(head, tail);
        cout << x << " ";
        if (x == max) {
            cout << last_even << " ";
        }
    }   
    return 0;   
} 
