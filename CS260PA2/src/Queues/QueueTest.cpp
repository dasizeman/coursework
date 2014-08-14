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
	cout << "Enqueue 50 items" << endl;
	for (int i = 0; i < 50; i++)
		pq.ENQUEUE(i);

	pq.PRINTQUEUE();

	cout << endl;
	pq.DEQUEUE();
	cout << "Deque an item " << endl;
	pq.PRINTQUEUE();

	cout << endl;

	cout << "First item:" << endl;
	cout << pq.FRONT() << endl;

	cout << "Enqueue an item" << endl;
	pq.ENQUEUE(80);
	pq.PRINTQUEUE();

	return 0;
}



