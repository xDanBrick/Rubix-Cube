#pragma once
#include "SolveState.h"
#include "CornerState.h"

class CrossState : public SolveState
{
	public:
		CrossState(Cube* cube);
		~CrossState();
		int GetNextTurn();
		int Centres();
		int Cross();
		vector<int > flipEdge_;
		int FlipEdge(int target, int edge, int middle, int dir);
		SolveState* GetNewState();
		int SolveEdge();
};

