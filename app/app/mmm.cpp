#include "mmm.h"

bool mmm::if_same(Node * t1, Node * t2)
{
	if (!t1 && !t2) {
		return true;
	}
	if (!t1 || !t2) {
		return false;
	}
	bool a = if_symmetry(t1->right, t2->right);
	bool b = if_symmetry(t1->left, t2->left);
	if (a&&b&&t1->a == t2->a)
		return true;
	else return false;
}

bool mmm::if_symmetry(Node * t1, Node * t2)
{
	if (!t1 && !t2) {
		return true;
	}
	if (!t1 || !t2) {
		return false;
	}
	bool a = if_symmetry(t1->left, t2->right);
	bool b = if_symmetry(t1->right, t2->left);
	if (a&&b&&t1->a == t2->a)
		return true;
	else return false;
}

mmm::mmm(int t = 0, int n = 0)
{
	max_Tree = t;
	max_Number = n;

}

mmm::~mmm()
{
	while (!forest.empty()) {
		forest.back().clear();
		forest.pop_back();
	}
}

bool mmm::createTree(string & a)
{
	random_device g;
	mt19937_64 gen(g());
	uniform_int_distribution<> display(1, 3);
	int i = display(gen);
	B_Tree temp;
	for (int j = i; j > 0; --j) {
		temp.insert(generalSymbol());
	}
	for (int j = i+1; j > 0; --j) {
		temp.insert(generalNumber());
	}
	forest.push_back(temp);
	return true;
}

string mmm::generalSymbol()
{
	random_device g;
	mt19937_64 gen(g());
	uniform_int_distribution<> display(1, 4);
	string t;
	int f = display(gen);
	if (f == 1) {
		t = "+";
	}
	else if (f == 2) {
		t = "-";
	}
	else if (f == 3) {
		t = "×";
	}
	else {
		t = "÷";
	}
	return t;
}

string mmm::generalNumber()
{
	string t;
	random_device g;
	mt19937_64 gen(g());
	uniform_int_distribution<> display(1, 2);
	uniform_int_distribution<> display1(1, max_Number);
	int f = display(gen);
	if (f == 1) {
		t = to_string(display1(gen));
	}
	else {
		int a = display1(gen);
		int b = display1(gen);
		if (a < b) {
			t = t + to_string(a) + "/" + to_string(b);
		}
		else if(a==b) {
			t = "1";
		}
		else {
			int k = a / b;
			a -= b*k;
			t = t+to_string(k)+"'"+to_string(a) + "/" + to_string(b);
		}
	}
	return t;
}

bool mmm::write(const char* tar)
{
	ofstream www(tar);
	if (!www.is_open()) {
		cout << "写入失败" << endl;
		return false;
	}
	for (auto t : forest) {
		www << t.check()<<"\t";
	}
	return true;
}

bool mmm::write_ans(const char * ans)
{
	ofstream www(ans);
	if (!www.is_open()) {
		cout << "写入失败" << endl;
		return false;
	}
	for (auto t : forest) {
		//很烦，这里要写一个计算自己算式的函数，而如何把字符串式子转化为运算又是难题
		www << t.check() << "\t";
	}
	return true;
}


