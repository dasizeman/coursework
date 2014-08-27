/*
 * dfs.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: dave
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct cost_record{
	int index;
	int cost;
	cost_record(int, int);
};

cost_record::cost_record(int i, int c)
{
	index = i;
	cost = c;
}

struct vertex{
	string label; // The label of this vertex
	vector<cost_record> adj; // The adjacent vertices to this one and costs to get there
	vertex(string);
};

vertex::vertex(string lab)
{
	label = lab;
}


void dfs(vector<vertex> & v,vector<bool> & mark, int i, int & count);

int main()
{
	// Create the test graph (using the adjacency list model)
	vector<vertex> graph;
	graph.push_back(*(new vertex("a"))); // 0
	graph.push_back(*(new vertex("b")));// 1
	graph.push_back(*(new vertex("c"))); // 2
	graph.push_back(*(new vertex("d"))); // 3
	graph.push_back(*(new vertex("e"))); // 4
	graph.push_back(*(new vertex("f")));// 5

    // Adj to a
	graph[0].adj.push_back(*(new cost_record(1,3)));
	graph[0].adj.push_back(*(new cost_record(3,4)));
	graph[0].adj.push_back(*(new cost_record(5,5)));

	 // Adj to b
	graph[1].adj.push_back(*(new cost_record(2,1)));
	graph[1].adj.push_back(*(new cost_record(5,1)));

	 // Adj to c
	graph[2].adj.push_back(*(new cost_record(3,2)));

	 // Adj to d
	graph[3].adj.push_back(*(new cost_record(1,3)));

	 // Adj to e
	graph[4].adj.push_back(*(new cost_record(3,3)));
	graph[4].adj.push_back(*(new cost_record(5,2)));

	// Adj to f
	graph[5].adj.push_back(*(new cost_record(3,2)));

	// Run the algorithm
	for (int i = 0; i < 6; i++)
	{
		cout << "DFS STARTING AT " << graph[i].label << endl;
		int count = 1;
		vector<bool> mark(graph.size());
		dfs(graph,mark,i,count);
		cout << "-----------" << endl;
	}




	return 0;
}

void dfs(vector<vertex> & v, vector<bool> & mark, int i, int & count)
{
	cout << v[i].label << " : " << count << endl;
	count++;
	mark[i] = true;
	for (unsigned int j = 0; j < v[i].adj.size(); j++)
	{
		if (!mark[v[i].adj[j].index])
			dfs(v,mark, v[i].adj[j].index, count);
	}

}




