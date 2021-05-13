#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Edge
{
	int startVertex;
	int endVertex;
	int weight;

};

class MST
{
public:
	MST();

	bool run();

	void initializeMST(),
		sortMST(),
		kruskalsAlg(),
		printMST(),
		printSG();

	vector<Edge> minimumSpanningTree;
	vector<Edge> subGraph;
};


