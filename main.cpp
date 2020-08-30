#include <iostream>
#include "SkipList.h"
using namespace std;

int main() {
	skiplist sk;
	
	sk.printAll();
	for (int i = 0;i < 20;++i) {
		sk.insert(i);
	}
	sk.printAll();

	sk.find(0);
	sk.find(9);
	sk.find(20);

	sk.insert(20);
	sk.find(20);

	sk.remove(20);
	sk.find(20);

	sk.remove(0);
	sk.remove(10);

	sk.printAll();

	
	return 0;


}