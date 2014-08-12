#include <vector>
#include <iostream>
using namespace std;

#include "LOCTree.h"

template<typename T>
LOCTree<T> createFullTree(T&, int);

int main()
{
	tnode<int> nodespace[1000];
	tcell cellspace[1000];
	ns_cursor navail = 1;
	cs_cursor cavail = 1;

	LOCTree<int> tree1(nodespace, cellspace, &navail, &cavail);
	LOCTree<int> tree2(nodespace, cellspace, &navail, &cavail);
	LOCTree<int> tree3(nodespace, cellspace, &navail, &cavail);
	tree1.CREATE0(2);
	tree2.CREATE0(3);
	tree3.CREATE0(4);
	tree1.CREATE3(1, tree2, tree3);
	//tree1.PRINTTREE(tree1.ROOT(), "", false);
	//tree1.CREATE3(1, tree2, tree3);
	//tree1.PRINTTREE(tree1.ROOT(), "", false);




	return 0;
}

template<typename T>
LOCTree<T> createFullTree( T & rootval, int height)
{
	cout << "Height: " << height << endl;
	LOCTree<T> t1, t2, t3;
	if (height == 1)
	{
		t1.CREATE0(++rootval);
		t2.CREATE0(++rootval);
		t3.CREATE0(++rootval);
		t1.CREATE3(rootval-3, t2, t3);
	}
	else if (height > 1)
	{
		t1 = createFullTree(++rootval, height-1);
		t2 = createFullTree(++rootval, height-1);
		t3 = createFullTree(++rootval, height-1);

		t1.CREATE3(0, t2, t3);
		//t1.PRINTTREE(t1.ROOT(), "", false);
	}
	return t1;
}
