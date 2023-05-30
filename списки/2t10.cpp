#include <iostream>        
#include <cmath>        
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
        t->next = r; //r - следующий для хвоста  
        r->prev = t; //хвост - предыдущий для r  
    }
    t = r; //r теперь хвост  
}

void remove_duplicates(list*& h, list*& t) {
    list* current = t;  // current - указатель на текущий элемент, начинаем с хвостового 
    list* runner;  // runner - указатель для перебора элементов списка 
    list* duplicate;  // duplicate - указатель на элемент, который нужно удалить (дубликат) 
    while (current && current->prev) {  // проходимся по всем элементам списка (кроме первого) 
        runner = current;
        while (runner->prev) {  // проходимся по всем элементам списка (кроме текущего) 
            if (current->inf == runner->prev->inf) {  // если элементы одинаковы 
                duplicate = runner->prev;  // сохраняем указатель на дубликат 
                runner->prev = runner->prev->prev;  // удаляем дубликат из списка 
                if (duplicate == h) { // если удаляется головной элемент, обновляем указатель на голову 
                    h = runner;
                }
                if (duplicate == t) { // если удаляется хвостовой элемент, обновляем указатель на хвост 
                    t = current;
                }
                if (duplicate->prev) { // обновляем ссылки соседних элементов 
                    duplicate->prev->next = runner;
                }
                runner->prev = duplicate->prev;  // runner - новый предыдущий для следующего элемента 
                delete duplicate;  // удаляем дубликат 
            }
            else {
                runner = runner->prev;
            }
        }
        current = current->prev;  // переходим к следующему элементу 
    }
}

void print(list* h, list* t) { //печать элементов списка  
    list* p = h; //укзатель на голову  
    while (p) { //пока не дошли до конца списка  
        cout << p->inf << " ";
        p = p->next; //переход к следующему элементу  
    }
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
    remove_duplicates(head, tail);
    print(head, tail); // выводим на экран список  
    return 0;
}

