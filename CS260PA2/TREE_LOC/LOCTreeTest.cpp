#include <vector>
#include <iostream>
using namespace std;

#include "LOCTree.h"

template<typename T>
LOCTree<T> createFullTree(T&, int);

int main()
{
	/*
	LOCTree<int> tree;
	tree.CREATE0(0);
	LOCTree<int>* subtrees[2];
	for (int i = 0; i < 2; i++)
	{
		subtrees[i] = new LOCTree<int>;
		subtrees[i]->CREATE0(i+1);
	}
	tree.CREATE3(10, *(subtrees[0]), *(subtrees[1]));
	tree.PRINTTREE(tree.ROOT(), "", false);

	cout << tree.LABEL(tree.ROOT()) << endl;
	cout << tree.LABEL(tree.LEFTMOST_CHILD(tree.ROOT()));
*/

	int rootval = 0;
	LOCTree<int> generatedTree = createFullTree(rootval,2);
	//generatedTree.PRINTTREE(generatedTree.ROOT(), "", false);
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
		cout << "Height 1 Tree FINAL:" << endl;
		t1.PRINTTREE(t1.ROOT(), "", false);
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
