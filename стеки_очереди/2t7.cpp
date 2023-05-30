#include<iostream>      
#include <cmath>      
using namespace std;

struct stack {
    int inf;
    stack* next;
};

bool isPrime(int x) {
    if (x == 1) return true;
    else {
        for (int i = 2; i < x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
}

void push(stack*& h, int x) {//�������      
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack*& h) { //��������      
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}


void reverse(stack*& h) { //"���������"�����      
    stack* head1 = NULL; //������������� ��������� �����      
    while (h) //���� ���� �� ����      
        push(head1, pop(h)); //������������ �� ������ ����� � ������      
    h = head1; //�������������� ���������      
}

stack* result(stack*& h) {
    stack* res = NULL; //�������������      
    stack* odd = NULL; //���� ��� �������� �����      
    stack* even = NULL; //���� ��� ������ �����      
    while (h) {
        int x = pop(h); //������� ������ �������      
        if (x % 2 == 0) push(even, x); //���� ������ - ��������� � ��������������� ����      
        else push(odd, x); //���� �������� - ��������� � ��������������� ����      
    }
    //������� ����� ����, �������� ������� ��������, ����� ������ �����      
    while (even) {
        int x = pop(even);
        push(res, x);
    }
    while (odd) {
        int x = pop(odd);
        push(res, x);
    }
    return res;
}

int main() {
    int n;
    cout << " n = ";
    cin >> n;
    stack* head = NULL; //�������������      
    int x;
    for (int i = 0; i < n; i++) { //������� ����      
        cin >> x;
        push(head, x);
    }
    reverse(head); //�������������� ����      
    stack* res = result(head); //���������      
    while (res)
        cout << pop(res) << " "; //������� �� �����      

    cout << endl;
    return 0;
}