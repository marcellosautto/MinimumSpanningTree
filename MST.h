#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
class Edge
{
public:
	int startVertex;
	int endVertex;
	int weight;

};

class Graph
{
public:
	int V, E;
	Edge* edge;

};

class MST
{

	Graph* createGraph(int V, int E)
	{

		Graph* graph = new Graph;
		graph->V = V;
		graph->E = E;
		graph->edge = new Edge[E];
		return graph;
	}

public:
	MST();

	bool run();

	void initializeMST(),
		sortMST(),
		kruskalsAlg(),
		printGraph(),
		printMST(),
		unite(int x, int y);

	int find(int x);

	Graph* graph = createGraph(7, 12);
	vector<Edge> minimumSpanningTree;
	vector<int> parents;
};






