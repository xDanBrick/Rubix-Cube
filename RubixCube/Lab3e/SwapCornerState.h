#pragma once
#include "SolveState.h"
#include "FinalState.h"
class SwapCornerState : public SolveState
{
	public:
		SwapCornerState(Cube* cube);
		~SwapCornerState();
		vector<int > flipEdge_;

		SolveState* GetNewState();
		int GetNextTurn();
		int SolveTopCross();
		int CheckCorners();
		Piece* piece2_;
		int state_;
		enum STATE{DONE, ONE, NONE, TURN};
};

