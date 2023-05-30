#include <iostream>
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

void remove_duplicates(queue*& h, queue*& t) { //удаление повторяющихся элементов из очереди
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