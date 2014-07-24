/*
 * ArrayList.h
 *
 *  Created on: Jul 21, 2014
 *      Author: dave
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#define MAXSIZE 1000

#include <iostream>
using namespace std;

typedef int al_position;

template<typename T>
class ArrayList {

private:
	T elements[MAXSIZE];
	int last;


public:
	ArrayList();
	virtual ~ArrayList();
	al_position END();
	void INSERT(T x, al_position p);
	void DELETE(al_position p);
	al_position LOCATE(T x);
	al_position FIRST();
	T RETRIEVE(al_position p);
	al_position NEXT(al_position p);
	al_position PREVIOUS(al_position p);
	al_position MAKENULL();
	void PRINTLIST();
};

#endif /* ARRAYLIST_H_ */

template<typename T>
ArrayList<T>::ArrayList() {
	last = 0;

}

template<typename T>
al_position ArrayList<T>::END()
{
	return last+1;
}

template<typename T>
void ArrayList<T>::INSERT(T x, al_position p)
{
	al_position q;
	if (last >= MAXSIZE)
	{
		cout << "INSERT FAIL: The list is full" << endl;
	}
	else if (p > END() || p < 1)
	{
		cout << "INSERT FAIL: There is no such position: " << p << endl;
	}
	else
	{
		for (q = last; q >= p; q--)
		{
			elements[q+1] = elements[q];
		}
		last++;
		elements[p] = x;
	}
}

template<typename T>
void ArrayList<T>::DELETE(al_position p)
{
	al_position q;
	if (p > last || p < 1)
	{
		cout << "INSERT FAIL: There is no such position: " << p << endl;
	}
	else
	{
		last--;
		for (q = p; q <= last; q++)
		{
			elements[q] = elements[q+1];
		}
	}
}

template<typename T>
al_position ArrayList<T>::LOCATE(T x)
{
	al_position q;

	for (q = FIRST(); q < END(); q++)
	{
		if (elements[q] == x)
			return q;
	}

	return -1;
}

template<typename T>
al_position ArrayList<T>::FIRST()
{
	return 1;
}

template<typename T>
al_position ArrayList<T>::NEXT(al_position p)
{
	if (p > last || p < 1)
	{
		cout << "NEXT failed: no such position" << endl;
		return END();
	}

	return p+1;
}

template<typename T>
al_position ArrayList<T>::PREVIOUS(al_position p)
{
	if (p > END() || p < 1)
	{
		return NULL;
	}

	return p-1;
}

template<typename T>
T ArrayList<T>::RETRIEVE(al_position p)
{
	return elements[p];
}

template<typename T>
al_position ArrayList<T>::MAKENULL()
{
	last = 0;
	return 1;
}

template<typename T>
void ArrayList<T>::PRINTLIST()
{
	if (FIRST() == END())
		cout << "PRINT FAIL: List is empty!" << endl;
	else
	{
		al_position p;
		for (p = FIRST(); p < END(); p = NEXT(p))
			cout << RETRIEVE(p) << " ";
	}
}

template<typename T>
ArrayList<T>::~ArrayList() {

}


