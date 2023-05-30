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

void remove_duplicates(list*& h, list*& t) {
    list* current = t;  // current - ��������� �� ������� �������, �������� � ���������� 
    list* runner;  // runner - ��������� ��� �������� ��������� ������ 
    list* duplicate;  // duplicate - ��������� �� �������, ������� ����� ������� (��������) 
    while (current && current->prev) {  // ���������� �� ���� ��������� ������ (����� �������) 
        runner = current;
        while (runner->prev) {  // ���������� �� ���� ��������� ������ (����� ��������) 
            if (current->inf == runner->prev->inf) {  // ���� �������� ��������� 
                duplicate = runner->prev;  // ��������� ��������� �� �������� 
                runner->prev = runner->prev->prev;  // ������� �������� �� ������ 
                if (duplicate == h) { // ���� ��������� �������� �������, ��������� ��������� �� ������ 
                    h = runner;
                }
                if (duplicate == t) { // ���� ��������� ��������� �������, ��������� ��������� �� ����� 
                    t = current;
                }
                if (duplicate->prev) { // ��������� ������ �������� ��������� 
                    duplicate->prev->next = runner;
                }
                runner->prev = duplicate->prev;  // runner - ����� ���������� ��� ���������� �������� 
                delete duplicate;  // ������� �������� 
            }
            else {
                runner = runner->prev;
            }
        }
        current = current->prev;  // ��������� � ���������� �������� 
    }
}

void print(list* h, list* t) { //������ ��������� ������  
    list* p = h; //�������� �� ������  
    while (p) { //���� �� ����� �� ����� ������  
        cout << p->inf << " ";
        p = p->next; //������� � ���������� ��������  
    }
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
    remove_duplicates(head, tail);
    print(head, tail); // ������� �� ����� ������  
    return 0;
}

