#include "SecondLayerState.h"

SecondLayerState::SecondLayerState(Cube* cube) : SolveState(cube)
{

	GetTargetPieces(FR, FL, BL, BR);
}


SecondLayerState::~SecondLayerState()
{
}

SolveState* SecondLayerState::GetNewState()
{
	return new TopLayerState(cube_);
}

int SecondLayerState::SolveEdge(int target1, int target2, int side1, int side2, int upSide1, int upSide2)
{
	if (targetPieces_.front()->color1_ != targetPieces_.front()->startColor1_ && targetPieces_.front()->GetPosition() == target1)
	{
		targetPieces_.front()->flipped_ == true;
	}
	if (targetPieces_.front()->stuckPosition_ > 0)
	{
		return DoSortingAlgorithm(algorithm_->Insert2ndEdge(right, up));
	}
	if (targetPieces_.front()->flipped_ == true)
	{
		return DoAlgorithm1(algorithm_->Insert2ndEdge(side1, upSide1), target1);
	}
	else
	{
		return DoAlgorithm1(algorithm_->Insert2ndEdge(side2, upSide2), target2);
	}
}

int SecondLayerState::GetNextTurn()
{
	if (targetPieces_.empty())
	{
		isBeingSolved_ = false;
		return none;
	}
	ResetCurrentPosition();
	if (targetPieces_.front()->InStartingPosition() == true && targetPieces_.front()->beingSolved == false)
	{
		targetPieces_.pop();
		return none;
	}
	switch (targetPieces_.front()->GetStartPosition())
	{
		case FR: return SolveEdge(RU, FU, rightIn, front, upIn, up);
		case FL: IsPieceStuck(BR, BR); return SolveEdge(FU, LU, frontIn, leftIn, upIn, up);
		case BL: return SolveEdge(BU, LU, backIn, left, up, upIn);
		case BR: return SolveEdge(RU, BU, right, back, up, upIn);
	}
	return none;
}
