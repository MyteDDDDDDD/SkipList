SkipList
==
Editor: YUAN Zichun(Elvis)
Email: elvis_yuan@foxmail.com
Github:https://github.com/MyteDDDDDDD

SkipList is one kind of data structure. This SkipList based on C++ and VS2017.It uses up to 16 levels(0-15) to store elements with similar structure of balance tree. It takes time cost of O(logn) to insert,find and remove one node.
0 level of skiplist contains all the integers.
1 to 15 levels contains nodes used for searching.
Each node contains a unique integer and a vector contains pointers it leads to in each level.
*****
Interface
==
### skiplist()
build a skiplist with maximum levels(to be 16 here);

use a node *head* with INT_MIN value to mark the first pointer of each level;
use a node *tail* with INT_MAX value to mark the last pointer of each level;
### insert(int k)
insert an integer k into skiplist;

call getRandomLevel to get the levels need to be inserted in;
start pass from the head of maximum level , for each level we stop at the node with the largest integer which is less than k, and than use this pointer as the start poniter of next level, repeat these steps until the node we need to insert k.

### find(int k)
find if k exists in skiplist;
if does exist return true,else false;

pass from the maximum level to 0 level, for each level we stop at the node with the largest integer which is less than k, and than pass to the next lower level until we reach a larger integer than k in 0 level(return false) or we find the k(return true).

### remove(int k)
remove integer k from skiplist;

pass from the maximum level to 0 level, for each level we stop at the node with the largest integer which is less than k,and than use this pointer as the start poniter of next level, until we find k.Than retrict the pointer lead to k to k->next. Repeat this step until we retrict the node stored k in 0 level.
### printAll()
to print all in the nodes in skiplist

File List
===
* main.cpp

construction and test cases

* SkipList.h

interfaces and constructors

* SkipList.cpp


Performance
===
|  Function |Data size   |Time cost(s)  |
| ------------ | ------------ | ------------ |
|  insert() | 50  |0.01   	|
|  find()   | 50  |0.001  	|
|  remove() | 50  |0.002 	|
|insert()	|100	|	0.013|
|find()		|100	|	0.004|
|remove()	|100	|	0.015|

data from test cases in main.cpp


