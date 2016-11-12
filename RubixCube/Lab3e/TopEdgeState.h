#pragma once
#include "SolveState.h"
#include "SwapCornerState.h"

class TopEdgeState : public SolveState
{
	public:
		TopEdgeState(Cube* cube);
		~TopEdgeState();

		vector<int > flipEdge_;
		int FlipEdge(int target, int edge, int middle, int dir);
		SolveState* GetNewState();
		int GetNextTurn();
		enum STATE{DONE, NONE, LINE, ARROW, TURN};
		int state_;
		int CheckEdges();
};

