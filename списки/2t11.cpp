#include <iostream>           
#include <cmath>      
#include <algorithm>
using namespace std;
struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) { //вставка элемента в конец списка     
    list* r = new list; //создаем новый элемент     
    r->inf = x;
    r->next = NULL; //всегда последний     
    if (!h && !t) { //если список пуст     
        r->prev = NULL; //первый элемент     
        h = r; //это голова     
    }
    else {
        t->next = r; //r - следующий дл€ хвоста     
        r->prev = t; //хвост - предыдущий дл€ r     
    }
    t = r; //r теперь хвост     
}

void print(list* h, list* t) { //печать элементов списка     
    list* p = h; //укзатель на голову     
    while (p) { //пока не дошли до конца списка     
        cout << p->inf << " ";
        p = p->next; //переход к следующему элементу     
    }
}

void bubble_sort(list*& h, list*& t) {
    if (!h || !h->next) return; //если список пуст или состоит из одного элемента, то сортировка не требуетс€      
    list* p, * q, * r;
    bool flag;
    do {
        flag = false; //флаг сортировки      
        p = h;
        while (p->next) {
            q = p->next;
            if (p->inf > q->inf) { //если требуетс€ перестановка      
                r = q->next;
                if (p->prev) p->prev->next = q;  //если это не первый элемент      
                else h = q; //если это первый элемент, то q становитс€ головой      
                q->prev = p->prev; //св€зываем элементы      
                q->next = p;
                p->prev = q;
                p->next = r;
                if (r) r->prev = p;
                if (t == p) t = q; //если p - хвост, то q становитс€ хвостом 
                p = q; //p теперь после q      
                flag = true; //перестановка была      
            }
            else p = q; //переходим к следующей паре элементов      
        }
    } while (flag); //если не было перестановок, то сортировка завершена      
}

int main() {
    int n;
    list* head = NULL, * tail = NULL;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) { // вводим элементы с клавиатуры     
        int x;
        cin >> x;
        push(head, tail, x);
    }
    bubble_sort(head, tail); //сортируем список пузырьком
    print(head, tail); // выводим на экран отсортированный список 
    return 0;
}