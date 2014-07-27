/*
 * ASTest.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: dave
 */

#include "ArrayStack.h"

int main()
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
	return 0;
}


