/*
 * PointerQueue.h
 *
 *  Created on: Aug 8, 2014
 *      Author: dave
 */

#ifndef POINTERQUEUE_H_
#define POINTERQUEUE_H_

#include "PointerList.h"

template<typename T>
class PointerQueue {

private:
	cell<T>* front = NULL, *rear = NULL;
	PointerList<T> PList;

public:
	PointerQueue();
	T FRONT();
	void ENQUEUE(T x);
	void DEQUEUE();
	bool EMPTY();
	void MAKENULL();
	void 	PRINTQUEUE();


};

template<typename T>
PointerQueue<T>::PointerQueue()
{
}

template<typename T>
T PointerQueue<T>::FRONT()
{
	return PList.FIRST()->next->element;
}

template<typename T>
void PointerQueue<T>::ENQUEUE(T x)
{
	PList.INSERT(x, PList.FIRST());
}

template<typename T>
void PointerQueue<T>::DEQUEUE()
{
	PList.DELETE(PList.PREVIOUS(PList.END()));
}

template <typename T>
bool PointerQueue<T>::EMPTY()
{
	return (PList.FIRST()->next == NULL);
}

template<typename T>
void PointerQueue<T>::MAKENULL()
{
	PList.MAKENULL();
}

template<typename T>
void PointerQueue<T>::PRINTQUEUE()
{
	PList.PRINTLIST();
}



#endif /* POINTERQUEUE_H_ */
