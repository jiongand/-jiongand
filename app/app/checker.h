#ifndef CHECKER
#define CHECKER
#include<vector>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class checker
{
	vector<int> c;vector <int>w;
	string change(const string&nnn);
	string re_change(const string&nnn);
	string jisuan(const string &num1, const string &num2, const string &symbol);
	void minCommonMultiple(int& a, int& b);//��С������
	int maxCommonDicisor(int a, int b);//���Լ��
	string answer(const string& ppp);
public:
	void compare(const char*e,const char*a,const char*p);
};
#endif // !CHECKER



