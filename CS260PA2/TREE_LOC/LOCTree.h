/*
 * LOCTree.h
 *
 *  Created on: Aug 9, 2014
 *      Author: dave
 *
 *  This is a class based on the "List of children" implementation of the Tree ADT presented
 *  in Aho's Data Structure's and Algorithms.  Since the class is a tree itself, the CREATEi
 *  methods have been slightly adapted from the text, but achieve the same effect
 */

#ifndef LOCTREE_H_
#define LOCTREE_H_

#include <deque>
#include <string>
#include "PointerList.h"

using namespace std;

typedef int cs_cursor; // A cursor into the cell space
typedef int ns_cursor; // A cursor into the nodespace

template<typename T>
struct tnode {
	T label; // The label of the node
	cs_cursor header; // A cursor to the node's leftmost child in cellspace
};

struct tcell {
	ns_cursor node; // A cursor to this cell's node in nodespace
	cs_cursor next; // A cursor to this cell's right sibling in cellspace
};

template<typename T>
class LOCTree {

protected: // We need to access these for when this tree will be merged with another one
	deque<tnode<T> > nodespace;
	deque<tcell> cellspace;
	ns_cursor root;


public:
	LOCTree();
	void CREATE0(T v);  // Makes this tree have a single node with value v
	void CREATE1(T v); // Create a new node with value v, and makes it the root of this tree
	void CREATE2(T v, LOCTree t); // Create a new node v, and set this tree and t as it's children (merge this with t and set v as root)
	void CREATE3(T v, LOCTree t1, LOCTree t2); // Create new node v, and set this, t1 and t2 as it's children (three-way merge with v as root)
	ns_cursor ROOT();
	ns_cursor LEFTMOST_CHILD(ns_cursor);
	ns_cursor RIGHT_SIBLING(ns_cursor);
	ns_cursor PARENT(ns_cursor);
	T LABEL(ns_cursor);
	void MAKENULL();
	void PRINTTREE(ns_cursor n, string indent, bool last);
};

template<typename T>
LOCTree<T>::LOCTree()
{
	// The root will be at 1, 0 will represent null
	root = 1;
	nodespace.clear();
	cellspace.clear();
	nodespace.resize(1);
	cellspace.resize(1);
}

template<typename T>
void LOCTree<T>::CREATE0(T v)
{
	LOCTree();
	tnode<T> newn;
	newn.label = v;
	newn.header = 0;
	nodespace.push_back(newn);
	root = 1;

}

template<typename T>
void LOCTree<T>::CREATE1(T v)
{
	// Create the node for the new root, and set the root here
	tnode<T> newn;
	newn.label = v;
	root = nodespace.size(); // Since we haven't added it yet

	// Create a cell entry for the old root
	tcell newc;
	newc.node = nodespace.size()-1; // Set the node to the old root
	newc.next = 0;
	cellspace.push_back(newc);

	// Set the root's child to the old root
	newn.header = cellspace.size()-1;

	// Finally, add the new root to nodespace
	nodespace.push_back(newn);


}

template<typename T>
void LOCTree<T>::CREATE2(T v, LOCTree<T> t)
{

}

template<typename T>
void LOCTree<T>::CREATE3(T v, LOCTree<T> t1, LOCTree<T> t2)
{

}

template<typename T>
ns_cursor LOCTree<T>::ROOT()
{
	return root;
}

template<typename T>
T LOCTree<T>::LABEL(ns_cursor n)
{
	return nodespace[n].label;
}

template<typename T>
ns_cursor LOCTree<T>::LEFTMOST_CHILD(ns_cursor n)
{
	return cellspace[nodespace[n].header].node;
}

template<typename T>
ns_cursor LOCTree<T>::RIGHT_SIBLING(ns_cursor n)
{
	return cellspace[nodespace[n].header].next;
}

template<typename T>
ns_cursor LOCTree<T>::PARENT(ns_cursor n)
{

}

template<typename T>
void LOCTree<T>::MAKENULL()
{
	nodespace.clear();
	cellspace.clear();
	LOCTree();
}

template <typename T>
void LOCTree<T>::PRINTTREE(node n, string indent, bool last)
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
	cout << label[n] << endl;

	cell<node>* i = header[n]->FIRST();
	cell<node>* end = header[n]->END();
	while (i->next != NULL)
	{
		i = i->next;
		PRINTTREE(i->element,indent, i == end);
	}
}

#endif /* LOCTREE_H_ */
