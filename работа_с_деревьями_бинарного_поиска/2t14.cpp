#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
ifstream in("input.txt");
struct tree {
	int inf;
	tree * right;
	tree* left;
};
tree* node(int x) {
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	return n;
}
void create(tree*& tr, int n) {
	int x;
	if (n > 0) {
		in >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}
void preorder(tree* tr) {

	if (tr) {
		cout << tr->inf << " ";
		preorder(tr->left);
		preorder(tr->right);
	}
}
int lefth(tree* tr) {
	int k = 0;
	tree* x = tr;
	while (x) {
		k++;
		x = x->left;
	}
	return k - 1;
}
int righth(tree* tr) {
	int k = 0;
	tree* x = tr;
	while (x) {
		k++;
		x = x->right;
	}
	return k - 1;
}
void add(tree*& tr, int x) {
	tree* n = node(x);
	tree* y = tr;
	if (lefth(tr) == righth(tr)) {
		do {
			y = y->left;
		} while (y->left);
		if (!y->left) y->left = n;
		else y->right = n;
	}
	else {
		do {
			y = y->right;
		} while (y->right);
		if (!y->left) y->left = n;
		else y->right = n;
	}

}
void find(tree* tr, int x, tree*& res) {
	if (tr) {
		if (tr->inf == x) {
			res = tr;
		}
		else {
			find(tr->left, x, res);
			find(tr->right, x, res);
		}
	}
}
void del_n(tree* tr, int val) {
	tree* y;
	find(tr, val, y);
	if (y) {
		if (lefth(tr) == 0) tr = NULL;

		else if (lefth(tr) != righth(tr)) {
			tree* x = tr->left;
			do {
				x = x->left;
			} while (x->left->left);
			if (x->right) {
				if (x->right->inf == val) {
					x->right = NULL;
				}
				else {
					y->inf = x->right->inf;
					x->right = NULL;
				}
				delete x->right;
			}
			else {
				if (x->left->inf == val) {
					x->left = NULL;
				}
				else {
					y->inf = x->left->inf;
					x->left = NULL;
				}
				delete x->left;
			}
		}
		else {
			tree* x = tr->right;
			do {
				x = x->right;
			} while (x->right->right);
			if (x->right) {
				if (x->right->inf == val) {
					x->right = NULL;
				}
				else {
					y->inf = x->right->inf;
					x->right = NULL;

				}
				delete x->right;
			}
			else {
				if (x->left->inf == val) {
					x->left = NULL;
				}
				else {
					y->inf = x->left->inf;
					x->left = NULL;
				}
				delete x->left;
			}
		}
	}

}
void print(tree* tr, int k) {
	if (!tr) cout << "Empty tree\n"; // если дерево пустое, выводим сообщение об этом
	else { // если дерево не пустое, начинаем выводить его содержимое по уровням
		queue<tree*> cur, next; // создаем две очереди для текущих и следующих уровней дерева
		tree* r = tr;
		cur.push(r); // помещаем корень дерева в очередь текущих узлов
		int j = 0; // номер узла на уровне, начиная с 0
		while (cur.size()) { // пока текущая очередь не пуста
			if (j == 0) { // если текущий узел - первый на уровне
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
					cout << ' '; // выводим пробелы перед узлом, чтобы выровнять дерево
			}
			tree* buf = cur.front(); // сохраняем текущий узел в буфер
			cur.pop(); // удаляем текущий узел из очереди текущих узлов
			j++; // увеличиваем номер текущего узла на уровне
			if (buf) { // если текущий узел не пустой
				cout << buf->inf; // выводим содержимое текущего узла
				next.push(buf->left); // сохраняем левого потомка текущего узла в очередь следующих узлов
				next.push(buf->right); // сохраняем правого потомка текущего узла в очередь следующих узлов
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' '; // выводим пробелы после узла, чтобы выровнять дерево
			}

			if (!buf) { // если текущий узел пустой
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' '; // выводим пробелы после узла и еще один пробел, чтобы выровнять дерево
				cout << ' ';
			}
			if (cur.empty()) { // если текущая очередь пуста
				cout << endl; // переходим на новую строку
				swap(cur, next); // меняем местами очереди текущих и следующих узлов
				j = 0; // сбрасываем номер текущего узла на уровне
				k--; // уменьшаем уровень дерева
			}
		}
	}
}

int sumOfLeaves(tree* tr) {
	if (tr == NULL) return 0; //если дерево пустое, сумма равна 0
	if (tr->left == NULL && tr->right == NULL) return tr->inf; //если узел является листом, возвращаем его значение
	return sumOfLeaves(tr->left) + sumOfLeaves(tr->right); //рекурсивно вызываем функцию для левого и правого поддеревьев и складываем результаты
}

int main() {
	setlocale(LC_ALL, "Russian");
	tree* tr = NULL;
	int n, x;
	in >> n;
	create(tr, n);
	int k = int(log((float)n) / log((float)2.0));
	print(tr, k);
	preorder(tr);
	cout << endl;
	cout << "Сумма листьев: " << sumOfLeaves(tr) << endl; //подсчитываем сумму листьев и выводим ее на экран
	return 0;
}