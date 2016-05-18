#pragma once
#include <vector>
#include "Piece.h"
#include "Input.h"
#include "Turn.h"
#include "TurnType.h"

using std::vector;

class CubeInput
{
	public:
		CubeInput();
		~CubeInput();
		bool isMoving_;
		bool IsMoving();
		int currentMove_;
		vector<Piece*> selected;
		vector<Piece*>* cube_;
		enum TYPE{ X, Y, Z };
		Input* input_;
		void Reset();
		int currentTurn_;
		inline void SelectPiece(Piece* piece){ piece->SelectPiece(); selected.push_back(piece); };
		void AddToSelected(int turn[9]);
		void Mix();
		TurnType* turnType_;
		int state_;
		int mixerTurn_;
		void MakeTurn(Turn* turn);
		int type_;
		void SelectSide(int side[9], int type);
		void RotateSelected(float angle);
		float turn;
		virtual void Update();
		enum STATE{MIX, SOLVE, SEXY, WAIT};
		virtual void Solve() = 0;
		void Wait();
		void Sexy();
		int mixerMax_;
		
};

