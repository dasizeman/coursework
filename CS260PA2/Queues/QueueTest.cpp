/*
 * QueueTest.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: dave
 */
#include "PointerQueue.h"

int main()
{
	PointerQueue<int> pq;

	for (int i = 0; i < 50; i++)
		pq.ENQUEUE(i);

	pq.PRINTQUEUE();

	return 0;
}



