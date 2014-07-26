/*
 * PointerList.h
 *
 *  Created on: Jul 23, 2014
 *      Author: dave
 */

#ifndef POINTERLIST_H_
#define POINTERLIST_H_

#include <iostream>
using namespace std;

template<typename T>
struct cell{
		T element;
		cell<T>* next;
	};


template <typename T>
class PointerList {

private:
	cell<T>* head;

public:
	PointerList();
	virtual ~PointerList();
	cell<T>* END();
	cell<T>* FIRST();
	void INSERT(T x, cell<T>* p);
	void DELETE(cell<T>* p);
	cell<T>* LOCATE(T x);
	cell<T>* MAKENULL();
	T RETRIEVE(cell<T>* p);
	cell<T>* NEXT(cell<T>* p);
	void PRINTLIST();
};

template<typename T>
PointerList<T>::PointerList() {
	new(head) cell<T>();
	head->next = NULL;
}

template<typename T>
cell<T>* PointerList<T>::FIRST()
{
	return head;
}

template<typename T>
cell<T>* PointerList<T>::END()
{
	cell<T>* q;
	q = FIRST();
	while (q->next != NULL)
	{
		q = q->next;
	}
	return q;
}

template<typename T>
void INSERT(T x, cell<T>* p)
{
	cell<T>* temp;
	temp = p->next;
	p->next = new cell<T>;
	p->next->element = x;
	p->next->next = temp;
}

template<typename T>
void PointerList<T>::DELETE(cell<T>* p)
{
	delete(p->next);
	p->next = p->next->next;
}

template<typename T>
cell<T>* PointerList<T>::LOCATE(T x)
{
	cell<T>* p;
	p = FIRST();
	while (p->next != NULL)
	{
		if (p->next->element == x)
			return p;
		else
			p = p->next;
	}
	return p;
}

template<typename T>
T PointerList<T>::RETRIEVE(cell<T>* p)
{
	return p->element;
}

template<typename T>
cell<T>* PointerList<T>::MAKENULL()
{
	cell<T>* p;
	cell<T>* d;
	d = FIRST();
	while (p->next != NULL)
	{
		p = d->next;
		delete(d);
		d = p;
	}
	new(head) cell<T>();
	head->next = NULL;
}

template<typename T>
cell<T>* PointerList<T>::NEXT(cell<T>* p)
{
	if (p->next == NULL)
		return END();
	return p->next;
}

template<typename T>
void PointerList<T>::PRINTLIST()
{
	cell<T>* p = FIRST();
	while(p->next != NULL)
	{
		cout << p->element << " ";
		p = p->next;
	}
}

template<typename T>
PointerList<T>::~PointerList() {
	MAKENULL();
	delete(head);
}


#endif /* POINTERLIST_H_ */
