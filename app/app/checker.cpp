#include "checker.h"

string checker::change(const string & nnn)
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

string checker::re_change(const string & nnn)
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
	ppp = to_string(k) + "\'" + to_string(z) + "/" + to_string(m_p);
	return ppp;
}

string checker::jisuan(const string & num1, const string & num2, const string & symbol)
{
	string n1 = change(num1);
	string n2 = change(num2);
	int f = 0;
	//直接将n1和n2分母规格化（两者为整型时一为分母）,然后统一计算，除了除法要复杂些
	if (n1.find('/') == string::npos&&n2.find('/') == string::npos) {
		f = 1;
	}
	int z1 = 0, z2 = 0, m1 = 1, m2 = 1;
	string t;
	if (n1.find('/') == string::npos) {
		z1 = atoi(n1.c_str());
	}
	else
		for (size_t i = 0; i < n1.size() && !f; ++i) {
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
	}
	else
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
			string g = to_string(atoi(n1.c_str()) + atoi(n2.c_str()));
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

void checker::minCommonMultiple(int & a, int & b)
{
	int c = maxCommonDicisor(a, b);
	a /= c;
	b /= c;
}

int checker::maxCommonDicisor(int a, int b)
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

string checker::answer(const string & ppp)
{
	string kk;
	string sum("0");
	vector<string> n;
	vector<string> s;
	size_t i = 0;
	while (ppp[i] != '.') {
		++i;
	}
	++i;
	for (; i < ppp.size()-1; ++i) {
		string tttt;
		while ((ppp[i] < '0' || ppp[i]>'9') && ppp[i] != '+'&&ppp[i] != '-'&&ppp[i] != '\''&&ppp[i] != '/') {
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
					if (ppp[i - 1] == '+' || ppp[i - 1] == '-') {
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
			string t = jisuan(s[s.size() - 2], s[s.size() - 1], am);
			s.pop_back(); s.pop_back();
			s.push_back(t);
			continue;
		}
		s.push_back(am);
	}
	return s[0];
}

void checker::compare(const char * e, const char * a, const char * p)
{
	ifstream ex(e), an(a);
	ofstream pi(p);
	if (!(ex.is_open() && an.is_open() && pi.is_open())) {
		cout << "文件打开异常" << endl;
		ex.close(); an.close(); pi.close();
		return;
	}
	char k[100],b[100];
	int index = 1;
	while (ex.tellg() != EOF && an.tellg() != EOF) {
		ex.getline(k, 100);
		an.getline(b, 100);
		string t = b;
		if (t.empty())break;
		while (*t.begin() != '.') {
			t.erase(t.begin());
		}
		t.erase(t.begin());

		if (t==answer(k)) {
			c.push_back(index);
		}
		else {
			w.push_back(index);
		}
		++index;
	}
	pi << "Correct:" << c.size() << "(";
	for (auto ggg : c) {
		pi << ggg << ",";
	}
	pi << ")" << endl;
	pi << "Wrong:" << w.size() << "(";
	for (auto ggg : w) {
		pi << ggg << ",";
	}
	pi << ")" << endl;
	ex.close(); an.close(); pi.close();
}
