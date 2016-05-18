#include "TopEdgeState.h"

TopEdgeState::TopEdgeState(vector<Piece* >* cube)
{
	cube_ = cube;
	target_[0] = FU;
	target_[1] = BU;
	target_[2] = FL;
	target_[3] = FR;
	state_ = CheckEdges();
	GetTargetPieces(FU, BU, FL, FR);
	flipEdge_ = algorithm_->rotateTopEdges_;
}


TopEdgeState::~TopEdgeState()
{
}

int TopEdgeState::FlipEdge(int target, int edge, int middle, int dir)
{
	return 0;
}
SolveState* TopEdgeState::GetNewState()
{
	return new SwapCornerState(cube_);
}
int TopEdgeState::GetNextTurn()
{
	state_ = CheckEdges();
	if (state_ == LINE)
	{
		//return right;
	}
	if (state_ == DONE)
	{
		isBeingSolved_ = false;
		return up;
	}
	if (state_ == TURN)
	{
		return up;
	}
	if (state_ == LINE)
	{
		if (currentMove_ == flipEdge_.size() - 1)
		{
			currentMove_ = -1;
		}
		currentMove_++;
		return flipEdge_[currentMove_];
	}
	return up;
}

int TopEdgeState::CheckEdges()
{
	vector<Piece*> pieces;
	vector<Piece*> flipped;
	pieces.push_back(LookFor(target_[0]));
	pieces.push_back(LookFor(target_[1]));
	pieces.push_back(LookFor(target_[2]));
	pieces.push_back(LookFor(target_[3]));

	for (int i = 0; i < pieces.size(); i++)
	{
		if (currentMove_ != -1)
		{
			return state_;
		}
		else
		{
			if (pieces[i]->GetPosition() == pieces[i]->GetStartPosition() && pieces[i]->GetPosition() == FU)
			{
				for (int j = 0; j < 4; j++)
				{
					if (pieces[j]->GetPosition() == pieces[j]->GetStartPosition())
					{
						return DONE;
					}
				}
					return LINE;
			}
			else
			{
				return TURN;
			}
		}
	}
	return up;
}
