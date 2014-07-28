/*
 * TimingTests.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: dave
 */

#include <list>
#include <stack>
#include <ctime>
using namespace std;

#include "ArrayList/ArrayList.h"
#include "ArrayStack/ArrayStack.h"
#include "PointerList/PointerList.h"
#include "PointerStack/PointerStack.h"

void iteratedInsertionFront(int);
void iteratedInsertionBack(int);
void traverse(int);
void iteratedDeletionFront(int);
void iteratedDeletionBack(int);
void iteratedPush(int);
void iteratedPop(int);

int main()
{

	for (int i = 100000; i <= 1000000; i += 100000)
	{
		cout << "--Running test of " << i << " items---" << endl;
		iteratedInsertionFront(i);
		iteratedInsertionBack(i);
		traverse(i);
		iteratedDeletionFront(i);
		iteratedDeletionBack(i);
		iteratedPush(i);
		iteratedPop(i);
	}

	return 0;
}

void iteratedInsertionFront(int num)
{
	clock_t start, end;

	// ArrayList implementation
	ArrayList<int> intAL;

	start = clock();
	for (int i = 0; i < num; i++)
		intAL.INSERT(i , intAL.FIRST());
	end = clock();
	double AL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	intAL.MAKENULL();

	// PointerList implementation
	PointerList<int> intPL;

	start = clock();
	for (int i = 0; i < num; i++)
		intPL.INSERT(i, intPL.FIRST());
	end = clock();

	double PL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	intPL.MAKENULL();

	// STL list implementation
	list<int> stlList;

	start = clock();
	for (int i = 0; i < num; i++)
		stlList.push_front(i);
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	stlList.clear();

	// Print results
	cout << "FRONT ITERATED INSERTION (ms)" << endl;
	cout << "\tArrayList: " << AL_time << endl;
	cout << "\tPointerList: " << PL_time << endl;
	cout << "\tSTL List: " << stl_time << endl;

}

void iteratedInsertionBack(int num)
{
	clock_t start, end;

	// ArrayList implementation
	ArrayList<int> intAL;

	start = clock();
	for (int i = 0; i < num; i++)
		intAL.INSERT(i , intAL.END());
	end = clock();
	double AL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	intAL.MAKENULL();

	// PointerList implementation
	PointerList<int> intPL;

	start = clock();
	for (int i = 0; i < num; i++)
		intPL.INSERT(i, intPL.END());
	end = clock();

	double PL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	intPL.MAKENULL();

	// STL list implementation
	list<int> stlList;

	start = clock();
	for (int i = 0; i < num; i++)
		stlList.push_back(i);
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	stlList.clear();

	// Print results
	cout << "BACK ITERATED INSERTION (ms)" << endl;
	cout << "\tArrayList: " << AL_time << endl;
	cout << "\tPointerList: " << PL_time << endl;
	cout << "\tSTL List: " << stl_time << endl;
}

void traverse(int num)
{
	clock_t start, end;

	// ArrayList implementation
	ArrayList<int> intAL;

	for (int i = 0; i < num; i++)
		intAL.INSERT(i , intAL.END());

	start = clock();
	position p = intAL.FIRST();
	while (p != intAL.END())
		p = intAL.NEXT(p);
	end = clock();
	double AL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	intAL.MAKENULL();

	// PointerList implementation
	PointerList<int> intPL;

	for (int i = 0; i < num; i++)
		intPL.INSERT(i, intPL.FIRST());

	start = clock();
	cell<int>* q = intPL.FIRST();
	cell<int>* endp = intPL.END();
	while (q != endp)
		q = intPL.NEXT(q);
	end = clock();

	double PL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	intPL.MAKENULL();

	// STL list implementation
	list<int> stlList;

	for (int i = 0; i < num; i++)
		stlList.push_back(i);

	start = clock();
	list<int>::iterator it = stlList.begin();
	while (it != stlList.end())
		it++;
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	stlList.clear();

	// Print results
	cout << "TRAVERSAL (ms)" << endl;
	cout << "\tArrayList: " << AL_time << endl;
	cout << "\tPointerList: " << PL_time << endl;
	cout << "\tSTL List: " << stl_time << endl;
}

void iteratedDeletionFront(int num)
{
	clock_t start, end;

	// ArrayList implementation
	ArrayList<int> intAL;

	for (int i = 0; i < num; i++)
			intAL.INSERT(i , intAL.END());

	start = clock();
	while (intAL.FIRST() != intAL.END())
		intAL.DELETE(intAL.FIRST());
	end = clock();
	double AL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// PointerList implementation
	PointerList<int> intPL;

	for (int i = 0; i < num; i++)
			intPL.INSERT(i, intPL.FIRST());

	start = clock();;
	while (intPL.FIRST()->next != NULL) // Don't use end here, we don't want to traverse the entire list for each condition check
		intPL.DELETE(intPL.FIRST());
	end = clock();

	double PL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// STL list implementation
	list<int> stlList;

	for (int i = 0; i < num; i++)
			stlList.push_back(i);

	start = clock();
	while (stlList.begin() != stlList.end())
		stlList.pop_front();
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// Print results
	cout << "FRONT ITERATED DELETION (ms)" << endl;
	cout << "\tArrayList: " << AL_time << endl;
	cout << "\tPointerList: " << PL_time << endl;
	cout << "\tSTL List: " << stl_time << endl;
}

void iteratedDeletionBack(int num)
{
	clock_t start, end;

	// ArrayList implementation
	ArrayList<int> intAL;

	for (int i = 0; i < num; i++)
			intAL.INSERT(i , intAL.END());

	start = clock();
	while (intAL.FIRST() != intAL.END())
		intAL.DELETE(intAL.END()-1);
	end = clock();
	double AL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// PointerList implementation
	// NOTE: Deleting from the back REALLY sucks with this implementation.  We can't use END(), because it represents
	// one past last position.  And we can't do END()-1 like we did for the array implementation.  So we literally have
	// to move all the way to one before the last node, and call delete there.  Remember position i points to the i-1th
	// node here
	PointerList<int> intPL;

	for (int i = 0; i < num; i++)
			intPL.INSERT(i, intPL.FIRST());

	start = clock();
	cell<int>* d; // The node to call DELETE on
	while (intPL.FIRST()->next != NULL) // Don't use end here, we don't want to traverse the entire list for each condition check
	{
		d = intPL.FIRST();
		while (d->next->next != NULL)
			d = intPL.NEXT(d);
		intPL.DELETE(d);
	}
	end = clock();

	double PL_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// STL list implementation
	list<int> stlList;

	for (int i = 0; i < num; i++)
			stlList.push_back(i);

	start = clock();
	while (stlList.begin() != stlList.end())
		stlList.pop_back();
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// Print results
	cout << "BACK ITERATED DELETION (ms)" << endl;
	cout << "\tArrayList: " << AL_time << endl;
	cout << "\tPointerList: " << PL_time << endl;
	cout << "\tSTL List: " << stl_time << endl;
}

void iteratedPush(int num)
{
	clock_t start, end;

	// ArrayStack implementation
	ArrayStack<int> intAS;

	start = clock();
	for (int i = 0; i < num; i++)
		intAS.PUSH(i);
	end = clock();

	double AS_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);
	intAS.MAKENULL();

	// PointerStack implementation
	PointerStack<int> intPS;

	start = clock();
	for (int i = 0; i < num; i++)
		intPS.PUSH(i);
	end = clock();

	double PS_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);
	intPS.MAKENULL();

	// STL Stack implementation
	stack<int> stlStack;

	start = clock();
	for (int i = 0; i < num; i++)
		stlStack.push(i);
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// Print results
	cout << "ITERATED PUSH (ms)" << endl;
	cout << "\tArrayList: " << AS_time << endl;
	cout << "\tPointerList: " << PS_time << endl;
	cout << "\tSTL List: " << stl_time << endl;
}

void iteratedPop(int num)
{
	clock_t start, end;

	// ArrayStack implementation
	ArrayStack<int> intAS;

	for (int i = 0; i < num; i++)
			intAS.PUSH(i);

	start = clock();
	for (int i = 0; i < num; i++)
			intAS.POP();
	end = clock();

	double AS_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// PointerStack implementation
	PointerStack<int> intPS;

	for (int i = 0; i < num; i++)
			intPS.PUSH(i);

	start = clock();
	for (int i = 0; i < num; i++)
			intPS.POP();
	end = clock();

	double PS_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// STL Stack implementation
	stack<int> stlStack;

	for (int i = 0; i < num; i++)
			stlStack.push(i);

	start = clock();
	for (int i = 0; i < num; i++)
		stlStack.pop();
	end = clock();

	double stl_time = ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

	// Print results
	cout << "ITERATED POP (ms)" << endl;
	cout << "\tArrayList: " << AS_time << endl;
	cout << "\tPointerList: " << PS_time << endl;
	cout << "\tSTL List: " << stl_time << endl;
}




