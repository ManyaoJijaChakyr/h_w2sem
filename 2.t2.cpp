#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void print_int(set<int>k) { //вывод на экран множества целочисленных элементов
	for (auto it = k.begin(); it != k.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void print_str(set<string>k) { //вывод на экран множества элементов типа string
	for (auto it = k.begin(); it != k.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void t2_4() {
	int n;
	cout << "Введите количество членов последовательности" << endl;
	cin >> n;
	set <int> a; // последовательность целых чисел
	for (int i = 0; i < n; ++i) { // ввод чисел с консоли
		string h; cin >> h;
		int l = stoi(h); // перевод из string в int
		a.insert(l);
	}
	set <int> res; // резултирующее множество 
	print_int(a);
	for (auto it = a.begin(); it != a.end(); ++it) { // поиск двузначных и трехзначных чисел 
		if (*it > 10 && *it < 1000) {
			int b = *it;
			while (b) {
				res.insert(b % 10); 
				b /= 10; // записываем найденые цифры в множество
			}
		}
	}
	cout << "Итог" << endl;
	print_int(res);
}

void t2_8() {
	set <string> vopr, voskl, pov; // множества слов в разных предложениях
	string razd = "!?.";
	string str = "Солнце светит ярко!Солнце еще не взошло.Солнце уже взошло?";
	int pos = 0; // начало предложения
	while (pos < str.size()) {
		int k = str.find_first_of(razd, pos); // конец предложения 
		auto tp = str[k]; // сохраняем знак препинания
		k -= pos;
		string temp = str.substr(pos, k) + " "; // записываем предложение в новую переменную
		int pos1 = 0; // начало слова
		while (pos1 < temp.size()) {
			int k1 = temp.find_first_of(" ", pos1); // конец слова
			k1 -= pos1;
			string word = temp.substr(pos1, k1); // записываем слово в новую переменную
			transform(word.begin(), word.end(), word.begin(), tolower); // перевод в нижний регистр
			if (tp == '.') pov.insert(word);
			if (tp == '!') voskl.insert(word);
			if (tp == '?') vopr.insert(word);
			pos1 += k1 + 1; // обновляем начало слова
		}
		pos += k + 1; // обновляем начало предложения
		print_str(pov);
		print_str(voskl);
		print_str(vopr);
		vector <string> res;
		set_intersection(pov.begin(), pov.end(), voskl.begin(), voskl.end(), inserter(res, res.begin())); // пересечение множеств
		for (auto it = res.begin(); it != res.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		cout << res.size();
	}
}

void t2_14() {
	ifstream file;
	file.open("C:\\Users\\egor6\\source\\repos\\dz\\14.txt"); // открываем файл
	cout << "Ведите число k" << endl;
	int k; cin >> k;
	map <string, int> let, num;
	string s, nums = "0123456789", firstWord;
	while (file >> s) { // считываем каждое слово файла
		int l = s.find_first_not_of(nums); // ищем в слове первый символ, не являющийся цифрой
		if (s.find_first_not_of(nums) == string::npos) num[s]++; // если все символы - это цифры то записываем число в отображение с цифрами
		else {
			if (let.size() == 0) {
				firstWord == s;
			}
			let[s]++; // а иначе записываем в отображение со словами
		}
	}
	cout << "Числа, встречающиеся " << k << " раз" << endl;
	for (auto it = num.begin(); it != num.end(); ++it) {
		if (it->second == k) { // находим то число, которое встречается k раз
			cout << it->first << endl; // выводим его на экран
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите номер задания" << endl;
	cin >> n;
	if (n == 1) t2_4();
	if (n == 2) t2_8();
	if (n == 3) t2_14();
	return 0;
}