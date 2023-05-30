#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void print_int(set<int>k) { //����� �� ����� ��������� ������������� ���������
	for (auto it = k.begin(); it != k.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void print_str(set<string>k) { //����� �� ����� ��������� ��������� ���� string
	for (auto it = k.begin(); it != k.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void t2_4() {
	int n;
	cout << "������� ���������� ������ ������������������" << endl;
	cin >> n;
	set <int> a; // ������������������ ����� �����
	for (int i = 0; i < n; ++i) { // ���� ����� � �������
		string h; cin >> h;
		int l = stoi(h); // ������� �� string � int
		a.insert(l);
	}
	set <int> res; // ������������� ��������� 
	print_int(a);
	for (auto it = a.begin(); it != a.end(); ++it) { // ����� ���������� � ����������� ����� 
		if (*it > 10 && *it < 1000) {
			int b = *it;
			while (b) {
				res.insert(b % 10); 
				b /= 10; // ���������� �������� ����� � ���������
			}
		}
	}
	cout << "����" << endl;
	print_int(res);
}

void t2_8() {
	set <string> vopr, voskl, pov; // ��������� ���� � ������ ������������
	string razd = "!?.";
	string str = "������ ������ ����!������ ��� �� ������.������ ��� ������?";
	int pos = 0; // ������ �����������
	while (pos < str.size()) {
		int k = str.find_first_of(razd, pos); // ����� ����������� 
		auto tp = str[k]; // ��������� ���� ����������
		k -= pos;
		string temp = str.substr(pos, k) + " "; // ���������� ����������� � ����� ����������
		int pos1 = 0; // ������ �����
		while (pos1 < temp.size()) {
			int k1 = temp.find_first_of(" ", pos1); // ����� �����
			k1 -= pos1;
			string word = temp.substr(pos1, k1); // ���������� ����� � ����� ����������
			transform(word.begin(), word.end(), word.begin(), tolower); // ������� � ������ �������
			if (tp == '.') pov.insert(word);
			if (tp == '!') voskl.insert(word);
			if (tp == '?') vopr.insert(word);
			pos1 += k1 + 1; // ��������� ������ �����
		}
		pos += k + 1; // ��������� ������ �����������
		print_str(pov);
		print_str(voskl);
		print_str(vopr);
		vector <string> res;
		set_intersection(pov.begin(), pov.end(), voskl.begin(), voskl.end(), inserter(res, res.begin())); // ����������� ��������
		for (auto it = res.begin(); it != res.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		cout << res.size();
	}
}

void t2_14() {
	ifstream file;
	file.open("C:\\Users\\egor6\\source\\repos\\dz\\14.txt"); // ��������� ����
	cout << "������ ����� k" << endl;
	int k; cin >> k;
	map <string, int> let, num;
	string s, nums = "0123456789", firstWord;
	while (file >> s) { // ��������� ������ ����� �����
		int l = s.find_first_not_of(nums); // ���� � ����� ������ ������, �� ���������� ������
		if (s.find_first_not_of(nums) == string::npos) num[s]++; // ���� ��� ������� - ��� ����� �� ���������� ����� � ����������� � �������
		else {
			if (let.size() == 0) {
				firstWord == s;
			}
			let[s]++; // � ����� ���������� � ����������� �� �������
		}
	}
	cout << "�����, ������������� " << k << " ���" << endl;
	for (auto it = num.begin(); it != num.end(); ++it) {
		if (it->second == k) { // ������� �� �����, ������� ����������� k ���
			cout << it->first << endl; // ������� ��� �� �����
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ����� �������" << endl;
	cin >> n;
	if (n == 1) t2_4();
	if (n == 2) t2_8();
	if (n == 3) t2_14();
	return 0;
}