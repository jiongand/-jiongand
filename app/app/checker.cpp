#include "checker.h"

void checker::compare(const char * e, const char * a, const char * p)
{
	ifstream ex(e), an(a);
	ofstream pi(p);
	if (!(ex.is_open() && an.is_open() && pi.is_open())) {
		cout << "文件打开异常" << endl;
		ex.close(); an.close(); pi.close();
		return;
	}
	char k[20],b[20];
	int index = 1;
	while (ex.tellg() != EOF && an.tellg() != EOF) {
		ex.getline(k, 20);
		an.getline(b, 20);
		if (!strcmp(k, b)) {
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
