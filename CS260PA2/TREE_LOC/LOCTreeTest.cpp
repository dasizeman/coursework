#include <vector>
#include <iostream>
using namespace std;

#include "LOCTree.h"

int main()
{
	LOCTree<int> ltree;
	ltree.CREATE0(5);
	ltree.PRINTTREE(ltree.ROOT(), "", false);

	return 0;
}
