#pragma once
#include "SolveState.h" 

class FinalState : public SolveState
{
	public:
		FinalState(vector<Piece* >* cube);
		~FinalState();

		vector<int > flipEdge_;
		int FlipEdge(int target, int edge, int middle, int dir);
		SolveState* GetNewState();
		int GetNextTurn();
		enum STATE{ DONE, NONE, ONE, TURN, ROTATE };
		int state_;
		int CheckEdges();
		int counter_;
};

