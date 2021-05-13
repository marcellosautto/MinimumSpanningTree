#include "MST.h"

MST::MST()
{
}

bool MST::run()
{
	initializeMST();
	//printMST();
	sortMST();
	printMST();
	kruskalsAlg();
	printMST();
	printSG();

	return false;
}

void MST::initializeMST()
{
	ifstream inFile("data.txt");

	while (!inFile.eof())
	{
		Edge edge;
		inFile >> edge.startVertex;
		inFile >> edge.endVertex;
		inFile >> edge.weight;

		minimumSpanningTree.emplace_back(edge);

	}
}

void MST::sortMST()
{
	/* Function to sort an array using insertion sort*/

	int i, j;
	for (i = 1; i < minimumSpanningTree.size(); i++)
	{
		Edge key = minimumSpanningTree[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && minimumSpanningTree[j].weight > key.weight) //sort by weight
		{
			minimumSpanningTree[j + 1] = minimumSpanningTree[j];
			j = j - 1;
		}
		minimumSpanningTree[j + 1] = key;
	}
}

void MST::printMST()
{
	for (int i = 0; i < minimumSpanningTree.size(); i++)
	{
		cout << minimumSpanningTree[i].startVertex+1 << " " << minimumSpanningTree[i].endVertex+1 << " " << minimumSpanningTree[i].weight << endl;
	}

	cout << "------------------------------" << endl << endl;
}

void MST::kruskalsAlg()
{
	
	for (int i = 0; i < minimumSpanningTree.size(); i++)
	{
		bool cycles = false;
		for (int j = 0; j < subGraph.size(); j++)
		{
			if (minimumSpanningTree[i].endVertex == subGraph[j].startVertex || minimumSpanningTree[i].endVertex == subGraph[j].endVertex) //if this vertex forms a cycle, ignore it
			{
				cycles = true;
			}
				
		}

		if (cycles == false) //if the vertex doesnt cycle, add it to the subgraph
			subGraph.emplace_back(minimumSpanningTree[i]);
	
	}
}

void MST::printSG()
{
	
	int totalWeight = 0;
	for (int i = 0; i < subGraph.size(); i++)
	{
		cout << subGraph[i].startVertex+1 << " - " << subGraph[i].endVertex+1 << " = " << subGraph[i].weight << endl;
		totalWeight += subGraph[i].weight;
	}

	cout << "------------------------------" << endl << endl;

	cout << "Total Weight = " << totalWeight << endl;
}
