#pragma once
#include "SolveState.h"
#include "TopEdgeState.h"

class TopLayerState : public SolveState
{
	public:
		TopLayerState(Cube* cube);
		~TopLayerState();
		vector<int > flipEdge_;

		SolveState* GetNewState();
		int GetNextTurn();
		int SolveTopCross();
		int CheckCross();
		Piece* piece2_;
		int state_;
		enum STATE{NONE, LINE, DONE};
};

