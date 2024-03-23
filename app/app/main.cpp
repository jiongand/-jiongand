#include"mmm.h"
#include"checker.h"
//int argc, char* argv[]
int main() {
	/*random_device g;
	mt19937_64 gen(g());
	uniform_int_distribution<> display(1, 4);*/
	/*for (int i = 0; i < 5; i++) {
		cout << display(gen)  << endl;
	}*/
	/*if (argc != 5) {
		cout << "输入参数不正确" << endl;
		return -1;
	}
	checker check;
	mmm t;
	char* g = nullptr, *v = nullptr;
	for (int i = 1; i < argc; i+=2) {
		if (argv[i] == "-r") {
			t.set_MaxNumber(atoi(argv[i+1]));
		}
		if (argv[i] == "-n") {
			t.set_MaxTree(atoi(argv[i+1]));
		}
		if (argv[i] == "-e") {
			g = argv[i];
		}
		if (argv[i] == "-a") {
			v = argv[i];
		}
	}
	if (g != nullptr&&v != nullptr) {
		check.compare(g, v, "Grade.txt");
		return 0;
	}*/
	mmm t;
	cout<<t.answer("2'1/2×2'1/2");

	/*t.full_create();
	const char *a = "Exercises.txt";
	const char *anser = "Answers.txt";
	t.write(a);
	t.write_ans(anser);
	cout << t.show_tree() << endl;*/
	return 0;
}