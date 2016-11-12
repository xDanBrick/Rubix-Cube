#include "Algorithm.h"

enum TURN {
	right = 0, rightIn, mid, midIn, left, leftIn,
	up, upIn, midU, midUIn, down, downIn,
	front, frontIn, midF, midFIn, back, backIn, none
};

int sexy[12] = { up, right, upIn, rightIn };

Algorithm::Algorithm()
{
	
	cross_ = { front, right, up, rightIn, upIn, frontIn };
	rotateCorners_ = { rightIn, down, right, downIn };
	rotateTopEdges_ = { right, up, rightIn, up, right, up, up, rightIn };
	swapTopCorners_ = { up, right, upIn, left, up, rightIn, upIn, left };

	sexyMove_ = CreateAlgorithm(sexy, 4);

	currentMove_ = 0;
}

Algorithm::~Algorithm()
{
}

vector<int > Algorithm::InsertCorner(int edge, int upDir)
{
	int dis = CheckInverted(edge);
	vector<int > vector = {edge, upDir, (edge + dis)};
	return vector;
}

vector<int > Algorithm::InsertEdge(int edge)
{
	int dis = CheckInverted(edge);
	vector<int > vector = { up, edge, upIn, (edge + dis) };
	return vector;
}


vector<int > Algorithm::Insert2ndEdge(int edge, int edge2)
{
	int dis = CheckInverted(edge);
	int dis2 = CheckInverted(edge2);
	vector<int > vector = { edge, edge2, edge, edge2, edge, (edge2 + dis2), (edge + dis), (edge2 + dis2), (edge + dis) };
	return vector;
}

vector<int > Algorithm::TakeOutEdge(int edge)
{
	int dis = CheckInverted(edge);
	vector<int > vector = { edge, up, (edge + dis) };
	return vector;
}

vector<int>  Algorithm::CreateAlgorithm(int turn[12], int size)
{
	vector<int > vector;
	for (int i = 0; i < size + 2; i++)
	{
		vector.push_back(turn[i]);
	}
	return vector;
}

vector<int > Algorithm::FlipEdge(int edge, int middle)
{
	int dis = CheckInverted(middle);
	vector<int > vector = { edge, edge, up, middle, upIn, (middle + dis) };
	return vector;
}

vector<int > Algorithm::SwapCorners(int edge, int edge2)
{
	int dis = CheckInverted(edge);
	int dis2 = CheckInverted(edge2);
	vector<int > vector = {up, edge, upIn, edge2, up, (edge + dis), upIn, (edge2 + dis2)};
	return vector;
}

vector<int > Algorithm::FlipCorner(int edge, int middle)
{
	int dis = CheckInverted(edge);
	vector<int > vector{edge, up, (edge + dis), upIn, edge, up, (edge + dis), upIn, edge, up, (edge + dis)};
	return vector;
}

vector<int > Algorithm::RotateCorner(int edge, int upDir)
{
	int dis = CheckInverted(edge);
	int upDis = CheckInverted(upDir);
	vector<int > vector = {edge, upDir, (edge + dis), (upDir + upDis), edge, upDir, upDir, (edge + dis), (upDir + upDis), edge, upDir, (edge + dis)};
	return vector;
}
