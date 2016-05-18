#include "FinalState.h"


FinalState::FinalState(vector<Piece* >* cube)
{
	cube_ = cube;
	target_[0] = BUR;
	target_[1] = BUL;
	target_[2] = FUL;
	target_[3] = FUR;
	GetTargetPieces(BUR, BUL, FUL, FUR);
	state_ = CheckEdges();
	counter_ = 0;
	flipEdge_ = algorithm_->rotateCorners_;
}


FinalState::~FinalState()
{
}

int FinalState::FlipEdge(int target, int edge, int middle, int dir)
{
	return 0;
}
SolveState* FinalState::GetNewState()
{
	return this;
}
int FinalState::GetNextTurn()
{
	if (currentMove_ == flipEdge_.size() - 1)
	{
		currentMove_ = -1;
	}
	state_ = CheckEdges();
	if (state_ == DONE)
	{
		isBeingSolved_ = false;
		return none;
	}
	if (state_ == ONE)
	{
		currentMove_++;
		return flipEdge_[currentMove_];
	}
	return up;
}

int FinalState::CheckEdges()
{
	if (currentMove_ > -1)
	{
		return state_;
	}
	vector<Piece*> pieces;
	pieces.push_back(LookFor(target_[0]));
	pieces.push_back(LookFor(target_[1]));
	pieces.push_back(LookFor(target_[2]));
	pieces.push_back(LookFor(target_[3]));
	Piece* piece1 = LookFor(FUR);
	counter_++;
	if (counter_ == 1 || counter_ == 5 || counter_ == 15)
	{
		return ROTATE;
	}
	if (counter_ > 15)
	{
		return DONE;
	}
	return ONE;
}
