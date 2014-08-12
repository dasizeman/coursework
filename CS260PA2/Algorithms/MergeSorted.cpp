/*
 * MergeSorted.cpp
 *
 *	Merges n sorted lists
 *
 *  Created on: Aug 12, 2014
 *      Author: dave
 */
#include <cstdlib>
#include <ctime>
using namespace std;

#include "PointerList.h"

template<typename T>
PointerList<T>* mergeNLists(PointerList<PointerList<T>* >* lists);

void createNSortedIntLists(int n, PointerList<PointerList<int>* >* lists );

int main()
{
	srand((unsigned)time(0));

	PointerList<PointerList<int>* >* lists = new PointerList<PointerList<int>* >;

	createNSortedIntLists(5, lists);

	cout << "SOURCE LISTS" << endl;
	cout << "-------------------" << endl;
	cell<PointerList<int>* >* pos = lists->FIRST();
	while (pos->next != NULL)
	{
		pos = pos->next;
		pos->element->PRINTLIST();
		cout << endl;
	}
	cout << "-------------------" << endl;
	cout << "MERGED LIST:" << endl;

	PointerList<int>* merged = mergeNLists(lists);
	merged->PRINTLIST();



	return 0;
}

void createNSortedIntLists(int n, PointerList<PointerList<int>* >* lists)
{
	int numberToAdd = (1 + (rand() % (10 + (rand() % 100))));

	PointerList<int>* currentlist;
	for (int i = 0; i < n; i++) // Each list
	{
		currentlist = new PointerList<int>;
		lists->INSERT(currentlist, lists->END());

		for (int j = 0; j < 5; j++) // Each list will have 10 items
		{
			// Add the current number to the current list
			currentlist->INSERT(numberToAdd, currentlist->END());

			// Increment the number to add by some amount between 1 and 10
			numberToAdd += (1 + (rand() % (10 + (rand() % 100))));
		}
		numberToAdd = (1 + (rand() % (10 + (rand() % 100))));
	}

}

template<typename T>
PointerList<T>* mergeNLists(PointerList<PointerList<T>* >* lists)
{
	PointerList<T>* res = new PointerList<T>;

	PointerList<T>* lowestlist; // The list with the lowest first element

	while (lists->FIRST()->next != NULL) // While the list of lists in not depleted
	{
		// Go through each list and find the one that has the lowest first element
		lowestlist = lists->FIRST()->next->element;

		cell<PointerList<int>* >* pos = lists->FIRST();
		cell<PointerList<int>* >* lowestpos = pos;
		while (pos->next != NULL)
		{
			pos = pos->next;
			int currentlistvalue = lists->RETRIEVE(pos)->FIRST()->next->element;
			int lowestlistvalue = lowestlist->FIRST()->next->element;
			if (currentlistvalue <= lowestlistvalue)
			{
				lowestpos = pos;
				lowestlist = lists->RETRIEVE(pos);
			}
		}

		// Add the first element of the lowest list to the result list
		res->INSERT(lowestlist->RETRIEVE(lowestlist->FIRST()->next), res->END());

		// Remove the element from that list
		lowestlist->DELETE(lowestlist->FIRST());


		// If that list is now empty, remove it from our list of lists
		if (lowestlist->FIRST()->next == NULL)
		{
			lists->DELETE(lists->PREVIOUS(lowestpos));
		}
	}


	return res;

}


