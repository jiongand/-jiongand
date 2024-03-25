#ifndef MMM
#define MMM
#include"B_Tree.h"
#include<random>
class mmm
{
	vector<B_Tree> forest;
	vector<string> ans_;
	int max_Tree;
	int max_Number;
	int now_Tree;
	void minCommonMultiple(int& a,int& b);//最小公倍数
	int maxCommonDicisor(int a,int b);//最大公约数
	bool if_same(Node*t1,Node*t2);
	bool if_symmetry(Node*t1,Node*t2);
	bool test();
public:
	mmm(int t,int n);string answer(const string& ppp);
	mmm();
	~mmm();
	bool createTree();
	void full_create();
	string generalSymbol();//生成四则运算符
	string generalNumber();//生成数字
	string change(const string&nnn);
	string re_change(const string&nnn);
	string jisuan(const string &num1,const string &num2,const string &symbol);
	string show_tree();
	bool write(const char* tar);//写入文档
	bool write_ans(const char* ans);//写入答案
	void set_MaxTree(int a);
	void set_MaxNumber(int a);
};
#endif
