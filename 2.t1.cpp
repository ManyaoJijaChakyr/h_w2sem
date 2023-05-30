#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

void t1_4() {
	vector <int> a = { 2,2,3,4,5,5,6,7,9,9,9,9,10,11,7,4,11,8,11 }; // ������ 
	int maxa = *max_element(a.begin(), a.end()); // ����������� �������
	int c = 0; // ������� ������������ ���������
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == maxa) c++; 
	}
	cout << "���������� ����������� ��������� �����������������: " << c;
}

int ax; // ���������� ���������� ��� reove_if

void t1_10() {
	list <int> a = { 2,2,3,4,5,5,6,7,9,9,9,9,10,11,7,4,11,8,11 }; // ������ 
	int maxa = *max_element(a.begin(), a.end()); // ����������� �������
	int mina = *min_element(a.begin(), a.end()); // ���������� �������
	int nn; // ����� �������
	cout << "������� ����� �" << endl;
	cin >> ax;
	cout << endl;
	cout << "������� ����� �������" << endl;
	cin >> nn;
	cout << endl;
	a.remove_if([](int n) {return n % ax == 0;  }); // �������� ���� ��������� ������� �
	for (auto it = a.begin(); it != a.end(); ++it) { 
		if (*it == maxa) { // ������� ������������ �������
			it++;
			a.insert(it, nn); // ������ ����� ���� ����� �������
			it--;
		}
	}
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (*it % 2 == 1) { // ������� �������� �������
			if (*it == 1) { // ���� ������ ������� �������� ��������, ������ �������� � ������ ������
				it = a.erase(it); // ������� ������ �������
				a.insert(it, mina); // �� ��� ����� ������ ����������� ������� ������������������
				it = a.begin();
			}
			else {
				it = a.erase(it); // ������� ������ �������
				it--;
				a.insert(it, mina); // �� ��� ����� ������ ����������� ������� ������������������
			}
		}
	}
	for (auto it = a.begin(); it != a.end(); ++it) { // ����� �������� ������������������ �� �����
		cout << *it << " ";
	}
}

int bx; // ���������� ���������� ��� remove_if

int t1_14() {
	setlocale(LC_ALL, "Russian");
	list <int> a = { 2,2,3,4,5,5,6,7,9,9,9,9,10,11,11,7,4,11,8,11 }; // ������ ����������������� 
	list <int> b = { 6,0,5,12,4,16,5,5,17,17,10,15,13,10,11,12,1,15,2,6 }; // ������ ����������������
	cout << "������� ������� �" << endl;
	int x; cin >> x;
	cout << endl;
	cout << "������� ����� �������" << endl;
	int nn; cin >> nn;
	cout << endl;
	for (auto it = a.begin(); it != a.end(); ++it) { 
		if (*it % 2 == 0 && *it % x == 0) { // ������� ������ ������� ������� �
			it++;
			a.insert(it, nn); // ������ ����� ���� ����� �������
			it--;
		}
	}
	int max = *max_element(b.begin(), b.end()); // ������� ������������ �������
	bx = max;
	b.remove_if([](int n) {return (n == bx); }); // ������� ��� ����������� ��������
	/*for (auto it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = b.begin(); it != b.end(); ++it) {
		cout << *it << " ";
	}*/
	a.sort(); // ���������� ������ ������������������ 
	a.unique(); // �������� ������������� ���������
	b.sort(); // ���������� ������ ������������������
	b.unique(); // �������� ������������� ���������
	a.merge(b); // ����������� � ���� ������������������
	cout << endl;
	for (auto it = a.begin(); it != a.end(); ++it) { // ����� �������� ������������������ �� �����
		cout << *it << " ";
	}
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� �������" << endl;
	int n; cin >> n;
	cout << endl;
	if (n == 1) t1_4();
	if (n == 2) t1_10();
	if (n == 3) t1_14();
	return 0;
}
