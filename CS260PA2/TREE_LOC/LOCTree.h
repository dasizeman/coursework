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

#include <vector>
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
private:
	tnode<T>* nodespace;
	tcell* cellspace;
	ns_cursor* navail;
	cs_cursor* cavail;


protected: // We need to access these for when this tree will be merged with another one
	ns_cursor root;



public:
	LOCTree(tnode<T>*, tcell*, ns_cursor*, cs_cursor*);
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
LOCTree<T>::LOCTree(tnode<T>* nspointer, tcell* cspointer, ns_cursor* navailp, cs_cursor* cavailp)
{
	// The root will be at 1, 0 will represent null
	root = 0;
	nodespace = nspointer;
	cellspace = cspointer;
	navail = navailp;
	cavail = cavailp;


}

template<typename T>
void LOCTree<T>::CREATE0(T v)
{
	LOCTree(nodespace, cellspace, navail, cavail);
	tnode<T> newn;
	newn.label = v;
	newn.header = 0;
	nodespace[*navail] = newn;
	root = *navail;
	(*navail)++;

}

template<typename T>
void LOCTree<T>::CREATE1(T v)
{
	ns_cursor oldroot = root;
	CREATE0(v);
	nodespace[root].header = *cavail;

	// Create a cell for the new root, and make it's child the old root
	tcell newc;
	newc.node = oldroot;
	newc.next = 0;
	cellspace[*cavail] = newc;
	(*cavail)++;

	cout << "CREATE 1 DONE" << endl;
	PRINTTREE(ROOT(), "", false);


}

template<typename T>
void LOCTree<T>::CREATE2(T v, LOCTree<T> t)
{
	CREATE1(v);

	// Two cases: t has children already (it has a node in cellspace), or it is a single node,
	// in which case it does not and we have to create one pointing back to that node (this makes
	// sense trust me)

	// Case 1:
	if (nodespace[t.ROOT()].header != 0)
	{
		// Set t's root as the second child of this root
		cellspace[nodespace[root].header].next = nodespace[t.ROOT()].header;
	}
	else // Case 2:
	{
		// Create a cellspace entry for t's root
		tcell newc;
		newc.node = t.ROOT();
		newc.next = 0;
		cellspace[*cavail] = newc;
		(*cavail)++;

		// Add this entry as this root's second child
		cellspace[nodespace[root].header].next = (*cavail - 1);
	}

	cout << "CREATE 2 DONE" << endl;
	PRINTTREE(ROOT(), "", false);

}

template<typename T>
void LOCTree<T>::CREATE3(T v, LOCTree<T> t1, LOCTree<T> t2)
{
	CREATE2(v, t1);

	// Two cases: t has children already (it has a node in cellspace), or it is a single node,
	// in which case it does not and we have to create one pointing back to that node (this makes
	// sense trust me)

	// Case 1:
	if (nodespace[t2.ROOT()].header != 0)
	{
		// Set t2's root as the third child of this root
		cellspace[cellspace[nodespace[root].header].next].next = nodespace[t2.ROOT()].header;
	}
	else // Case 2:
	{
		// Create a cellspace entry for t's root
		tcell newc;
		newc.node = t2.ROOT();
		newc.next = 0;
		cellspace[*cavail] = newc;
		(*cavail)++;

		// Add this entry as this root's third child
		cellspace[cellspace[nodespace[root].header].next].next = (*cavail - 1);
	}

	cout << "CREATE 3 DONE" << endl;
	PRINTTREE(ROOT(), "", false);
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
	// Find the cellspace entry whose node is n, and take the node field of the cell pointed to by that
	// cell's next field
	cs_cursor c;
	for (int i = 1; i < *cavail; i++)
	{
		if (cellspace[i].node == n)
			c = i;
	}
	return cellspace[cellspace[c].next].node;
}

template<typename T>
ns_cursor LOCTree<T>::PARENT(ns_cursor n)
{

}

template<typename T>
void LOCTree<T>::MAKENULL()
{
	LOCTree(nodespace, cellspace, navail, cavail);
}

template <typename T>
void LOCTree<T>::PRINTTREE(ns_cursor n, string indent, bool last)
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
	cout << nodespace[n].label << endl;

	ns_cursor child = LEFTMOST_CHILD(n); // The first child
	while (child != 0) // While there are more children
	{
		PRINTTREE(child,indent, (RIGHT_SIBLING(child) == 0)); // Print the child tree
		child = RIGHT_SIBLING(child);
	}
}

#endif /* LOCTREE_H_ */
