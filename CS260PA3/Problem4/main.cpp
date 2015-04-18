#include "Trie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void print_trie(Trie t, string s="");

int size = 0;
int main()
{
	Trie t = new TrieNode;
	t->value = NULL;
	t->next = NULL;

	cout << "Loading trie" << endl;

	string word;
	ifstream in;
	in.open("AliceInWonderland.txt");
	ofstream out;
	out.open("all_words.txt");

	while(in >> word)
	{
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		INSERT(word, t);	
		out << word << endl;
	}
	out.close();

	print_trie(t);
	cout << "size: " << size << endl
		  << "Size refers to the number of words." << endl
		  << "(Symbols included, so \"this\" and \"'--this\" and \"this.\" are all different words)" << endl
		  << "See all_words.txt for all the words read from the file." << endl
		  << "See trie_result.txt for all the words stored in the trie." << endl;
	in.close();


	return 0;
}

void print_trie(Trie t, string s)
{
	TrieNode* n = t->value;
	if(t->domain == '$')
	{
		ofstream out;
		s = s.substr(0, s.size()-1);
		out.open("trie_result.txt", ios::app);
		out << s << endl;
		size++;
	}
	while(n != NULL)
	{
		char temp[2];
		temp[0] = n->domain;
		temp[1] = '\0';
		s.append(temp);
		print_trie(n, s);	
		s = s.substr(0, s.size()-1);
		n = n->next;
	}
}
