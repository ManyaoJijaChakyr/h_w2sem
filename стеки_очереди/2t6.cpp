#include<iostream>      
#include <cmath>      
using namespace std;   
   
struct queue {   
    int inf;   
    queue* next;   
};   
   
void push(queue*& h, queue*& t, int x) { //вставка элемента в очередь   
    queue* r = new queue; //создаем новый элемент   
    r->inf = x;   
    r->next = NULL; //всегда последний   
    if (!h && !t) { //если очередь пуста   
        h = t = r; //это и голова и хвост   
    }   
    else {   
        t->next = r; //r - следующий для хвоста   
        t = r; //теперь r - хвост   
    }   
}   
   
int pop(queue*& h, queue*& t) { //удаление элемента из очереди   
    queue* r = h; //создаем указатель на голову   
    int i = h->inf; //сохраняем значение головы   
    h = h->next; //сдвигаем указатель на следующий элемент   
    if (!h) //если удаляем последний элемент из очереди   
        t = NULL;   
    delete r; //удаляем первый элемент   
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
