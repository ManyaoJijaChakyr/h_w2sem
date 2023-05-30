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
/*
void createHT(vector<people> a, vector<people>& e) {
	int j = 0;
	for (int i = 0; i < a.size(); ++i) {
		int k = help_f(a[i].dob.yy, a.size());
		//int j = 0;
		for (int l = 0; l < a.size() * 2; ++l) {
			int p = linear(k, i, a.size());
			if (e[p].dob.yy == 0) {
				e[p] = a[i];
				break;
			}
			else j++;
		}
	}
}*/
void createHT(vector<people> a, vector<people>& e) {
	int j = 0;
	for (int i = 0; i < a.size(); ++i) {
		int k = help_f(a[i].dob.yy, a.size());
		for (int l = 0; l < a.size() * 2; ++l) {
			int p = linear(k, l, a.size());
			if (e[p].dob.yy == 0) {
				e[p] = a[i];
				break;
			}
			else j++;
			if (l == a.size() * 2 - 1) i++; 
		}
	}
}

void printdate(date d) {
	cout << d.dd << "." << d.mm << "." << d.yy << " ";
}
void print(people x) {
	cout << x.sname << " " << x.dlj << " "; printdate(x.dob); cout << x.stj << " " << x.zp << ", ";
}

void find_el(int x, vector<people> e) {
	int k = help_f(x, 31);
	for (int i = k; i < 31; ++i) {
		if (e[i].dob.yy == x) {
			cout << "Работник " << x << " года рождения: ";
			print(e[i]);	
			cout << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<people> a;
	a = inFile();
	vector<people> e(31);
	createHT(a, e);
	for (int i = 0; i < 31; ++i) {
		cout << i << ": ";
		print(e[i]);
		cout << endl;
	}
	int c; cin >> c;
	find_el(c, e);
	return 0;

}

