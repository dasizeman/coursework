/*
 * Main.cpp
 *
 *  Created on: Jul 26, 2014
 *      Author: dave
 */

#include "ArrayList.h"
#include "PointerList.h"
#include "ArrayStack.h"
#include "PointerStack.h"

void testArrayList();
void testPointerList();
void testArrayStack();
void testPointerStack();

int main()
{
	//testArrayList();
	//testPointerList();
	//testArrayStack();
	testPointerStack();
	return 0;
}

void testArrayList()
{
	//Create a new ArrayList
		ArrayList<int> intAL;

		// Fill it
		position p = intAL.FIRST();
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
		position location = intAL.LOCATE(3);
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
}

void testPointerList()
{
	//Create a new ArrayList
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
}

void testArrayStack()
{
	// Create a new stack
	ArrayStack<int> arrS;

	// Push some items on the stack
	for (int i = 0; i < 10; i++)
		arrS.PUSH(i);

	// Print
	arrS.PRINTSTACK();

	cout << endl << "----------" << endl;

	// Pop
	arrS.POP();
	arrS.PRINTSTACK();

	// Top
	cout << endl << "Top: " << arrS.TOP() << endl;

	cout << "----------" << endl;

	// Clear
	cout << "Clearing..." << endl;
	arrS.MAKENULL();
	arrS.PRINTSTACK();

	cout << "---------" << endl;
	cout << "Pushing 5..." << endl;
	arrS.PUSH(5);
	arrS.PRINTSTACK();
	cout << endl << "Popping..." << endl;
	arrS.POP();
	arrS.PRINTSTACK();
	cout << "Popping..." << endl;
	arrS.POP();

}

void testPointerStack()
{
	// Create a new stack
		PointerStack<int> pointS;

		// Push some items on the stack
		for (int i = 0; i < 10; i++)
			pointS.PUSH(i);

		// Print
		pointS.PRINTSTACK();

		cout << endl << "----------" << endl;

		// Pop
		pointS.POP();
		pointS.PRINTSTACK();

		// Top
		cout << endl << "Top: " << pointS.TOP() << endl;

		cout << "----------" << endl;

		// Clear
		cout << "Clearing..." << endl;
		pointS.MAKENULL();
		pointS.PRINTSTACK();

		cout << "---------" << endl;
		cout << "Pushing 5..." << endl;
		pointS.PUSH(5);
		pointS.PRINTSTACK();
		cout << endl << "Popping..." << endl;
		pointS.POP();
		pointS.PRINTSTACK();
		cout << "Popping..." << endl;
		pointS.POP();
}




