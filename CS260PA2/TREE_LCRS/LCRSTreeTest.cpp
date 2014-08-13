#include <vector>
#include <iostream>
using namespace std;

#include "LCRSTree.h"

template<typename T>
LCRSTree<T> createFullTree(T&, int, lcrs_node<T>*, lcrs_cursor*);

int main()
{
	lcrs_node<int> cellspace[1000];
	lcrs_cursor cavail = 1;

	int height = 3, rootval = 0;
	LCRSTree<int> tree = createFullTree(rootval, height, cellspace,&cavail);
	tree.PRINTTREE(tree.ROOT(), "", false);




	return 0;
}

template<typename T>
LCRSTree<T> createFullTree(T& rootval, int height, lcrs_node<T>* cs, lcrs_cursor* cavailp)
{
	LCRSTree<int> t1(cs, cavailp);
	LCRSTree<int> t2(cs,cavailp);
	LCRSTree<int> t3(cs, cavailp);
	if (height == 1)
	{
		int oldroot = rootval;
		t1.CREATE0(++rootval);
		t2.CREATE0(++rootval);
		t3.CREATE0(++rootval);
		t1.CREATE3(oldroot, t2, t3);
	}
	else if (height > 1)
	{
		int oldroot = rootval;
		t1 = createFullTree(++rootval, height-1, cs, cavailp);
		t2 = createFullTree(++rootval, height-1, cs, cavailp);
		t3 = createFullTree(++rootval, height-1, cs, cavailp);

		t1.CREATE3(oldroot, t2, t3);
	}
	return t1;
}
