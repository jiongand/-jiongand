#include"mmm.h"

int main(int argc, char* argv[]) {
	random_device g;
	mt19937_64 gen(g());
	uniform_int_distribution<> display(1, 4);
	/*for (int i = 0; i < 5; i++) {
		cout << display(gen)  << endl;
	}*/
}