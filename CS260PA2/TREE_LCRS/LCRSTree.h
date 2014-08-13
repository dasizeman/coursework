/*
 * LCRSTtree.h
 *
 *  Created on: Aug 12, 2014
 *      Author: dave
 */

#ifndef LCRSTREE_H_
#define LCRSTREE_H_

#include <string>
using namespace std;

typedef int lcrs_cursor;

template<typename T>
struct lcrs_node {
	T label;
	lcrs_cursor leftmost_child;
	lcrs_cursor right_sibling;
};

template<typename T>
class LCRSTree {
private:
	lcrs_cursor* cellspace;
	lcrs_cursor* cavail;
	lcrs_cursor root;



public:
	LCRSTree(lcrs_cursor*, lcrs_cursor*);
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
LCRSTree<T>::LCRSTree(lcrs_cursor* cspace, lcrs_cursor* cavailp)
{
	cellspace = cspace;
	cavail = cavailp;
	root = 0;
}

template<typename T>
void LCRSTree<T>::CREATE0(T v)
{

}

template<typename T>
void LCRSTree<T>::CREATE1(T v)
{

}

template<typename T>
void LCRSTree<T>::CREATE2(T v, LCRSTree<T> t)
{

}

template<typename T>
void LCRSTree<T>::CREATE3(T v, LCRSTree<T> t1, LCRSTree t2)
{

}

template<typename T>
lcrs_cursor LCRSTree<T>::ROOT()
{
	return root;
}

template<typename T>
lcrs_cursor LCRSTree<T>::LEFTMOST_CHILD(lcrs_cursor c)
{

}

template<typename T>
lcrs_cursor LCRSTree<T>::RIGHT_SIBLING(lcrs_cursor c)
{

}

template<typename T>
lcrs_cursor LCRSTree<T>::PARENT(lcrs_cursor c)
{

}

template<typename T>
T LCRSTree<T>::LABEL(lcrs_cursor c)
{

}
#endif /* LCRSTTREE_H_ */
