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
	stack* h1 = NULL;
	while (h) {
		int x = pop(h); //������� ������ �������
		push(res, x); //���������� � ���������
		if (isPrime(x)) {
			push(res, 0); //���� ����� �������, ��������� 0 � ���������
		}
		while (h) {
			int y = pop(h); //������� ������� �� �����
			if (x != y) push(h1, y); //���������� � ����� ����
		}
		reverse(h1); //�������������� ����
		h = h1; //�������������� ���������
		h1 = NULL;
	}
	reverse(res); //�������������� �������������� ����
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

