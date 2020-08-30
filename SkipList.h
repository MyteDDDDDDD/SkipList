#pragma once
#include<vector>
using namespace std;
class  skiplist
{
private:
	struct skipnode
	{
		int val;
		vector<skipnode*> next;
		skipnode(int v) :val(v) {}
		skipnode(int v, int l) :val(v) {
			next.resize(l+1,nullptr);
		}
		skipnode() {}
	};

public:
	 skiplist();
	~ skiplist();
	void insert(int);
	bool find(int);
	void remove(int);
	void printAll();
private:
	skipnode* head;
	skipnode* tail;
	const int maxLevel = 16;
	int getRandomLevel();

	
};



