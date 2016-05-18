#include "SwapCornerState.h"

SwapCornerState::SwapCornerState(vector<Piece* >* cube)
{
	cube_ = cube;
	target_[0] = FUR;
	target_[1] = BUR;
	target_[2] = BUL;
	target_[3] = FUL;
	GetTargetPieces(FUR, BUR, BUL, FUL);
}


SwapCornerState::~SwapCornerState()
{
}


SolveState* SwapCornerState::GetNewState()
{
	return new FinalState(cube_);
}
int SwapCornerState::GetNextTurn()
{
	if (currentMove_ == flipEdge_.size() - 1)
	{
		//isBeingSolved_ = false;
		currentMove_ = -1;
	}
	state_ = CheckCorners();
	if (state_ == DONE)
	{
		isBeingSolved_ = false;
		return up;
	}
	if (state_ == TURN)
	{
		return up;
	}
	if (state_ == ONE)
	{
		currentMove_++;
		return flipEdge_[currentMove_];
	}
	return up;
}

int SwapCornerState::CheckCorners()
{
	if (currentMove_ != -1)
	{
		return state_;
	}
	vector<Piece*> pieces;
	pieces.push_back(LookFor(target_[0]));
	pieces.push_back(LookFor(target_[1]));
	pieces.push_back(LookFor(target_[2]));
	pieces.push_back(LookFor(target_[3]));
	Piece* piece = LookFor(FU);
	int counter = 0;
	
	if (piece->GetPosition() == FU && piece->GetPosition() == piece->GetStartPosition())
	{
		if (pieces[0]->GetPosition() == pieces[0]->GetStartPosition())
		{
			counter++;
			flipEdge_ = algorithm_->SwapCorners(right, left);
		}
		if (pieces[1]->GetPosition() == pieces[1]->GetStartPosition())
		{
			counter++;
			flipEdge_ = algorithm_->SwapCorners(backIn, frontIn);
		}
		if (pieces[2]->GetPosition() == pieces[2]->GetStartPosition())
		{
			counter++;
			flipEdge_ = algorithm_->SwapCorners(leftIn, rightIn);
		}
		if (pieces[3]->GetPosition() == pieces[3]->GetStartPosition())
		{
			counter++;
			flipEdge_ = algorithm_->SwapCorners(front, back);
		}
		if (counter == 0)
		{
			counter++;
			flipEdge_ = algorithm_->SwapCorners(right, left);
		}
		if (counter == 4)
		{
			return DONE;
		}

		return ONE;
	}
	if (counter == pieces.size())
	{
		//return DONE;
	}
	return TURN;
}
