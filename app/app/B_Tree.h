#ifndef B_TREE
#define B_TREE
#include<string>
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
struct Node
{
	struct Node *left;
	struct Node* right;
	string a;
};

typedef struct Node Node;

class B_Tree
{
	Node* root;
	size_t sum;
	bool delete_(Node*&a);
	Node* create(string a);
	string check(Node*a);
public:
	B_Tree();~B_Tree();
	B_Tree(string& a);
	bool insert(string&& a);
	bool clear();
	size_t getSum();
	string check();
};
#endif

