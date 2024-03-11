#include "Check.h"

//
//
//"D:\\gg\\orig.txt","D:\\gg\\orig_0.8_add.txt","D:\\gg\\t.txt"
int main(int argc, char* argv[]) {
	system("chcp 65001");
	if (argc != 4) {
		std::cout << "输入不足";
		return -1;
	}
	Check ggg;
	ggg.check(argv[1],argv[2],argv[3]);
	return 0;
}