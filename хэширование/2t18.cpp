#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <list>
using namespace std;

ifstream in("C:\\Users\\egor6\\h_w2sem\\employee.txt");


struct date
{
	int dd, mm, yy;
};

struct people
{
	string sname;
	string dlj;
	date dob;
	int stj;
	int zp;
};

date strtodate(string str) {
	date x;
	string temp = str.substr(0, 2);
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);
	x.yy = atoi(temp.c_str());
	return x;
}

vector<people> inFile() {
	vector<people> a;
	people temp;
	for (int i = 0; i < 25; ++i) {
		in >> temp.sname;
		in >> temp.dlj;
		string tmp;
		in >> tmp;
		temp.dob = strtodate(tmp);
		in >> temp.stj;
		in >> temp.zp;
		a.push_back(temp);
	}
	return a;
}

int help_f(int x, int size) {
	int k = x % size;
	return k;
}

int linear(int a, int b, int size) {
	return ((a + b) % size);
}

void createHT(vector<people> a, vector<list<people>> &e) {
	for (int i = 0; i < a.size(); ++i) {
		int k = a[i].stj % a.size();
		e[k].push_back(a[i]);
	}
}

void printdate(date d) {
	cout << d.dd << "." << d.mm << "." << d.yy << " ";
}
void print(people x) {
	cout << x.sname << " " << x.dlj << " "; printdate(x.dob); cout << x.stj << " " << x.zp << ", ";
}

void find_stj(vector<list<people>> a, int x) {
	int k = x % a.size();
	cout << "Информация о пользовательях со стажем " << k << ":" << endl;
	for (auto it = a[k].begin(); it != a[k].end(); ++it) {
		people w = *it;
		if (w.stj == x) {
			print(w);
			cout << endl;
		}
	}
	cout << endl;
}

void delete_stj(vector<list<people>>& a, int x) {
	int k = x % a.size();
	for (auto it = a[k].begin(); it != a[k].end(); ) {
		people w = *it;
		if (w.stj == x) {
			it = a[k].erase(it);
		}
		else {
			++it;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<people> a;
	a = inFile();
	vector<list<people>> e(a.size());
	createHT(a, e);
	for (int i = 0; i < e.size(); ++i) {
		cout << i << ": ";
		for (auto it = e[i].begin(); it != e[i].end(); ++it) {
			people x = *it;
			print(x);
		}
		cout << endl;
	}
	cout << "Введите стаж для получения информации" << endl;
	int r; cin >> r;
	find_stj(e, r);
	cout << "Введите стаж для удаления информации" << endl;
	int q; cin >> q;
	delete_stj(e, q);
	for (int i = 0; i < e.size(); ++i) {
		cout << i << ": ";
		for (auto it = e[i].begin(); it != e[i].end(); ++it) {
			people x = *it;
			print(x);
		}
		cout << endl;
	}
	return 0;
}