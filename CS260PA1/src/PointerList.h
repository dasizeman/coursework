/*
 * PointerList.h
 *
 *  Created on: Jul 23, 2014
 *      Author: dave
 */

#ifndef POINTERLIST_H_
#define POINTERLIST_H_

#include <iostream>

template<typename T>
struct cell{
		T element;
		cell<T>* next;
	};

typedef cell* al_position;


template <typename T>
class PointerList {

private:
	cell<T>* head;

public:
	PointerList();
	virtual ~PointerList();
};

#endif /* POINTERLIST_H_ */
