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
	position p = intAL.FIRST();
	for (int i = 1; i <= 100; i++)
	{
		intAL.INSERT(i, p);
		p = intAL.NEXT(p);
	}
	// Print it
	intAL.PRINTLIST();
	return 0;
}




