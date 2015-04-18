#include <string>

using namespace std;

struct celltype {
	char domain;
	celltype *value;  //pointer to first cell on list for the child node
	celltype *next;   //pointer to next cell on the list 
};

typedef celltype TrieNode;

typedef TrieNode* Trie;

void ASSIGN(TrieNode* n, char c, TrieNode* p);
TrieNode* VALUEOF(TrieNode* n, char c);
void GETNEW(TrieNode* n, char c);
void MAKENULL(TrieNode* n);
void INSERT (string x, Trie words);