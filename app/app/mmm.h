#ifndef MMM
#define MMM
#include"B_Tree.h"
#include<random>
class mmm
{
	vector<B_Tree> forest;
	int max_Tree;
	int max_Number;
	int minCommonMultiple(int a,int b);//最小公倍数
	int maxCommonDicisor(int a,int b);//最大公约数
	bool if_same(Node*t1,Node*t2);
	bool if_symmetry(Node*t1,Node*t2);

public:
	mmm(int t,int n);
	~mmm();
	bool createTree(string& a);
	string generalSymbol();//生成四则运算符
	string generalNumber();//生成数字
	bool write(const char* tar);//写入文档
	bool write_ans(const char* ans);//写入答案
};
#endif
