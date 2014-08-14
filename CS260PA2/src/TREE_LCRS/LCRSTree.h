/*
 * LCRSTtree.h
 *
 *  Created on: Aug 12, 2014
 *      Author: dave
 */

#ifndef LCRSTREE_H_
#define LCRSTREE_H_

#include <string>
#include <iostream>
using namespace std;

typedef int lcrs_cursor;

template<typename T>
struct lcrs_node {
	T label;
	lcrs_cursor leftmost_child;
	lcrs_cursor right_sibling;
	lcrs_cursor parent;
};

template<typename T>
class LCRSTree {
private:
	lcrs_node<T>* cellspace;
	lcrs_cursor* cavail;
	lcrs_cursor root;



public:
	LCRSTree(lcrs_node<T>*, lcrs_cursor*);
	void CREATE0(T v);  // Makes this tree have a single node with value v
	void CREATE1(T v); // Create a new node with value v, and makes it the root of this tree
	void CREATE2(T v, LCRSTree t); // Create a new node v, and set this tree and t as it's children (merge this with t and set v as root)
	void CREATE3(T v, LCRSTree t1, LCRSTree t2); // Create new node v, and set this, t1 and t2 as it's children (three-way merge with v as root)
	lcrs_cursor ROOT();
	lcrs_cursor LEFTMOST_CHILD(lcrs_cursor);
	lcrs_cursor RIGHT_SIBLING(lcrs_cursor);
	lcrs_cursor PARENT(lcrs_cursor);
	T LABEL(lcrs_cursor);
	void MAKENULL();
	void PRINTTREE(lcrs_cursor n, string indent, bool last);
};

template<typename T>
LCRSTree<T>::LCRSTree(lcrs_node<T>* cspace, lcrs_cursor* cavailp)
{
	cellspace = cspace;
	cavail = cavailp;
	root = 0;
}

template<typename T>
void LCRSTree<T>::CREATE0(T v)
{
	lcrs_node<T> newc;
	newc.label = v;
	newc.leftmost_child = 0;
	newc.parent = 0;
	newc.right_sibling = 0;
	cellspace[*cavail] = newc;
	root = *cavail;
	(*cavail)++;
}

template<typename T>
void LCRSTree<T>::CREATE1(T v)
{
	lcrs_cursor oldroot = root;
	CREATE0(v);
	cellspace[root].leftmost_child = oldroot;
	cellspace[cellspace[root].leftmost_child].parent = root;
}

template<typename T>
void LCRSTree<T>::CREATE2(T v, LCRSTree<T> t)
{
	CREATE1(v);
	cellspace[cellspace[root].leftmost_child].right_sibling = t.ROOT();
	cellspace[cellspace[cellspace[root].leftmost_child].right_sibling].parent = root;
}

template<typename T>
void LCRSTree<T>::CREATE3(T v, LCRSTree<T> t1, LCRSTree t2)
{
	CREATE2(v, t1);
	cellspace[cellspace[cellspace[root].leftmost_child].right_sibling].right_sibling = t2.ROOT();
	cellspace[cellspace[cellspace[cellspace[root].leftmost_child].right_sibling].right_sibling].parent = root; // Wow
}

template<typename T>
lcrs_cursor LCRSTree<T>::ROOT()
{
	return root;
}

template<typename T>
lcrs_cursor LCRSTree<T>::LEFTMOST_CHILD(lcrs_cursor c)
{
	return cellspace[c].leftmost_child;
}

template<typename T>
lcrs_cursor LCRSTree<T>::RIGHT_SIBLING(lcrs_cursor c)
{
	return cellspace[c].right_sibling;
}

template<typename T>
lcrs_cursor LCRSTree<T>::PARENT(lcrs_cursor c)
{
	return cellspace[c].parent;
}

template<typename T>
T LCRSTree<T>::LABEL(lcrs_cursor c)
{
	return cellspace[c].label;
}

template<typename T>
void LCRSTree<T>::MAKENULL()
{
	LCRSTree(cellspace, cavail);
}

template<typename T>
void LCRSTree<T>::PRINTTREE(lcrs_cursor n, string indent, bool last)
{

	/* Adapted from http://stackoverflow.com/questions/1649027/ */
	cout << indent;
	if (last)
	{
	   cout << "\\-";
	   indent += "  ";
	}
	else
	{
	   cout << "|-";
	   indent += "| ";
	}
	cout << cellspace[n].label << endl;

	lcrs_cursor child = LEFTMOST_CHILD(n); // The first child
	while (child != 0) // While there are more children
	{
		PRINTTREE(child,indent, (RIGHT_SIBLING(child) == 0)); // Print the child tree
		child = RIGHT_SIBLING(child);
	}
}
#endif /* LCRSTTREE_H_ */
