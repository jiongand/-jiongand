#ifndef MMM
#define MMM
#include"B_Tree.h"
#include<random>
class mmm
{
	vector<B_Tree> forest;
	int max_Tree;
	int max_Number;
	int minCommonMultiple(int a,int b);//��С������
	int maxCommonDicisor(int a,int b);//���Լ��
	bool if_same(Node*t1,Node*t2);
	bool if_symmetry(Node*t1,Node*t2);

public:
	mmm(int t,int n);
	~mmm();
	bool createTree(string& a);
	string generalSymbol();//�������������
	string generalNumber();//��������
	bool write(const char* tar);//д���ĵ�
	bool write_ans(const char* ans);//д���
};
#endif
