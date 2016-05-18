#pragma once
#include "SolveState.h"
#include "SecondLayerState.h"

class CornerState : public SolveState
{
	public:
		CornerState(vector<Piece* >* cube);
		~CornerState();

		int GetNextTurn();
		vector<int > insertCorner_;
		int InsertCorner(int target2, vector<int> vector);
		int nextTurn_;
		SolveState* GetNewState();
		int TakeOutCorner();
		//queue<Piece* > targetPieces_;
		int SolveCorner(int target1, int target, int side1, int side2, int upSide1, int upSide2);
};

