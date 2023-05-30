#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

void t1_4() {
	vector <int> a = { 2,2,3,4,5,5,6,7,9,9,9,9,10,11,7,4,11,8,11 }; // список 
	int maxa = *max_element(a.begin(), a.end()); // максималный элемент
	int c = 0; // счетчик максимальных элементов
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == maxa) c++; 
	}
	cout << "Количество максималных элементов последователности: " << c;
}

int ax; // глобальная переменная для reove_if

void t1_10() {
	list <int> a = { 2,2,3,4,5,5,6,7,9,9,9,9,10,11,7,4,11,8,11 }; // список 
	int maxa = *max_element(a.begin(), a.end()); // максималный элемент
	int mina = *min_element(a.begin(), a.end()); // минималный элемент
	int nn; // новый элемент
	cout << "Введите число Х" << endl;
	cin >> ax;
	cout << endl;
	cout << "Введите новый элемент" << endl;
	cin >> nn;
	cout << endl;
	a.remove_if([](int n) {return n % ax == 0;  }); // удаление всех элементов кратных Х
	for (auto it = a.begin(); it != a.end(); ++it) { 
		if (*it == maxa) { // находим максимальный элемент
			it++;
			a.insert(it, nn); // ставим после него новый элемент
			it--;
		}
	}
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (*it % 2 == 1) { // находим нечетный элемент
			if (*it == 1) { // если первый элемент оказался нечетным, ставим итератор в начало списка
				it = a.erase(it); // удаляем старый элемент
				a.insert(it, mina); // на его место ставим минимальный элемент последовательности
				it = a.begin();
			}
			else {
				it = a.erase(it); // удаляем старый элемент
				it--;
				a.insert(it, mina); // на его место ставим минимальный элемент последовательности
			}
		}
	}
	for (auto it = a.begin(); it != a.end(); ++it) { // вывод конечной последовательности на экран
		cout << *it << " ";
	}
}

int bx; // глобальная переменная для remove_if

int t1_14() {
	setlocale(LC_ALL, "Russian");
	list <int> a = { 2,2,3,4,5,5,6,7,9,9,9,9,10,11,11,7,4,11,8,11 }; // превая последователность 
	list <int> b = { 6,0,5,12,4,16,5,5,17,17,10,15,13,10,11,12,1,15,2,6 }; // вторая последователност
	cout << "Введите элемент Х" << endl;
	int x; cin >> x;
	cout << endl;
	cout << "Введите новый элемент" << endl;
	int nn; cin >> nn;
	cout << endl;
	for (auto it = a.begin(); it != a.end(); ++it) { 
		if (*it % 2 == 0 && *it % x == 0) { // находим четный элемент кратный Х
			it++;
			a.insert(it, nn); // ставим после него новый элемент
			it--;
		}
	}
	int max = *max_element(b.begin(), b.end()); // находим максимальный элемент
	bx = max;
	b.remove_if([](int n) {return (n == bx); }); // удаляем все максималные элементы
	/*for (auto it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = b.begin(); it != b.end(); ++it) {
		cout << *it << " ";
	}*/
	a.sort(); // сортировка первой последовательности 
	a.unique(); // удаление повторяющихся элементов
	b.sort(); // сортировка второй последовательности
	b.unique(); // удаление повторяющихся элементов
	a.merge(b); // объединение в одну последовательность
	cout << endl;
	for (auto it = a.begin(); it != a.end(); ++it) { // вывод конечной последовательности на экран
		cout << *it << " ";
	}
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	cout << "Введите номер задания" << endl;
	int n; cin >> n;
	cout << endl;
	if (n == 1) t1_4();
	if (n == 2) t1_10();
	if (n == 3) t1_14();
	return 0;
}
