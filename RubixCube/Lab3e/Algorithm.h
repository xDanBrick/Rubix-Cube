#pragma once
#include "TurnType.h"
#include <vector>

using std::vector;

class Algorithm
{
	public:
		Algorithm();
		~Algorithm();
		TurnType* turnType_;
		vector<int >  CreateAlgorithm(int turn[12], int size);
		vector<int > sexyMove_;
		vector<int > cross_;
		vector<int > rotateTopEdges_;
		vector<int > swapTopCorners_;
		vector<int > rotateCorners_;
		vector<int > FlipEdge(int edge, int middle);
		vector<int > FlipCorner(int edge, int middle);
		vector<int > RotateCorner(int edge, int upDir);
		vector<int > InsertCorner(int edge, int upDir);
		vector<int > Insert2ndEdge(int edge, int edge2);
		vector<int > InsertEdge(int edge);
		vector<int > SwapCorners(int edge, int edge2);
		vector<int > TakeOutEdge(int edge);
		inline int CheckInverted(int edge){ if (edge % 2 == 0){ return 1; } return -1; };
};

