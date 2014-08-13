#include <vector>
#include <iostream>
using namespace std;

#include "LOCTree.h"

template<typename T>
LOCTree<T> createFullTree(T&, int, tnode<T>*, tcell*, ns_cursor*, cs_cursor*);

int main()
{
	tnode<int> nodespace[1000];
	tcell cellspace[1000];
	ns_cursor navail = 1;
	cs_cursor cavail = 1;

	int height = 3, rootval = 0;
	LOCTree<int> tree = createFullTree(rootval, height, nodespace, cellspace, &navail, &cavail);
	tree.PRINTTREE(tree.ROOT(), "", false);




	return 0;
}

template<typename T>
LOCTree<T> createFullTree(T& rootval, int height, tnode<T>* ns, tcell* cs, ns_cursor* navailp, cs_cursor* cavailp)
{
	//cout << "Height: " << height << endl;
	LOCTree<int> t1(ns, cs, navailp, cavailp);
	LOCTree<int> t2(ns, cs, navailp, cavailp);
	LOCTree<int> t3(ns, cs, navailp, cavailp);
	if (height == 1)
	{
		int oldroot = rootval;
		t1.CREATE0(++rootval);
		t2.CREATE0(++rootval);
		t3.CREATE0(++rootval);
		t1.CREATE3(oldroot, t2, t3);
		//t1.PRINTTREE(t1.ROOT(), "", false);
	}
	else if (height > 1)
	{
		int oldroot = rootval;
		t1 = createFullTree(++rootval, height-1, ns, cs, navailp, cavailp);
		//t1.PRINTTREE(t1.ROOT(), "", false);
		t2 = createFullTree(++rootval, height-1, ns, cs, navailp, cavailp);
		//t2.PRINTTREE(t2.ROOT(), "", false);
		t3 = createFullTree(++rootval, height-1, ns, cs, navailp, cavailp);
		//t3.PRINTTREE(t3.ROOT(), "", false);

		t1.CREATE3(oldroot, t2, t3);
		//t1.PRINTTREE(t1.ROOT(), "", false);
	}
	//cout << "-----------" << endl;
	return t1;
}
