#include "SolveState.h"

SolveState::SolveState(Cube* cube) : SolveState(cube)
{
	currentMove_ = -1;
	step_ = 0;
	isBeingSolved_ = true;
	beingSolved_ = 0;
	algorithm_ = new Algorithm();
}

SolveState::~SolveState()
{
}

Piece* SolveState::LookFor(int position)
{
	for (int i = 0; i < cube_->cube_.size(); i++)
	{
		if (cube_->cube_.at(i)->GetStartPosition() == position)
		{
			return cube_->cube_.at(i);
		}
	}
	return NULL;
}

int SolveState::DoAlgorithm(vector<int> algorithm, int target)
{
	if (piece->GetPosition() == target || piece->beingSolved == true)
	{
		piece->beingSolved = true;
		currentAlgorithm_ = algorithm;
		currentMove_++;
		if (currentMove_ == algorithm.size() - 1)
		{
			beingSolved_++;
		}
		return algorithm[currentMove_];
	}
	return up;
}

int SolveState::DoSortingAlgorithm(vector<int> algorithm)
{
	currentAlgorithm_ = algorithm;
	currentMove_++;
	if (currentMove_ == algorithm.size() - 1)
	{
		targetPieces_.front()->stuckPosition_ = 0;
	}
	return algorithm[currentMove_];
}

void SolveState::IsPieceStuck(int target1, int target2)
{
	if (targetPieces_.front()->GetPosition() == target1 || targetPieces_.front()->GetPosition() == target2)
	{
		targetPieces_.front()->stuckPosition_ = targetPieces_.front()->GetPosition();
	}
}

int SolveState::DoAlgorithm1(vector<int> algorithm, int target)
{
	if (targetPieces_.front()->GetPosition() == target || targetPieces_.front()->beingSolved == true)
	{
		targetPieces_.front()->beingSolved = true;
		currentAlgorithm_ = algorithm;
		currentMove_++;
		if (currentMove_ == algorithm.size() - 1)
		{
			targetPieces_.pop();
		}
		return algorithm[currentMove_];
	}
	return up;
}

void SolveState::CalculatePiece()
{

}

void SolveState::GetTargetPieces(int pos1, int pos2, int pos3, int pos4)
{
	targetPieces_.push(LookFor(pos1));
	targetPieces_.push(LookFor(pos2));
	targetPieces_.push(LookFor(pos3));
	targetPieces_.push(LookFor(pos4));
}

int SolveState::GetQuickestMove(int turn, int target)
{
	int type, turns;
	if (turn < 6)
	{
		type = XNORMAL;
	}
	else if (turn < 12)
	{
		type = YNORMAL;
	}
	else type = ZNORMAL;
	Edge* edge = new Edge(0, 0, targetPieces_.front()->GetPosition());
	for (int i = 1; i < 4; i++)
	{
		edge->CheckTurn(type, i);
		if (edge->GetPosition() == target)
		{
			turns = i;
		}
	}
	if (turns == 4)
	{
		return none;
	}
	if (turns == 3)
	{
		return turn+1;
	}
	return turn;
}