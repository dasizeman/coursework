/*
 * OpenHashTable.h
 *
 *  Created on: Aug 27, 2014
 *      Author: dave
 */

#ifndef OPENHASHTABLE_H_
#define OPENHASHTABLE_H_

#include <string>
using namespace std;

#include "PointerList.h"

class OpenHashTable {
public:
	OpenHashTable(int b);
	void MAKENULL();
	bool MEMBER(string x);
	void INSERT(string x);
	void DELETE (string x);

private:
	const int MAXBUCKETS = 1000;
	int B;
	int N;
	PointerList<string>* table[MAXBUCKETS];
	int h(string s);
};

OpenHashTable::OpenHashTable(int b)
{
	B = b;
	N = 0;
	for (int i = 0; i < MAXBUCKETS; i++)
		table[i] = NULL;
}

void OpenHashTable::MAKENULL()
{
	for (int i = 0; i < B; i++)
		table[i]->MAKENULL();
	OpenHashTable(B);
}

bool OpenHashTable::MEMBER(string x)
{
	cell<string>* p;
	p = table[h(x)]->FIRST();
	while (p->next != NULL)
	{
		p = p->next;
		if (p->element == x)
			return true;
	}

	return false;
}

void OpenHashTable::INSERT(string x)
{
	int bucket = h(x);
    if (!MEMBER(x))
    {
    	table[bucket]->INSERT(x, table[bucket]->END());
    }
}

void OpenHashTable::DELETE(string x)
{
	cell<string>* p;
	int bucket = h(x);
	p = table[bucket]->FIRST();

	while (p->next != NULL)
	{
		if (p->next->element == x)
			table[bucket]->DELETE(p);
	}
}

int OpenHashTable::h (string s)
{
	int i, sum;
	sum = 0;
	for (i = 0; i < s.length(); i++)
	{
		sum += (int)(s[i]);
	}

	return sum % B;
}


#endif /* OPENHASHTABLE_H_ */
