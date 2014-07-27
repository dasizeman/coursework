/*
 * ArrayStack.h
 *
 *  Created on: Jul 26, 2014
 *      Author: dave
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
#define MAXSIZE 1000

#include <iostream>
using namespace std;

template<typename T>
class ArrayStack {

private:
	int top;
	T elements[MAXSIZE+1];

public:
	ArrayStack();
	void MAKENULL();
	bool EMPTY();
	T TOP();
	void POP();
	void PUSH(T x);
	void PRINTSTACK();

};

template<typename T>
ArrayStack<T>::ArrayStack()
{
	top = MAXSIZE+1;
}

template<typename T>
void ArrayStack<T>::MAKENULL()
{
	top = MAXSIZE+1;
}

template<typename T>
bool ArrayStack<T>::EMPTY()
{
	return (top > MAXSIZE);
}

template<typename T>
T ArrayStack<T>::TOP()
{
	if (EMPTY())
		cout << "TOP ERROR: Stack is empty" << endl;
	else return elements[top];
}

template<typename T>
void ArrayStack<T>::POP()
{
	if (EMPTY())
		cout << "POP ERROR: Stack is empty" << endl;
	else
		top++;
}

template<typename T>
void ArrayStack<T>::PUSH(T x)
{
	if (top == 1)
		cout << "PUSH ERROR: Stack is full" << endl;
	else
	{
		top--;
		elements[top] = x;
	}
}

template<typename T>
void ArrayStack<T>::PRINTSTACK()
{
	if (EMPTY())
		cout << "PRINT ERROR: Stack is empty!" << endl;
	else
	{
		for (int i = top; i <= MAXSIZE; i++)
			cout << elements[i] << " ";
	}
}



#endif /* ARRAYSTACK_H_ */
