#include "B_Tree.h"

B_Tree::~B_Tree()
{
	delete_(root);
}

B_Tree::B_Tree()
{
	root = new Node;
	root->left = nullptr;
	root->right = nullptr;
}

B_Tree::B_Tree(string & a)
{
	B_Tree();
	root->a = a;
}

bool B_Tree::insert(string& b)
{
	Node*a = create(b);
	if (!a)return false;
	Node*c = nullptr;
	vector<Node*> temp;
	temp.push_back(root);
	while (!temp.empty()) {
		c = temp.back();
		if (c->left == nullptr) {
			c->left = a;
			break;
		}
		else if (c->right == nullptr) {
			c->right = a;
			break;
		}
		else {
			temp.push_back(c->left);
			temp.push_back(c->right);
		}

	}
	return true;
}

Node* B_Tree::create(string & a)
{
	if (!root)return nullptr;
	Node* temp = new Node;
	if (!temp)return nullptr;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->a = a;
	return temp;
}


bool B_Tree::delete_(Node*&a)
{
	if (!a)return true;
	delete_(a->left);
	delete_(a->right);
	delete a;
	return true;
}
