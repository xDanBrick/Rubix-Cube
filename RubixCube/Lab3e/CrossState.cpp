#include "CrossState.h"

CrossState::CrossState(vector<Piece* >* cube)
{
	cube_ = cube;
	turnType_ = algorithm_->turnType_;
	beingSolved_ = 0;
	GetTargetPieces(RD, LD, FD, BD);
	target_[0] = RD;
	target_[1] = LD;
	target_[2] = FD;
	target_[3] = BD;
}

CrossState::~CrossState()
{
}



SolveState* CrossState::GetNewState()
{
	return new CornerState(cube_);
}

int CrossState::GetNextTurn()
{
	switch (step_)
	{
		case 0: return Centres(); break;
		case 1: return Cross(); break;
	}
	return up;
}
int CrossState::Centres()
{
	piece = LookFor(D);
	if (piece->solved_ == false)
	{
		switch (piece->GetPosition())
		{
			case U: return mid;
			case B:	piece->solved_ = true; return mid;
			case F: piece->solved_ = true; return midIn;
			case L: piece->solved_ = true; return midFIn;
			case R: piece->solved_ = true; return midIn;
		}
	}
	piece = LookFor(F);
	if (piece->solved_ == false)
	{
		if (piece->GetPosition() == R || piece->GetPosition() == L)
		{
			step_++;
			piece->solved_ = true;
		}
		if (piece->GetPosition() == L)
		{
			return midUIn;
		}
		else
		{
			return midU;
		}
	}
	return NULL;
}

int CrossState::Cross()
{
	int nextMove;
	if (targetPieces_.front()->InStartingPosition())
	{
		targetPieces_.pop();
	}
	if (targetPieces_.empty())
	{
		isBeingSolved_ = false;
		return up;
	}
	ResetCurrentPosition();
	if (targetPieces_.front()->GetStartPosition() == RD)
	{
		switch (targetPieces_.front()->GetPosition())
		{
			case FD: nextMove = downIn; break;
			case BD: nextMove = down; break;
			case FR: nextMove = rightIn; break;
			case FL: nextMove = left; break;
			case BL: nextMove = leftIn; break;
			case FU: nextMove = upIn; break;
			case LU:
			case BU: nextMove = up; break;
			case BR:
			case RU: nextMove = right; break;
		}
		return nextMove;
	}
	if (targetPieces_.front()->GetStartPosition() == LD)
	{
		if (targetPieces_.front()->beingSolved == false)
		{
			if (PositionIs(FU) || PositionIs(BU))
			{
				CheckPieceFlipped();
				return GetQuickestMove(up, LU);
			}
			switch (targetPieces_.front()->GetPosition())
			{
				case FD: return front;
				case BD: return back;
				case FL: return leftIn;
				case FR: return frontIn;
				case BR: return backIn;
				case RU: return up;
				case BL:
				case LU: return left;
			}
		}
		return DoAlgorithm1(algorithm_->InsertEdge(midF), targetPieces_.front()->GetPosition());
	}
	if (targetPieces_.front()->GetStartPosition() == FD)
	{
		if (targetPieces_.front()->beingSolved == false)
		{
			if (PositionIs(RU) || PositionIs(LU))
			{
				CheckPieceFlipped();
				return GetQuickestMove(up, FU);
			}
			switch (targetPieces_.front()->GetPosition())
			{
				case FL: return frontIn;
				case BR: return backIn;
				case BU:
				case RU: return up;
				case FR:
				case FU: return front;
				case BL:
				case LD: return back;
			}
		}
		return DoAlgorithm1(algorithm_->FlipEdge(front, mid), targetPieces_.front()->GetPosition());
	}
	if (targetPieces_.front()->GetStartPosition() == BD)
	{
		IsPieceStuck(FL, FR);
		if (targetPieces_.front()->beingSolved == false && targetPieces_.front()->stuckPosition_ == 0)
		{
			if (PositionIs(LU) || PositionIs(RU))
			{
				CheckPieceFlipped();
				return GetQuickestMove(up, BU);
			}
			if (PositionIs(BR) || PositionIs(BU) || PositionIs(BL))
			{
				return back;
			}
		}
		else
		{
			if (targetPieces_.front()->stuckPosition_ == FR)
			{
				return DoSortingAlgorithm(algorithm_->TakeOutEdge(frontIn));
			}
			if (targetPieces_.front()->stuckPosition_ == FL)
			{
				return DoSortingAlgorithm(algorithm_->TakeOutEdge(front));
			}
		}
	}
	return up;
}

int CrossState::SolveEdge()
{
	IsPieceStuck(FL, FR);
	if (targetPieces_.front()->beingSolved == false && targetPieces_.front()->stuckPosition_ == 0)
	{
		if (targetPieces_.front()->GetPosition() == LU || targetPieces_.front()->GetPosition() == RU || targetPieces_.front()->GetPosition() == FU)
		{
			CheckPieceFlipped();
			return GetQuickestMove(up, BU);
		}
		if (targetPieces_.front()->GetPosition() == BR || targetPieces_.front()->GetPosition() == BU || targetPieces_.front()->GetPosition() == BL)
		{
			return back;
		}
	}
	else
	{
		if (targetPieces_.front()->stuckPosition_ == FR)
		{
			return DoSortingAlgorithm(algorithm_->TakeOutEdge(frontIn));
		}
		if (targetPieces_.front()->stuckPosition_ == FL)
		{
			return DoSortingAlgorithm(algorithm_->TakeOutEdge(front));
		}
	}
}