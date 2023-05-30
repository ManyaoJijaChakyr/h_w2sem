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

void push(stack*& h, int x) {//вставка      
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack*& h) { //удаление      
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}


void reverse(stack*& h) { //"обращение"стека      
    stack* head1 = NULL; //инициализация буферного стека      
    while (h) //пока стек не пуст      
        push(head1, pop(h)); //переписываем из одного стека в другой      
    h = head1; //переобозначаем указатели      
}

stack* result(stack*& h) {
    stack* res = NULL; //инициализация      
    stack* odd = NULL; //стек для нечетных чисел      
    stack* even = NULL; //стек для четных чисел      
    while (h) {
        int x = pop(h); //удаляем первый элемент      
        if (x % 2 == 0) push(even, x); //если четное - добавляем в соответствующий стек      
        else push(odd, x); //если нечетное - добавляем в соответствующий стек      
    }
    //создаем новый стек, добавляя сначала нечетные, потом четные числа      
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
    stack* head = NULL; //инициализация      
    int x;
    for (int i = 0; i < n; i++) { //создаем стек      
        cin >> x;
        push(head, x);
    }
    reverse(head); //переворачиваем стек      
    stack* res = result(head); //результат      
    while (res)
        cout << pop(res) << " "; //выводим на экран      

    cout << endl;
    return 0;
}