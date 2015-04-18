#include "Dijkstra.h"

GRAPH graph;
POT potNodes;
POTNODE last;

int main()
{

	/* 
		Graph structure
		A[1,2]=4, A[1,3]=1, A[1,4]=5, A[1,5]=8, A[1,6]=10, 
		A[3,2]=2, A[4,5]=2, A[5,6]=1 
	*/

	cout << "Dijkstra shortest paths algorithm" << endl; 
	cout << "Testing with problem 6 of review 2." << endl;

	CELL* cell12 = new CELL;
	cell12->nodeLabel = 4;
	cell12->nodeName = 2;
	
	CELL* cell13 = new CELL;
	cell13->nodeLabel = 1;
	cell13->nodeName = 3;
	
	CELL* cell14 = new CELL;
	cell14->nodeLabel = 5;
	cell14->nodeName = 4;
	
	CELL* cell15 = new CELL;
	cell15->nodeLabel = 8;
	cell15->nodeName = 5;
	
	CELL* cell16 = new CELL;
	cell16->nodeLabel = 10;
	cell16->nodeName = 6;

	CELL* cell32 = new CELL;
	cell32->nodeLabel = 2;
	cell32->nodeName = 2;

	CELL* cell45 = new CELL;
	cell45->nodeLabel = 2;
	cell45->nodeName = 5;

	CELL* cell56 = new CELL;
	cell56->nodeLabel = 1;
	cell56->nodeName = 6;
	
	graph[1].successors = cell12;
	cell12->next = cell13;
	cell13->next = cell14;
	cell14->next = cell15;
	cell15->next = cell16;
	cell16->next = NULL;

	graph[3].successors = cell32;
	cell32->next = NULL;

	graph[4].successors = cell45;
	cell45->next = NULL;

	graph[5].successors = cell56;
	cell56->next = NULL;

	Dijkstra(graph, potNodes, &last);

	for(int i = 1; i < 7; i++)
		cout << "D[" << i << "]"<< " = " << graph[i].dist << endl;

	return 0;
}