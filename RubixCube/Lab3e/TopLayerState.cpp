#include "TopLayerState.h"

TopLayerState::TopLayerState(vector<Piece* >* cube)
{
	cube_ = cube;
	GetTargetPieces(FU, BU, LU, RU);
	state_ = CheckCross();
}


TopLayerState::~TopLayerState()
{
}

SolveState* TopLayerState::GetNewState()
{
	return new TopEdgeState(cube_);
}
int TopLayerState::GetNextTurn()
{
	ResetCurrentPosition();
	if (state_ == NONE)
	{
		return DoSortingAlgorithm(algorithm_->cross_);
	}
	if (state_ == LINE)
	{
		return DoAlgorithm(algorithm_->cross_, LU);
	}
	return up;
}
int TopLayerState::SolveTopCross()
{
	
	return 0;
}

int TopLayerState::CheckCross()
{
	queue<Piece*> flipped;

	for (int i = 0; i < 4; i++)
	{
		if (targetPieces_.front()->color1_ != targetPieces_.front()->startColor1_)
		{
			flipped.push(targetPieces_.front());
		}
		targetPieces_.pop();
	}
	targetPieces_ = flipped;
	if (targetPieces_.size() == 0)
	{
		return DONE;
	}
	else if (targetPieces_.size() == 4)
	{
		return NONE;
	}
	else if (targetPieces_.size() == 2)
	{
		if (targetPieces_.front()->GetPosition() == LU && targetPieces_.back()->GetPosition() == RU || targetPieces_.front()->GetPosition() == RU && targetPieces_.back()->GetPosition() == LU
			|| targetPieces_.front()->GetPosition() == FU && targetPieces_.back()->GetPosition() == BU || targetPieces_.front()->GetPosition() == BU && targetPieces_.back()->GetPosition() == FU)
		{
			return LINE;
		}
		return NONE;
	}
	return up;
}