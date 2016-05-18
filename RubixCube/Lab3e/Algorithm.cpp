#include "Algorithm.h"

int cross[12] = { front, right, up, rightIn, upIn, frontIn };
int sexy[12] = { up, right, upIn, rightIn};
int rotateCorner[4] = { rightIn, down, right, downIn };
int topEdges[8] = { right, up, rightIn, up, right, up, up, rightIn };
int topCorners[8] = { up, right, upIn, left, up, rightIn, upIn, left };

Algorithm::Algorithm()
{
	for (int i = 0; i < 6; i++)
	{
		cross_.push_back(cross[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		rotateCorners_.push_back(rotateCorner[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		rotateTopEdges_.push_back(topEdges[i]);
		swapTopCorners_.push_back(topCorners[i]);
	}
	sexyMove_ = CreateAlgorithm(sexy, 4);
}

Algorithm::~Algorithm()
{
}

vector<int > Algorithm::InsertCorner(int edge, int upDir)
{
	int dis = CheckInverted(edge);
	vector<int > vector;
	vector.push_back(edge);
	vector.push_back(upDir);
	vector.push_back(edge + dis);
	return vector;
}

vector<int > Algorithm::InsertEdge(int edge)
{
	int dis = CheckInverted(edge);
	vector<int > vector;
	vector.push_back(up);
	vector.push_back(edge);
	vector.push_back(upIn);
	vector.push_back(edge + dis);
	return vector;
}


vector<int > Algorithm::Insert2ndEdge(int edge, int edge2)
{
	int dis = CheckInverted(edge);
	int dis2 = CheckInverted(edge2);
	vector<int > vector;
		vector.push_back(edge);
		vector.push_back(edge2);
		vector.push_back(edge);
		vector.push_back(edge2);
		vector.push_back(edge);
		vector.push_back(edge2 + dis2);
		vector.push_back(edge + dis);
		vector.push_back(edge2 + dis2);
		vector.push_back(edge + dis);
	return vector;
}


vector<int > Algorithm::TakeOutEdge(int edge)
{
	int dis = CheckInverted(edge);
	vector<int > vector;
	vector.push_back(edge);
	vector.push_back(up);
	vector.push_back(edge + dis);
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
	vector<int > vector;
	vector.push_back(edge);
	vector.push_back(edge);
	vector.push_back(up);
	vector.push_back(middle);
	vector.push_back(upIn);
	vector.push_back(middle+dis);
	return vector;
}

vector<int > Algorithm::SwapCorners(int edge, int edge2)
{
	int dis = CheckInverted(edge);
	int dis2 = CheckInverted(edge2);
	vector<int > vector;
	vector.push_back(up);
	vector.push_back(edge);
	vector.push_back(upIn);
	vector.push_back(edge2);
	vector.push_back(up);
	vector.push_back(edge + dis);
	vector.push_back(upIn);
	vector.push_back(edge2 + dis2);
	return vector;
}

vector<int > Algorithm::FlipCorner(int edge, int middle)
{
	int dis = CheckInverted(edge);
	vector<int > vector;
	vector.push_back(edge);
	vector.push_back(up);
	vector.push_back(edge + dis);
	vector.push_back(upIn);

	vector.push_back(edge);
	vector.push_back(up);
	vector.push_back(edge + dis);
	vector.push_back(upIn);

	vector.push_back(edge);
	vector.push_back(up);
	vector.push_back(edge + dis);
	return vector;
}

vector<int > Algorithm::RotateCorner(int edge, int upDir)
{
	int dis = CheckInverted(edge);
	int upDis = CheckInverted(upDir);
	vector<int > vector;
	vector.push_back(edge);
	vector.push_back(upDir);
	vector.push_back(edge + dis);
	vector.push_back(upDir + upDis);
	vector.push_back(edge);

	vector.push_back(upDir);
	vector.push_back(upDir);
	vector.push_back(edge + dis);
	vector.push_back(upDir + upDis);

	vector.push_back(edge);
	vector.push_back(upDir);
	vector.push_back(edge + dis);
	return vector;
}
