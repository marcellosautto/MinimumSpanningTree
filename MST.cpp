#include "MST.h"

MST::MST()
{
	parents.resize(graph->V+1);
}

bool MST::run()
{
	
	initializeMST();
	sortMST();
	kruskalsAlg();
	printGraph();
	printMST();


	return false;
}

void MST::initializeMST() //initialize graph with txt file
{
	ifstream inFile("data.txt");

	int i = 0;
	while (!inFile.eof())
	{
		inFile >> graph->edge[i].startVertex;
		inFile >> graph->edge[i].endVertex;
		inFile >> graph->edge[i].weight;
		i++;
	}
}

void MST::sortMST()
{
	/* Function to sort an array using insertion sort*/

	int i, j;
	for (i = 1; i < graph->E; i++)
	{
		Edge key = graph->edge[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && graph->edge[j].weight > key.weight) //sort by weight
		{
			graph->edge[j + 1] = graph->edge[j];
			j = j - 1;
		}
		graph->edge[j + 1] = key;
	}
}

void MST::printGraph()
{
	cout << "Original Graph\n";
	cout << "--------------\n";
	for (int i = 0; i < graph->E; i++)
	{
		cout << graph->edge[i].startVertex << " " << graph->edge[i].endVertex << " " << graph->edge[i].weight << endl;
	}
	cout << endl;
}


int MST::find(int x)
{
	if (parents[x] == x)
	{
		return x;
	}

	return find(parents[x]);
}

void MST::unite(int x, int y)
{
	int px = find(x);
	int py = find(y);
	parents[px] = py;
}

void MST::kruskalsAlg()
{
	for (int i = 0; i < graph->V; i++)
	{
		parents[i] = i;
	}

	for (int i = 0; i < graph->E; i++)
	{
		if (find(graph->edge[i].startVertex) != find(graph->edge[i].endVertex)) //if the edge does not form a cycle, add it to the minimum spanning tree
		{
			minimumSpanningTree.emplace_back(graph->edge[i]);
			unite(graph->edge[i].startVertex, graph->edge[i].endVertex);
		}
	}
}

void MST::printMST() //print original graph then minimum spanning tree
{
	cout << "Minimum Spanning Tree\n";
	cout << "---------------------\n";
	int totalWeight = 0;
	for (int i = 0; i < minimumSpanningTree.size(); i++)
	{
		cout << minimumSpanningTree[i].startVertex << " - " << minimumSpanningTree[i].endVertex << " = " << minimumSpanningTree[i].weight << endl;
		totalWeight += minimumSpanningTree[i].weight;
	}

	cout << "---------------------\n\n";

	cout << "Total Weight = " << totalWeight << endl;
}
