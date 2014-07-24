/*
 * ArrayListTest.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: dave
 */

#include "ArrayList.h"

int main()
{
	//Create a new ArrayList
	ArrayList<int> intAL;

	// Fill it
	al_position p = intAL.FIRST();
	for (int i = 1; i <= 10; i++)
	{
		intAL.INSERT(i, p);
		p = intAL.NEXT(p);
	}
	// Print it
	intAL.PRINTLIST();
	cout << endl <<  "-----------" << endl;

	// Delete the item at position 4 and 7
	intAL.DELETE(4);
	intAL.DELETE(7);

	cout << "Deleted items at positions 4 and 7" << endl;

	// Print the list again
	intAL.PRINTLIST();
	cout << endl << "-----------" << endl;

	// Try locating the number 3
	cout << "Looking for number 3..." << endl;
	al_position location = intAL.LOCATE(3);
	if (location >= 0)
		cout << "Found at position " << location << endl;
	else
		cout << "Item not found" << endl;

	cout << "-----------" << endl;

	// Try locating the number 8
	cout << "Looking for number 8..." << endl;
	location = intAL.LOCATE(8);
	if (location >= 0)
		cout << "Found at position " << location << endl;
	else
		cout << "Item not found" << endl;

	cout << "-----------" << endl;

	// Insert the number 23 at position 5
	cout << "Inserting 23 at position 5..." << endl;
	intAL.INSERT(23, 5);
	intAL.PRINTLIST();

	cout << endl << "-----------" << endl;

	// Try inserting 23 at position 11
	cout << "Inserting 23 at position 11..." << endl;
	intAL.INSERT(23,11);
	intAL.PRINTLIST();

	cout << endl << "-----------" << endl;

	// Clear the list
	cout << "Clearing the list..." << endl;
	intAL.MAKENULL();
	intAL.PRINTLIST();
	return 0;
}




