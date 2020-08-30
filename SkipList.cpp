/*
skiplist by Elvis YUAN

*/


#include "SkipList.h"
#include<iostream>
#include<ctime>

using namespace std;
skiplist::skiplist() {
	head = new skipnode(INT_MIN);
	tail = new skipnode(INT_MAX);
	for (int i = 0;i <maxLevel;++i) {
		head->next.push_back(tail);
	}
	srand(time(0));
}
skiplist::~skiplist() {
	delete head;
	delete tail;
}
void skiplist::insert(int k) {
	if (find(k)) {
		cout << k << "is existed" << endl;
		return;
	}
	int level = getRandomLevel();// get[0,15]
	skipnode* pre = head;
	skipnode* cur;
	for (int i = maxLevel - 1;i > level;--i) {// find the largest value which is less than k in level+1; time cost:O(logn) 
		cur = pre->next[i];
		while (cur != tail && cur->val < k) {
			pre = cur;
			cur = cur->next[i];
		}
	}
	skipnode* sn = new skipnode(k, level);
	
	for (int i = level;i >= 0;--i) {
		cur = pre;
		while (cur != tail && cur->val < k) {
			pre = cur;
			cur = cur->next[i];
		}
		sn->next[i] = pre->next[i];
		pre->next[i] = sn;
		cout << k << "has been inserted in level " << i << endl;
	}
	cout << k << "has been inserted from 0 to " << level <<" levels"<< endl;
}
bool skiplist::find(int k) {
	skipnode* pre = head;
	skipnode* cur;
	for (int i = maxLevel - 1;i >= 0;--i) {
		cur = pre->next[i];
		while (cur != tail) {
			if (cur->val == k) {
				cout << k << "has been found" << endl;
				return true;
			}
			else if (cur->val < k) {
				pre = cur;
				cur = cur->next[i];
			}
			else break;
		}

	}
	cout<<  k << "does not exist" << endl;
	return false;
}
void skiplist::remove(int k) {
	if (!find(k)) {
		return;
	}
	skipnode* pre = head;
	skipnode* cur;
	for (int i = maxLevel - 1;i >= 0;--i) {
		cur = pre->next[i];
		while (cur != tail) {
			if (cur->val == k) {
				pre->next[i] = cur->next[i];
				break;
			}
			else if (cur->val < k) {
				pre = cur;
				cur = cur->next[i];
			}
			else break;
		}
	}
	cout << k << "has been removed" << endl;
}
void skiplist::printAll() {
	skipnode* cur = head;
	for (int i = maxLevel-1;i >=0;--i) {
		cur = head->next[i];
		while (cur != tail) {
			cout << cur->val<<" ";
			cur = cur->next[i];
		}
		cout << endl;
	}
}
int skiplist::getRandomLevel() {//return a random number in [0,15]
	int r = 0;
	while (r < maxLevel&&rand()%2==1) {
		r++;
	}
	return r;
}