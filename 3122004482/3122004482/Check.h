#ifndef CHECK
#define CHECK
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <unordered_map>

class Check
{
	int same;//重复字个数
	std::unordered_map<char,int> g;
	int total;//总字数
	void load(const char* a);//将原文载入哈希表
	void find(const char* a);//把目标文章与原文章进行比对
public:
	Check();~Check();
	bool check(const char* f, const char* c, const char* a);//处理输入的文件路径，进行文件流操作
};
#endif

