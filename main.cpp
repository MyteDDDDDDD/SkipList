#include <iostream>
#include "SkipList.h"
#include<time.h>
using namespace std;

int main() {
	skiplist sk;
	
	for (int i = 0;i < 50;++i) {// build a skiplist with 50 integers
		sk.insert(rand());
	}
	sk.printAll();

	clock_t start, end;
	//test time cost with size of 50
	start = clock();
	sk.insert(100);
	end = clock();
	cout << "it takes "<<double(end - start)/CLOCKS_PER_SEC << " seconds to insert an integer" << endl;

	start = clock();
	sk.find(100);
	end = clock();
	cout << "it takes " << double(end - start) / CLOCKS_PER_SEC << " seconds to find an integer" << endl;

	start = clock();
	sk.remove(100);
	end = clock();
	cout << "it takes " << double(end - start) / CLOCKS_PER_SEC << " seconds to remvoe an integer" << endl;

	for (int i = 0;i < 50;++i) {//insert 50 more nodes
		sk.insert(rand());
	}
	start = clock();
	sk.insert(100);
	end = clock();
	cout << "it takes "<<double(end - start)/CLOCKS_PER_SEC << " seconds to insert an integer" << endl;

	start = clock();
	sk.find(100);
	end = clock();
	cout << "it takes " << double(end - start) / CLOCKS_PER_SEC << " seconds to find an integer" << endl;

	start = clock();
	sk.remove(100);
	end = clock();
	cout << "it takes " << double(end - start) / CLOCKS_PER_SEC << " seconds to remvoe an integer" << endl;

	return 0;


}
