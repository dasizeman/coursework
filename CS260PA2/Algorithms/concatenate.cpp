/*
 * ConcatenateLists.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: dave
 */
#include <cstdlib>
#include <ctime>
using namespace std;

#include "PointerList.h"

template<typename T>
PointerList<T>* concatenateLists(PointerList<PointerList<T>* >* lists);

void createNSortedIntLists(int n, PointerList<PointerList<int>* >* lists );

int main()
{
	PointerList<PointerList<int>* >* lists = new PointerList<PointerList<int>* >;
	createNSortedIntLists(5, lists);

	cell<PointerList<int>* >* pos = lists->FIRST();
	while (pos->next != NULL)
	{
		pos = pos->next;
		pos->element->PRINTLIST();
		cout << endl;
	}
	cout << "-------------------" << endl;

	PointerList<int>* concatenated = concatenateLists(lists);
	concatenated->PRINTLIST();

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
PointerList<T>* concatenateLists(PointerList<PointerList<T>* >* lists)
{
	PointerList<T>* res = new PointerList<T>;
	cell<PointerList<int>* >* pos = lists->FIRST()->next;

	while (pos->next!= NULL)
	{
		lists->RETRIEVE(pos)->END()->next = lists->RETRIEVE(lists->NEXT(pos))->FIRST()->next;
		pos = pos->next;
	}
	return lists->RETRIEVE(lists->FIRST()->next);

}



