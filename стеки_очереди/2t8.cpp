#include <iostream>
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

void remove_duplicates(queue*& h, queue*& t) { //�������� ������������� ��������� �� �������
    queue* current = h;
    queue* runner;
    queue* duplicate;

    while (current != NULL && current->next != NULL) {
        runner = current;
        while (runner->next != NULL) {
            if (current->inf == runner->next->inf) {
                duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    int n;
    cout << " n = ";
    cin >> n;

    queue* head = NULL;
    queue* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(head, tail, x);
    }

    remove_duplicates(head, tail);

    while (head != NULL) {
        cout << pop(head, tail) << " ";
    }

    return 0;
}