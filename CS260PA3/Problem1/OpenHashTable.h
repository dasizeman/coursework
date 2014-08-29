/*
 * OpenHashTable.h
 *
 *  Created on: Aug 27, 2014
 *      Author: dave
 */

#ifndef OPENHASHTABLE_H_
#define OPENHASHTABLE_H_

#include <string>
#include <iostream>
using namespace std;

#include "PointerList.h"
const int MAXBUCKETS = 100000;

class OpenHashTable {
public:
	OpenHashTable(int b);
	~OpenHashTable();
	void MAKENULL();
	bool MEMBER(string x);
	void INSERT(string x);
	void DELETE (string x);
	void SETB(int b);

private:
	int B;
	PointerList<string>* table[MAXBUCKETS];
	int h(string s);
};

OpenHashTable::OpenHashTable(int b)
{
	B = b;
	for (int i = 0; i < MAXBUCKETS; i++)
		table[i] = NULL;
	for (int i = 0; i < B; i++)
		table[i] = new PointerList<string>;
}

OpenHashTable::~OpenHashTable()
{
	MAKENULL();
	cout << "killing hash table" << endl;
}
void OpenHashTable::MAKENULL()
{
	for (int i = 0; i < B; i++)
	{
		table[i]->MAKENULL();
		table[i] = NULL;
	}
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
	//cout << "GENERATED KEY FOR INSERTION: " << bucket << endl;
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
		else
			p = p->next;
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

void OpenHashTable::SETB(int b)
{
	MAKENULL();
	B = b;
		for (int i = 0; i < B; i++)
			table[i] = new PointerList<string>;

}


#endif /* OPENHASHTABLE_H_ */
