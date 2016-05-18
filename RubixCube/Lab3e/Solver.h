#pragma once
#include "CubeInput.h"
#include "Turn.h"
#include "CrossState.h"
//#include "Server.h"

class Solver : public CubeInput
{
	public:
		Solver(Input* input, vector<Piece*>* cube);
		~Solver();
		void Solve();
		SolveState* currentState_;
	//	Server* server_;
};

