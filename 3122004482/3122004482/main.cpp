#include "Check.h"

//
//
//"D:\\gg\\orig.txt","D:\\gg\\orig_0.8_add.txt","D:\\gg\\t.txt"
int main(int argc, char* argv[]) {
	system("chcp 65001");//由于txt文件默认utf-8编码，而windows中文的命令台默认gbk编码，故用该系统命令改为utf-8编码
	if (argc != 4) {
		std::cout << "输入不足或过多"<<std::endl;
		return -1;
	}
	Check ggg;
	ggg.check(argv[1],argv[2],argv[3]);
	return 0;
}