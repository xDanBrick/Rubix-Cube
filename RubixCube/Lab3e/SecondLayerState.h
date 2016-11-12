#pragma once
#include "SolveState.h"
#include "TopLayerState.h"

class SecondLayerState : public SolveState
{
	public:
		SecondLayerState(Cube* cube);
		~SecondLayerState();
		int GetNextTurn();
		SolveState* GetNewState();
		int SolveEdge(int target1, int target2, int side1, int side2, int upSide1, int upSide2);
};

