#include "AIController.h"

AIController::AIController(Input* input, Cube* cube) : Controller(cube)
{
	//cube_ = cube;
	//currentState_ = new CrossState(cube);
}

AIController::~AIController()
{
}

void AIController::Solve()
{
	/*if (currentState_->isBeingSolved_ == false)
	{
		currentState_ = currentState_->GetNewState();
	}*/
	//if (IsMoving() == false)
	//{
	//	int turn = currentState_->GetNextTurn();
	//	if (turn != none)
	//	{
	//		//MakeTurn(turnType_->moves_[turn]);
	//	}
	//}
}

