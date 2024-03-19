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
	~B_Tree();	
	bool delete_(Node*&a);
	Node* create(string& a);
public:
	B_Tree();
	B_Tree(string& a);
	bool insert(string& a);

};
#endif

