/*
 * PLTest.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: dave
 */

#include "PointerList.h"

int main()
{
	//Create a new PointerList
			PointerList<int> intPL;

	// Fill it
	cell<int>* p = intPL.FIRST();
	for (int i = 1; i <= 10; i++)
	{
		intPL.INSERT(i, p);
		p = intPL.NEXT(p);
	}
	// Print it
	intPL.PRINTLIST();
	cout << endl <<  "-----------" << endl;

	// Delete the item at position 4 and 7
	intPL.DELETE(intPL.LOCATE(4));
	intPL.DELETE(intPL.LOCATE(7));

	cout << "Deleted items at positions 4 and 7" << endl;

	// Print the list again
	intPL.PRINTLIST();
	cout << endl << "-----------" << endl;

	// Try locating the number 3
	cout << "Looking for number 3..." << endl;
	cell<int>* location = intPL.LOCATE(3);
	if (location >= 0)
		cout << "Found" << endl;
	else
		cout << "Item not found" << endl;

	cout << "-----------" << endl;

	// Try locating the number 8
	cout << "Looking for number 8..." << endl;
	location = intPL.LOCATE(8);
	if (location >= 0)
		cout << "Found" << endl;
	else
		cout << "Item not found" << endl;

	cout << "-----------" << endl;

	// Insert the number 23 at position 5
	cout << "Inserting 23 at position 5..." << endl;
	p = intPL.FIRST();
	for (int i = 0; i < 4; i++)
		p = p->next;
	intPL.INSERT(23, p);
	intPL.PRINTLIST();

	cout << endl << "-----------" << endl;

	// Try inserting 23 at position 11
	cout << "Inserting 23 at position 11..." << endl;
	p = intPL.FIRST();
	for (int i = 0; i < 10; i++)
		p = intPL.NEXT(p);
	intPL.INSERT(23,p);
	intPL.PRINTLIST();

	cout << endl << "-----------" << endl;

	// Clear the list
	cout << "Clearing the list..." << endl;
	intPL.MAKENULL();
	intPL.PRINTLIST();
	return 0;
}



