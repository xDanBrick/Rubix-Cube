#include "Solver.h"

Solver::Solver(Input* input, vector<Piece*>* cube)
{
	cube_ = cube;
	input_ = input;
	currentState_ = new CrossState(cube);
	//server_ = new Server();
}

Solver::~Solver()
{
}

void Solver::Solve()
{
	if (currentState_->isBeingSolved_ == false)
	{
		currentState_ = currentState_->GetNewState();
	}
	if (IsMoving() == false)
	{
		int turn = currentState_->GetNextTurn();
		if (turn != none)
		{
			MakeTurn(turnType_->moves_[turn]);
		}
	}
}

