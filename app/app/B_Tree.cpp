#include "B_Tree.h"

B_Tree::~B_Tree()
{
	//delete_(root);
}

B_Tree::B_Tree()
{
	root = new Node;
	sum = 0;
	root->left = nullptr;
	root->right = nullptr;
}

B_Tree::B_Tree(string & a)
{
	B_Tree();
	root->a = a;
}

bool B_Tree::insert(string&& b)
{
	if (root->a.empty()) {
		root->a = b;
		sum++;
		return true;
	}
	Node*a = create(b);
	if (!a)return false;
	Node*c = nullptr;
	vector<Node*> temp;
	temp.push_back(root);
	while (!temp.empty()) {
		c = *(temp.begin());
		temp.erase(temp.begin());
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
	++sum;
	return true;
}

bool B_Tree::clear()
{
	return delete_(root);
}

size_t B_Tree::getSum()
{
	return sum;
}

string B_Tree::check()
{
	return check(root);
}

Node * B_Tree::get_Root()
{
	return root;
}

Node* B_Tree::create(string a)
{
	if (!root)return nullptr;
	Node* temp = new Node;
	if (!temp)return nullptr;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->a = a;
	return temp;
}

string B_Tree::check(Node * a)
{
	if (a == nullptr) {
		return string();
	}
	string t;
	t = t + check(a->left);
	t = t + a->a;
	t = t + check(a->right);
	return t;
}


bool B_Tree::delete_(Node*&a)
{
	if (a==nullptr)return true;
	bool f = delete_(a->left);
	bool g = delete_(a->right);
	a->left = nullptr;
	a->right = nullptr;
	delete a;
	a = nullptr;
	return true;
}
