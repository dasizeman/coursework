#include "Dijkstra.h"

void swap(POTNODE a, POTNODE b, GRAPH G, POT P)
{
	NODE temp; /* used to swap POT nodes */

	temp = P[b];
	P[b] = P[a];
	P[a] = temp;
	G[P[a]].toPOT = a;
	G[P[b]].toPOT = b;
}

float priority(POTNODE a, GRAPH G, POT P)
{
	return G[P[a]].dist;
}

void bubbleUp(POTNODE a, GRAPH G, POT P)
{
	if ((a > 2) &&
			(priority(a, G, P) < priority(a/2, G, P))) {
		swap(a, a/2, G, P);
		bubbleUp(a/2, G, P);
	}
}

void bubbleDown(POTNODE a, GRAPH G, POT P, int last)
{
	POTNODE child;

	child = 2*a;
	if (child < last &&
						priority(child+1, G, P) < priority(child, G, P))
		++child;
	if (child <= last &&
			priority(a, G, P) > priority(child, G, P)) {
		swap(a, child, G, P);
		bubbleDown(child, G, P, last);
	}
}

void initialize(GRAPH G, POT P, int *pLast)
{
	int i; /* we use i as both a graph and a tree node */

	for (i = 1; i < MAX; i++) {
		G[i].dist = INFTY;
		G[i].toPOT = i+1;
		P[i+1] = i;
	}
	G[1].dist = 0;
	(*pLast) = MAX;
}

void Dijkstra(GRAPH G, POT P, int *pLast)
{
	NODE u, v; /* v is the node we select to settle */
	LIST ps; /* ps runs down the list of successors of v;
			u is the successor pointed to by ps */

	initialize(G, P, pLast);
	while ((*pLast) > 2) {
		v = P[2];
		swap(2, *pLast, G, P);
		--(*pLast);
		bubbleDown(2, G, P, *pLast);
		ps = G[v].successors;
		while (ps != NULL) {
			u = ps->nodeName;
			if (G[u].dist > G[v].dist + ps->nodeLabel) {
				G[u].dist = G[v].dist + ps->nodeLabel;
				bubbleUp(G[u].toPOT, G, P);
			}
			ps = ps->next;
		}
	}
}

