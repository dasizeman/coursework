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

typedef int node;

template<typename T>
class LOCTree {

protected: // We need to access these for when this tree will be merged with another one
	vector<PointerList<node> > header;
	vector<T> label;
	node root;
	node avail; // The next available position for a node

private:
	void RESIZE(int n); // Resize our vectors

public:
	LOCTree();
	void CREATE0(T v);  // Makes this tree have a single node with value v
	void CREATE1(T v); // Create a new node with value v, and makes it the root of this tree
	void CREATE2(T v, LOCTree & t); // Create a new node v, and set this tree and t as it's children (merge this with t and set v as root)
	void CREATE3(T v, LOCTree & t1, LOCTree & t2); // Create new node v, and set this, t1 and t2 as it's children (three-way merge with v as root)
	node ROOT();
	node LEFTMOST_CHILD(node n);
	node RIGHT_SIBLING(node n);
	node PARENT(node n);
	T LABEL(node n);
	void MAKENULL();
	void PRINTTREE(node n, string indent, bool last);
};

template<typename T>
LOCTree<T>::LOCTree()
{
	// The root will be at 1, 0 will represent null
	root = 1;
	avail = 1;

	// Start off with 10 spaces
	header.resize(10);
	label.resize(10);
}

template<typename T>
void LOCTree<T>::RESIZE(int n)
{
	if (n > header.size() - 1) // header and label will always be the same size
	{
		header.resize(n+1);
		label.resize(n+1);
	}
}

template<typename T>
void LOCTree<T>::CREATE0(T v)
{
	if (!header.empty())
		header.clear();
	if (!label.empty())
		label.clear();
	avail = 1;
	RESIZE(avail);

	header[avail] = *(new PointerList<node>);
	label[avail] = v;
	avail++;

}

template<typename T>
void LOCTree<T>::CREATE1(T v)
{
	RESIZE(avail);

	// Move all other nodes down
	for (int i = avail-1; i >= 1; i--)
	{
		header[i+1] = header[i];
		label[i+1] = label[i];
	}

	// Create a new node with value v at root position
	header[ROOT()] = *(new PointerList<node>);
	label[ROOT()] = v;

	// Set its child to be the old root
	header[ROOT()].INSERT(ROOT() + 1, header[ROOT()].END());
	avail++;
}

template<typename T>
void LOCTree<T>::CREATE2(T v, LOCTree<T> & t)
{
	// We will CREATE1, then copy t's nodes into this tree, and add its root to this root's children

	CREATE1(v);
	RESIZE((avail+1) + (t.avail + 1)); // Make sure vectors are big enough to accommodate both trees

	for (int i = 1; i < t.avail; i++)
	{
		header[avail+i] = t.header[i];
		label[avail+i] = t.label[i];
	}

	header[ROOT()].INSERT(avail, header[ROOT()].END());

	avail+=t.avail;
}

template<typename T>
void LOCTree<T>::CREATE3(T v, LOCTree<T> & t1, LOCTree<T> & t2)
{
	// CREATE 2, and then follow a similar procedure to merge the 3rd tree

	CREATE2(v, t1);
	RESIZE((avail+1) + (t2.avail + 1)); // Make sure vectors are big enough to accommodate both trees

	for (int i = 1; i < t2.avail; i++)
	{
		header[avail+i] = t2.header[i];
		label[avail+i] = t2.label[i];
	}

	header[ROOT()].INSERT(avail, header[ROOT()].END());

	avail+=t2.avail;
}

template<typename T>
node LOCTree<T>::ROOT()
{
	return root;
}

template<typename T>
T LOCTree<T>::LABEL(node n)
{
	return label[n];
}

template<typename T>
node LOCTree<T>::LEFTMOST_CHILD(node n)
{
	return header[n].RETRIEVE(header[n].FIRST());
}

template<typename T>
node LOCTree<T>::RIGHT_SIBLING(node n)
{
	// Locate the child of n's parent that occurs after n
	node parent = PARENT(n);

	cell<node>* p = header[parent].FIRST();

	while (p->next != NULL)
	{
		p = p->next;
		if (p->element == n)
			break;
	}

	if (p->next == NULL)
		return 0;
	else return p->next->element;
}

template<typename T>
node LOCTree<T>::PARENT(node n)
{
	// Locate the node that has n as its child
	for (int i = 1; i < avail; i++)
	{
		cell<node>* p = header[i].FIRST();
		while(p->next != NULL)
		{
			p = p->next;
			if (p->element == n)
				return i;
		}
	}

	// Return "null" if not found
	return 0;
}

template<typename T>
void LOCTree<T>::MAKENULL()
{
	header.clear();
	label.clear();
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

	cell<node>* i = header[n].FIRST();
	cell<node>* end = header[n].END();
	while (i->next != NULL)
	{
		i = i->next;
		PRINTTREE(i->element,indent, i == end);
	}
}

#endif /* LOCTREE_H_ */
