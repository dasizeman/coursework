#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 100
#define INFTY 1E30

typedef int NODE;
typedef int POTNODE;

typedef struct CELL *LIST;
struct CELL {
	NODE nodeName;
	float nodeLabel;
	LIST next;
};

typedef struct GNODE {
	float dist;
	LIST successors;
	POTNODE toPOT;
} GRAPH[MAX];

typedef NODE POT[MAX+1];

void Dijkstra(GRAPH G, POT P, int *pLast);

