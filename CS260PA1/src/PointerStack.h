/*
 * PointerStack.h
 *
 *  Created on: Jul 26, 2014
 *      Author: dave
 */

#ifndef POINTERSTACK_H_
#define POINTERSTACK_H_

#include <iostream>
using namespace std;
#include "PointerList.h"

template <typename T>
class PointerStack {

private:
	cell<T>* top = NULL;

public:
	PointerStack();
	void MAKENULL();
	bool EMPTY();
	T TOP();
	void POP();
	void PUSH(T x);
	void PRINTSTACK();
};

template<typename T>
PointerStack<T>::PointerStack()
{
	top = new cell<T>;
}

template<typename T>
void PointerStack<T>::MAKENULL()
{
	cell<T>* p;
	cell<T>* d;
	d = top;
	while (d->next != NULL)
	{
		p = d->next;
		delete(d);
		d = p;
	}
	delete(d);
	top = new cell<T>;
}

template<typename T>
bool PointerStack<T>::EMPTY()
{
	return (top->next == NULL);
}

template<typename T>
T PointerStack<T>::TOP()
{
	if (EMPTY())
		cout << "TOP ERROR: Stack is empty" << endl;
	else return top->next->element;
}

template<typename T>
void PointerStack<T>::POP()
{
	if (EMPTY())
		cout << "POP ERROR: Stack is empty" << endl;
	else
	{
		cell<T>* d = top->next;
		top->next = top->next->next;
		delete(d);
	}
}

template<typename T>
void PointerStack<T>::PUSH(T x)
{
	cell<T>* temp = top->next;
	top->next = new cell<T>;
	top->next->element = x;
	top->next->next = temp;
}

template<typename T>
void PointerStack<T>::PRINTSTACK()
{
	cell<T>* p = top;
	if (p->next == NULL)
		cout << "PRINT ERROR: List is empty!" << endl;
	while(p->next != NULL)
	{
		p = p->next;
		cout << p->element << " ";
	}
}


#endif /* POINTERSTACK_H_ */
