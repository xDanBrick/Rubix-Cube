#pragma once
#include "Turn.h"
#include "Algorithm.h"
#include "Centres.h"
#include "Edge.h"
#include "Corner.h"
#include <queue>
#include "Cube.h"
using std::queue;

class SolveState
{
	public:
		SolveState(Cube* cube);
		~SolveState();
		Cube* cube_;
		Mesh mesh;
		int step_;
		Piece* LookFor(int position);
		Algorithm* algorithm_;
		virtual int GetNextTurn() = 0;
		int currentMove_;
		Piece* piece;
		inline void CheckPieceFlipped(){ if (targetPieces_.front()->IsFlipped()){ piece->flipped_ = true; } };
		bool isBeingSolved_;
		virtual SolveState* GetNewState() = 0;
		int beingSolved_;
		int target_[5];
		int DoAlgorithm(vector<int> algorithm, int target);
		int DoAlgorithm1(vector<int> algorithm, int target);
		void CalculatePiece();
		inline void ResetCurrentPosition(){ if (currentMove_ == currentAlgorithm_.size() - 1){ currentMove_ = -1; }; };
		vector<int> currentAlgorithm_;
		void GetTargetPieces(int pos1, int pos2, int pos3, int pos4);
		queue<Piece* > targetPieces_;
		int GetQuickestMove(int turn, int target);
		int DoSortingAlgorithm(vector<int> algorithm);
		void IsPieceStuck(int target1, int target2);
		inline bool PositionIs(int pos){ if (targetPieces_.front()->GetPosition() == pos){ return true; }return false; };
};

