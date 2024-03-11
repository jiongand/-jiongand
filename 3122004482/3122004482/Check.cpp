#include "Check.h"

Check::Check() {
	same = 0; 
	total = 0;
}

Check::~Check() {

}

bool Check::check(const char* f, const char* c, const char* a)
{
	if (f == nullptr || c == nullptr || a == nullptr) {
		std::cout << "所需文件不存在。" << std::endl;
		return false;
	}
	std::ifstream sample,target;
	std::ofstream answer;
	sample.open(f, std::ios::in);
	target.open(c, std::ios::in);
	answer.open(a, std::ios::out);
	if (!(sample.is_open() && target.is_open() && answer.is_open())) {
		std::cout << "文件打开失败。" << std::endl;
		sample.close();
		target.close();
		answer.close();
		return false;
	}
	char* s = nullptr;
	while (sample.peek()!=EOF ) {
		s = new char[512];
		sample.getline(s, 512);
		load(s);
		delete[] s;
		s = nullptr;
	}
	while (target.peek()!=EOF) {
		s = new char[512];
		target.getline(s, 512);
		find(s);
		delete[] s;
		s = nullptr;
	}
	if (total == 0) {
		sample.close();
		target.close();
		answer.close();
		std::cout << "无内容";
		return false;
	}
	double ggg = ((double)same / total)*100;
	answer << "查重率："<<std::setiosflags(std::ios::fixed)<<std::setprecision(2)<<ggg <<'%'<< std::endl;
	sample.close();
	target.close();
	answer.close();
	return true;
}

void Check::load(const char * sample)
{
	for (int i = 0;sample[i]!='\0';i++) {
		if (!g.count(sample[i])) {
			g[sample[i]] = 1;
		}
		else { ++g[sample[i]]; }
	}
}

void Check::find(const char * a)
{
	for (int i = 0; a[i] != '\0'; i++) {
		++total;
		if (g.count(a[i])&&g[a[i]]) {
			++same;
			--g[a[i]];
		}
	}
}


