#include "CornerState.h"

//Check if stuck - stuck = true
//If get to target
//If flipped get to next target
//Insert targetPieces_.front()

CornerState::CornerState(vector<Piece* >* cube)
{
	cube_ = cube;
	nextTurn_ = 0;
	step_ = 0;
	beingSolved_ = 0;

	target_[0] = BDR;
	target_[1] = BDL;
	target_[2] = FDR;
	target_[3] = FDL;
	GetTargetPieces(BDR, BDL, FDR, FDL);
}


CornerState::~CornerState()
{
}

SolveState* CornerState::GetNewState()
{
	return new SecondLayerState(cube_);
}

int CornerState::GetNextTurn()
{
	if (targetPieces_.empty())
	{
		isBeingSolved_ = false;
		return up;
	}
	if (targetPieces_.front()->InStartingPosition())
	{
		targetPieces_.pop();
	}
	ResetCurrentPosition();
	if (targetPieces_.front()->GetStartPosition() == BDR)
	{
		IsPieceStuck(FDR, FDL);
		return SolveCorner(FUR, BUL, rightIn, backIn, up, upIn);
	}
	if (targetPieces_.front()->GetStartPosition() == BDL)
	{
		IsPieceStuck(FDR, BDL);
		return SolveCorner(FUL, BUR, leftIn, back, upIn, up);
	}
	if (targetPieces_.front()->GetStartPosition() == FDR)
	{
		IsPieceStuck(FDL, BDL);
		return SolveCorner(BUR, FUL, right, frontIn, upIn, up);
	}
	if (targetPieces_.front()->GetStartPosition() == FDL)
	{
		return DoAlgorithm1(algorithm_->RotateCorner(front, up), FDL);
	}
	return up;
}

int CornerState::TakeOutCorner()
{
	currentMove_++;
	switch (targetPieces_.front()->stuckPosition_)
	{
		case BDL: currentAlgorithm_ = algorithm_->InsertCorner(leftIn, up); break;
		case BDR: currentAlgorithm_ = algorithm_->InsertCorner(rightIn, up); break;
		case FDL: currentAlgorithm_ = algorithm_->InsertCorner(left, up); break;
		case FDR: currentAlgorithm_ = algorithm_->InsertCorner(right, up); break;
	}
	if (currentMove_ == currentAlgorithm_.size() - 1)
	{
		targetPieces_.front()->stuckPosition_ = 0;
	}
	return currentAlgorithm_[currentMove_];
}

int CornerState::SolveCorner(int target1, int target2, int side1, int side2, int upSide1, int upSide2)
{
	if (targetPieces_.front()->GetPosition() == target1 && targetPieces_.front()->color1_ == targetPieces_.front()->startColor1_)
	{
		targetPieces_.front()->flipped_ = true;
	}
	if (targetPieces_.front()->stuckPosition_ != 0)
	{
		return TakeOutCorner();
	}
	else if (targetPieces_.front()->flipped_ == true)
	{
		return DoAlgorithm1(algorithm_->InsertCorner(side1, upSide1), target2);
	}
	else if (PositionIs(targetPieces_.front()->GetStartPosition()) && !targetPieces_.front()->InStartingPosition())
	{
		return DoAlgorithm1(algorithm_->RotateCorner(back, upIn), targetPieces_.front()->GetStartPosition());
	}
	else
	{
		return DoAlgorithm1(algorithm_->InsertCorner(side2, upSide2), target1);
	}
}
