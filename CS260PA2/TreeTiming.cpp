/*
 * TreeTiming.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: dave
 */
#include "TREE_LOC/LOCTree.h"
#include "TREE_LCRS/LCRSTree.h"

#include <ctime>
using namespace std;

void timePreorder(int);
void timePostorder(int);
void PreorderLOC(LOCTree<int>, ns_cursor, bool);
void PreorderLCRS(LCRSTree<int>, lcrs_cursor,bool);
void PostorderLOC(LOCTree<int>, ns_cursor, bool);
void PostorderLCRS(LCRSTree<int>, lcrs_cursor,bool);

template<typename T>
LCRSTree<T> createFullLCRSTree(T& rootval, int height, lcrs_node<T>* cs, lcrs_cursor* cavailp);
template<typename T>
LOCTree<T> createFullLOCTree(T& rootval, int height, tnode<T>* ns, tcell* cs, ns_cursor* navailp, cs_cursor* cavailp);

const int SPACESIZE = 100000; // Trees use a lot of memory

int main()
{
	const int RANGE = 10;
	for (int i = 1; i <= RANGE; i++)
	{
		cout << "=====HEIGHT " << i << "=====" << endl;
		timePreorder(i);
		timePostorder(i);
	}


}

void timePreorder(int h)
{
	// Stuff for LOCTree
	tnode<int> loc_nodespace[SPACESIZE];
	tcell loc_cellspace[SPACESIZE];
	ns_cursor loc_navail = 1;
	cs_cursor loc_cavail = 1;

	int height = h, rootval = 0;
	LOCTree<int> LOCtree = createFullLOCTree(rootval, height, loc_nodespace, loc_cellspace, &loc_navail, &loc_cavail);

	// Stuff for LCRSTree
	lcrs_node<int> lcrs_cellspace[SPACESIZE];
	lcrs_cursor lcrs_cavail = 1;

	rootval = 0;
	LCRSTree<int> LCRStree = createFullLCRSTree(rootval, height, lcrs_cellspace,&lcrs_cavail);

	clock_t start, end;
	start = clock();
	PreorderLOC(LOCtree, LOCtree.ROOT(),true);
	end = clock();

	double LOCtime = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	start = clock();
	PreorderLCRS(LCRStree, LCRStree.ROOT(), true);
	end = clock();

	double LCRStime = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	cout << "PREORDER:" << endl;
	cout << "\tLOC: " << LOCtime << endl;
	cout << "\tLCRS " << LCRStime << endl;



}

void timePostorder(int h)
{
	// Stuff for LOCTree
	tnode<int> loc_nodespace[SPACESIZE];
	tcell loc_cellspace[SPACESIZE];
	ns_cursor loc_navail = 1;
	cs_cursor loc_cavail = 1;

	int height = h, rootval = 0;
	LOCTree<int> LOCtree = createFullLOCTree(rootval, height, loc_nodespace, loc_cellspace, &loc_navail, &loc_cavail);

	// Stuff for LCRSTree
	lcrs_node<int> cellspace[SPACESIZE];
	lcrs_cursor cavail = 1;

	rootval = 0;
	LCRSTree<int> LCRStree = createFullLCRSTree(rootval, height, cellspace,&cavail);

	clock_t start, end;
	start = clock();
	PostorderLOC(LOCtree, LOCtree.ROOT(), true);
	end = clock();

	double LOCtime = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	start = clock();
	PostorderLCRS(LCRStree, LCRStree.ROOT(), true);
	end = clock();

	double LCRStime = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	cout << "POSTORDER:" << endl;
	cout << "\tLOC: " << LOCtime << endl;
	cout << "\tLCRS " << LCRStime << endl;

}

void PreorderLOC(LOCTree<int> t, ns_cursor n, bool quiet)
{
	ns_cursor c;
	if (!quiet)
	{
		cout << t.LABEL(n) << " ";
		cout.flush();
	}
	c = t.LEFTMOST_CHILD(n);
	while (c != 0)
	{
		PreorderLOC(t, c, quiet);
		c= t.RIGHT_SIBLING(c);
	}
}

void PreorderLCRS(LCRSTree<int> t, lcrs_cursor n, bool quiet)
{
	lcrs_cursor c;
	if (!quiet)
	{
		cout << t.LABEL(n) << " ";
		cout.flush();
	}
	c = t.LEFTMOST_CHILD(n);
	while (c != 0)
	{
		PreorderLCRS(t, c, quiet);
		c= t.RIGHT_SIBLING(c);
	}
}

void PostorderLOC(LOCTree<int> t, ns_cursor n, bool quiet)
{
	ns_cursor c;
	c = t.LEFTMOST_CHILD(n);
	while (c != 0)
	{
		PostorderLOC(t, c, quiet);
		c= t.RIGHT_SIBLING(c);
	}

	if (!quiet)
	{
		cout << t.LABEL(n) << " ";
		cout.flush();
	}
}

void PostorderLCRS(LCRSTree<int> t, lcrs_cursor n, bool quiet)
{
	lcrs_cursor c;
	c = t.LEFTMOST_CHILD(n);
	while (c != 0)
	{
		PostorderLCRS(t, c, quiet);
		c= t.RIGHT_SIBLING(c);
	}
	if (!quiet)
	{
		cout << t.LABEL(n) << " ";
		cout.flush();
	}
}

template<typename T>
LCRSTree<T> createFullLCRSTree(T& rootval, int height, lcrs_node<T>* cs, lcrs_cursor* cavailp)
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
		t1 = createFullLCRSTree(++rootval, height-1, cs, cavailp);
		t2 = createFullLCRSTree(++rootval, height-1, cs, cavailp);
		t3 = createFullLCRSTree(++rootval, height-1, cs, cavailp);

		t1.CREATE3(oldroot, t2, t3);
	}
	return t1;
}

template<typename T>
LOCTree<T> createFullLOCTree(T& rootval, int height, tnode<T>* ns, tcell* cs, ns_cursor* navailp, cs_cursor* cavailp)
{
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
	}
	else if (height > 1)
	{
		int oldroot = rootval;
		t1 = createFullLOCTree(++rootval, height-1, ns, cs, navailp, cavailp);
		t2 = createFullLOCTree(++rootval, height-1, ns, cs, navailp, cavailp);
		t3 = createFullLOCTree(++rootval, height-1, ns, cs, navailp, cavailp);

		t1.CREATE3(oldroot, t2, t3);
	}
	return t1;
}





