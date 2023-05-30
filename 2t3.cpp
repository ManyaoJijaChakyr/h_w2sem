#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream in("input1.txt");
ofstream out("output.txt");

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
	for (int i = 0; i < 20; ++i) {
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

void print(people a) {
	out << setw(10) << left << a.sname << '\t';
	out << left << setw(10) << a.dlj << '\t'; // заменяем endl на символ табуляции
	if (a.dob.dd < 10) out << left << '0' << a.dob.dd << '.';
	else out << left << a.dob.dd << '.';
	if (a.dob.mm < 10) out << left << '0' << a.dob.mm << '.';
	else out << left << a.dob.mm << '.';
	out << left << setw(6) << a.dob.yy;
	out << left << setw(10) << a.stj << '\t'; // заменяем endl на символ табуляции
	out << left << setw(10) << a.zp << endl;
}

bool operator < (people c, people b) {
	if (c.sname < b.sname) return true;
	if (c.sname == b.sname && c.dlj < b.dlj) return true;
	if (c.sname == b.sname && c.dlj == b.dlj && c.dob.yy < b.dob.yy) return true;
	if (c.sname == b.sname && c.dlj == b.dlj && c.dob.yy == b.dob.yy && c.stj < b.stj) return true;
	if (c.sname == b.sname && c.dlj == b.dlj && c.dob.yy == b.dob.yy && c.stj == b.stj && c.zp < b.zp) return true;

}



void merges(vector<people>& a, int l, int r, int m) {
	if (r - l >= 1) {
		if (a[l].zp > a[r].zp) {
			swap(a[l], a[r]);
		}
		vector<people> b;
		int i = l, j = m + 1;
		while (b.size() < r - l + 1) {
			if (i > m) {
				for (int k = j; k <= r; ++k) {
					b.push_back(a[k]);
				}
			}
			else if (j > r) {
				for (int k = i; k <= m; ++k) {
					b.push_back(a[k]);
				}
			}
			else if (a[i].zp < a[j].zp) {
				b.push_back(a[i]);
				i++;
			}
			else {
				b.push_back(a[j]);
				j++;
			}
		}
		for (int i = 0; i < b.size(); ++i) {
			a[l + i] = b[i]; // записываем отсортированный подмассив в исходный вектор a
		}
	}
}

void mergesort(vector<people>& a, int l, int r) {
	if (r - l >= 1) {
		int m = (l + r) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merges(a, l, r, m);
	}
}

void vst(vector<people>& a) {
	int N = a.size();
	for (int i = 1; i < N; ++i) {
		int j = i;
		while (a[j].sname < a[j - 1].sname or a[j].sname == a[j - 1].sname and a[j].stj < a[j - 1].stj or a[j].sname == a[j - 1].sname and a[j].stj == a[j - 1].stj and a[j].dob.yy < a[j - 1].dob.yy) {
			swap(a[j], a[j - 1]);
			j--;
			if (j == 0) break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите номер задания" << endl;
	int d; cin >> d;
	vector<people> a;
	a = inFile();
	int N = a.size() / 3 + 1;
	//blockSort(a, a.size(), N);
	if (d == 2) {
		int l = 0, r = 20 - 1, m = 10;
		mergesort(a, l, r);
	}
	if (d == 3) {
		vst(a);
	}
	for (int i = 0; i < a.size(); ++i) {
		print(a[i]);
	}
	return 0;
}