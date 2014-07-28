/*
 * PSTest.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: dave
 */

#include "PointerList.h"
#include "PointerStack.h"

int main()
{
	// Create a new stack
			PointerStack<int> pointS;

	// Push some items on the stack
	cout << "Pushing 10 items..." << endl;
	for (int i = 1; i <= 10; i++)
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
	return 0;
}


