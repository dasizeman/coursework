/*
 * ArrayList.h
 *
 *  Created on: Jul 21, 2014
 *      Author: dave
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#define MAXSIZE 1000000

#include <iostream>
using namespace std;

typedef int position;

template<typename T>
class ArrayList {

private:
	T elements[MAXSIZE+1];
	int last;


public:
	ArrayList();
	virtual ~ArrayList();
	position END();
	void INSERT(T x, position p);
	void DELETE(position p);
	position LOCATE(T x);
	position FIRST();
	T RETRIEVE(position p);
	position NEXT(position p);
	position PREVIOUS(position p);
	position MAKENULL();
	void PRINTLIST();
};

#endif /* ARRAYLIST_H_ */

template<typename T>
ArrayList<T>::ArrayList() {
	last = 0;

}

template<typename T>
position ArrayList<T>::END()
{
	return last+1;
}

template<typename T>
void ArrayList<T>::INSERT(T x, position p)
{
	position q;
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
void ArrayList<T>::DELETE(position p)
{
	position q;
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
position ArrayList<T>::LOCATE(T x)
{
	position q;

	for (q = FIRST(); q < END(); q++)
	{
		if (elements[q] == x)
			return q;
	}

	return -1;
}

template<typename T>
position ArrayList<T>::FIRST()
{
	return 1;
}

template<typename T>
position ArrayList<T>::NEXT(position p)
{
	if (p > last || p < 1)
	{
		cout << "NEXT failed: no such position" << endl;
		return END();
	}

	return p+1;
}

template<typename T>
position ArrayList<T>::PREVIOUS(position p)
{
	if (p > END() || p < 1)
	{
		return NULL;
	}

	return p-1;
}

template<typename T>
T ArrayList<T>::RETRIEVE(position p)
{
	return elements[p];
}

template<typename T>
position ArrayList<T>::MAKENULL()
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
		position p;
		for (p = FIRST(); p < END(); p = NEXT(p))
			cout << RETRIEVE(p) << " ";
	}
}

template<typename T>
ArrayList<T>::~ArrayList() {

}


