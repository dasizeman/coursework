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

typedef int position;

template<typename T>
class ArrayList {

private:
	T elements[MAXSIZE];
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
		for (q = END(); q >= p; q--)
		{
			elements[q] = elements[q-1];
		}
		last++;
		elements[p-1] = x;
	}
}

template<typename T>
void ArrayList<T>::DELETE(position p)
{
	position q;
	if (p > END() || p < 1)
	{
		cout << "INSERT FAIL: There is no such position: " << p << endl;
	}
	else
	{
		last--;
		for (q = p; q <= END(); q++)
		{
			elements[q-1] = elements[q];
		}
	}
}

template<typename T>
position ArrayList<T>::LOCATE(T x)
{
	position q;

	for (q = FIRST(); q <= END(); q++)
	{
		if (elements[q-1] == x)
			return q;
	}

	return NULL;
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
		return NULL;
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
	return elements[p-1];
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
	position p;
	for (p = FIRST(); p <= END(); p = NEXT(p))
		cout << RETRIEVE(p) << " ";
}

template<typename T>
ArrayList<T>::~ArrayList() {

}


