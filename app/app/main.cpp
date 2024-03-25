#include"mmm.h"
#include"checker.h"
//
int main(int argc, char* argv[]) {
	if (argc != 5) {
		cout << "输入参数不正确" << endl;
		return -1;
	}
	mmm t;
	char* g = nullptr, *v = nullptr;
	for (int i = 1; i < argc; i+=2) {
		string ggg = argv[i];
		string ppp = argv[i + 1];
		if (ggg == "-r") {
			if(atoi(ppp.c_str())>0)
			t.set_MaxNumber(atoi(ppp.c_str()));
			else {
				cout << "错误输入" << endl;
				return -1;
			}
		}
		if (ggg == "-n") {
			if (atoi(ppp.c_str()) > 0)
			t.set_MaxTree(atoi(ppp.c_str()));
			else {
				cout << "错误输入" << endl;
				return -1;
			}
		}
		if (ggg == "-e") {
			g = argv[i+1];
		}
		if (ggg == "-a") {
			v = argv[i+1];
		}
	}
	if (g != nullptr&&v != nullptr) {
		checker check;
		check.compare(g, v, "Grade.txt");
		return 0;
	}
	t.full_create();
	t.write("Exercises.txt");
	t.write_ans("Answers.txt");
	return 0;
}