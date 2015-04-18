#include "Trie.h"
#include <iostream>
#include <string>

using namespace std;

void ASSIGN(TrieNode* n, char c, TrieNode* p)
{
	TrieNode* t = n->value;
	while(t != NULL)
	{
		if(t->domain == c)
		{
			t->value = p;
			return;
		}
		t = t->next;
	}
	GETNEW(n, c);  //create new if not found
}

TrieNode* VALUEOF(TrieNode* n, char c)
{
	TrieNode* t = n->value;
	while(t != NULL)
	{	
		if(t->domain == c)
			return t; 
		t = t->next;
	}
	return NULL;
}

void GETNEW(TrieNode* n, char c)
{
	TrieNode* t = n->value;
	TrieNode* m = new TrieNode; 
	n->value = m;
	m->next = t;
	m->domain = c;
	m->value = NULL;
}

void MAKENULL(TrieNode* n)
{
	char c;
	TrieNode* m = n->value;
	n->value = NULL;
	TrieNode* temp = n->value;
	while(m != NULL)
	{
		m->value = NULL;
		temp = m->next;
		m = temp;
	}
}

void INSERT (string x, Trie words)
{
	int i; // counts positions in word x 
	Trie t; // used to point to trie nodes corresponding to prefixes of x 
	i = 0;
	t = words;
	while (x[i] != '\0')
	{
		if (VALUEOF(t, x[i]) == NULL)
		{
			// if current node has no child for character x[i], create one 
			GETNEW(t, x[i]);
		}
		t = VALUEOF(t, x[i]);
		// proceed to the child of t for character x[i], whether or not that child was just created 
		i++;	// move along the word x 
	}
	ASSIGN(t, '$', NULL);
	// now we have reached the first '\0' in x 
}