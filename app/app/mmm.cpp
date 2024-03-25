#include "mmm.h"

void mmm::minCommonMultiple(int & a, int & b)
{
	int c = maxCommonDicisor(a, b);
	a /= c;
	b /= c;
}

int mmm::maxCommonDicisor(int a, int b)
{
	if (a == 0 || b == 0) {
		return 0;
	}
	a = abs(a); b = abs(b);
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else if (a < b) {
			b = b - a;
		}
	}
	return a;
}

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

string mmm::answer(const string& ppp)
{
	string kk;
	string sum("0");
	vector<string> n;
	vector<string> s;
	for (size_t i = 0;i<ppp.size();++i) {
		string tttt;
		while ((ppp[i] < '0'||ppp[i]>'9') && ppp[i] != '+'&&ppp[i] != '-'&&ppp[i]!='\''&&ppp[i]!='/') {
			tttt.push_back(ppp[i++]);
		}
		if (ppp[i] == '+' || ppp[i] == '-' || tttt == "÷" || tttt == "×") {
			n.push_back(kk);
			kk.clear();
			string t;
			if (ppp[i] == '+' || ppp[i] == '-') {
				t.push_back(ppp[i++]);
			}
			else {
				t = tttt;
			}
			if (!s.empty()) {
				if (s.back() == "÷" || s.back() == "×") {
					if (ppp[i-1] == '+' || ppp[i-1] == '-') {
						for (int in = s.size() - 1; in >= 0; --in) {
							n.push_back(s[in]);
						}
						s.clear();
					}
				}
			}
			s.push_back(t);
		}
			kk.push_back(ppp[i]);
	}
	n.push_back(kk);
	for (int i = s.size() - 1; i >= 0; --i) {
		n.push_back(s[i]);
	}
	s.clear();
	for (auto am : n) {
		if (am == "+" || am == "-" || am == "÷" || am == "×") {
			string t = jisuan(s[s.size()-2],s[s.size()-1],am);
			s.pop_back(); s.pop_back();
			s.push_back(t);
			continue;
		}
		s.push_back(am);
	}
	return s[0];
}

bool mmm::test()
{
	if (forest.size()<=1)return true;
	B_Tree& temp = forest.back();
	for (int i = forest.size() - 2; i > 0; --i) {
		bool s = if_same(temp.get_Root(),forest[i].get_Root());
		if (s || if_symmetry(temp.get_Root(), forest[i].get_Root())) {
			return false;
		}
	}return true;
	
}

mmm::mmm(int t = -1, int n = -1)
{
	max_Tree = t;
	max_Number = n;
	now_Tree = 0;
}

mmm::mmm()
{
	max_Tree = -1;
	max_Number = -1;
}

mmm::~mmm()
{
	while (!forest.empty()) {
		forest.back().clear();
		forest.pop_back();
	}
}

bool mmm::createTree()
{
	random_device g;
	mt19937_64 gen(g());
	uniform_int_distribution<> display(1, 3);
	int i;
	i = display(gen);
	// = display(gen);
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



void mmm::full_create()
{
	if (max_Number == -1 || max_Tree == -1)return;
	while (now_Tree < max_Tree) {
		createTree();//这里还差个重复性检测
		string ggg = answer(forest.back().check());
		if (!test()||ggg.find('-')!=string::npos) {
			forest.back().clear();
			forest.pop_back();
			continue;
		}
		++now_Tree;
		ans_.push_back(ggg);
	}
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
			minCommonMultiple(a, b);
			t = t + to_string(a) + "/" + to_string(b);
		}
		else if(a==b) {
			t = "1";
		}
		else {
			int k = a / b;
			a -= b*k;
			if (a == 0) {
				t = to_string(k);
			}
			else {
				minCommonMultiple(a, b);
				t = t+to_string(k)+"'"+to_string(a) + "/" + to_string(b);
			}
		}
	}
	return t;
}

string mmm::change(const string & nnn)
{
	if (nnn.find('\'') == string::npos)return nnn;
	string ppp;
	int m_p = 1;
	int m = 0;
	int z = 0;
	for (size_t i = 0; i < nnn.size(); ++i) {
		if (nnn[i] == '\'') {
			m_p = atoi(ppp.c_str());
			ppp.clear();
			++i;
		}
		if (nnn[i] == '/') {
			m = atoi(ppp.c_str());
			ppp.clear();
			++i;
		}
		ppp.push_back(nnn[i]);
	}
	z = atoi(ppp.c_str());
	m += z * m_p;
	ppp.clear();
	ppp = ppp + to_string(m) + "/" + to_string(z);
	return ppp;
}

string mmm::re_change(const string & nnn)
{
	if (nnn.find('/') == string::npos)return nnn;
	if (nnn.find('\'') != string::npos)return nnn;
	string ppp;
	int m_p = 0;
	int z = 0;
	for (size_t i = 0; i < nnn.size(); ++i) {
		if (nnn[i] == '/') {
			z = atoi(ppp.c_str());
			ppp.clear();
			++i;
		}
		ppp.push_back(nnn[i]);
	}
	m_p = atoi(ppp.c_str());
	int k = z / m_p;
	if (k <= 0) {
		return nnn;
	}
	z -= k * m_p;
	ppp.clear();
	if (z == 0) {
		return string(to_string(k));
	}
	ppp = to_string(k) + "\'" + to_string(z) +"/"+ to_string(m_p);
	return ppp;
}

string mmm::jisuan(const string & num1, const string & num2, const string & symbol)
{
	string n1 = change(num1);
	string n2 = change(num2);
	int f = 0;
	//直接将n1和n2分母规格化（两者为整型时一为分母）,然后统一计算，除了除法要复杂些
	if (n1.find('/') == string::npos&&n2.find('/')==string::npos) {
		f = 1;
	}
	int z1 = 0, z2 = 0, m1 = 1, m2 = 1;
	string t;
	if (n1.find('/') == string::npos) {
		z1 = atoi(n1.c_str());
	}
	else
	for (size_t i = 0; i < n1.size()&&!f; ++i) {
		if (n1[i] == '/') {
			z1 = atoi(t.c_str());
			t.clear();
			++i;
		}
		t.push_back(n1[i]);
	}
	if (!t.empty()) {
		m1 = atoi(t.c_str());
		t.clear();
	}
	if (n2.find('/') == string::npos) {
		z2 = atoi(n2.c_str());
	}else
	for (size_t i = 0; i < n2.size() && !f; ++i) {
		if (n2[i] == '/') {
			z2 = atoi(t.c_str());
			t.clear();
			++i;
		}
		t.push_back(n2[i]);
	}
	if (!t.empty()) {
		m2 = atoi(t.c_str());
		t.clear();
	}
	
	z1 *= m2; z2 *= m1;
	if (symbol == "+") {
		if (f) {
			string g = to_string(atoi(n1.c_str())+atoi(n2.c_str()));
			return g;
		}
		int z3 = z1 + z2; int m3 = m1 * m2;
		minCommonMultiple(z3, m3);
		string g = to_string(z3) + "/" + to_string(m3);
		g = re_change(g);
		return g;
	}
	else if (symbol == "-") {
		if (f) {
			string g = to_string(atoi(n1.c_str()) - atoi(n2.c_str()));
			return g;
		}
		int z3 = z1 - z2; int m3 = m1 * m2;
		if (z3 == 0) {
			return string("0");
		}
		else if (z3 < 0) {
			return string("-1");
		}
		minCommonMultiple(z3, m3);
		string g = to_string(z3) + "/" + to_string(m3);
		g = re_change(g);
		return g;
	}
	else if (symbol == "×") {
		if (f) {
			string g = to_string(atoi(n1.c_str()) * atoi(n2.c_str()));
			return g;
		}int z3 = z1 * z2; int m3 = m1 * m2;
		m3 *= m3;
		minCommonMultiple(z3, m3);
		string g;
		if (m3 == 1) {
			g = to_string(z3);
		}
		else {
			g = to_string(z3) + "/" + to_string(m3);
			g = re_change(g);
		}
		return g;
	}
	else {
		if (f) {
		int a = atoi(n1.c_str()); int b = atoi(n2.c_str());
		string g;
		minCommonMultiple(a, b);
		g = to_string(a) + "/" + to_string(b);
		g = re_change(g);
		return g;
		}minCommonMultiple(z1, z2);
		string g;
		if (z2 == 1) {
			return string(to_string(z1));
		}
		g = to_string(z1) + "/" + to_string(z2);
		g = re_change(g);
		return g;
	}
	return string();
}

string mmm::show_tree()
{
	return forest.back().check();
}

bool mmm::write(const char* tar)
{
	if (max_Number == -1 || max_Tree == -1)return false;
	ofstream www(tar);
	if (!www.is_open()) {
		cout << "写入失败" << endl;
		return false;
	}
	int i = 1;
	for (auto t : forest) {
		www << i<<"."<<t.check()<<"="<<endl;
		++i;
	}
	return true;
}

bool mmm::write_ans(const char * ans)
{
	if (max_Number == -1 || max_Tree == -1)return false;
	ofstream www(ans);
	if (!www.is_open()) {
		cout << "写入失败" << endl;
		return false;
	}
	int i = 1;
	for (int j = i - 1; j < ans_.size(); ++j) {
		www << i << "." << ans_[j] << endl;
		++i;
	}
	return true;
}

void mmm::set_MaxTree(int a)
{
	max_Tree = a;
}

void mmm::set_MaxNumber(int a)
{
	max_Number = a;
}


