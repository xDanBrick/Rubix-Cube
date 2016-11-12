#pragma once
#include "Edge.h"
#include "Corner.h"
#include "Mesh.h"
#include "Input.h"
#include "Centres.h"
#include <vector>
#include "Piece.h"
#include "Turn.h"
#include "Algorithm.h"

enum TURN {
	right = 0, rightIn, mid, midIn, left, leftIn,
	up, upIn, midU, midUIn, down, downIn,
	front, frontIn, midF, midFIn, back, backIn, none
};


enum DIRECTION { X, Y, Z };

using std::vector;

class Cube
{
	public:
		Cube();
		~Cube();
		vector<Turn* > moves_;
		inline void MixCube() { state_ = MIX; };
		inline void SelectPiece(Piece* piece) { piece->SelectPiece(); selected_.push_back(piece); };
		void Render();
		Mesh mesh;
		vector<Piece*> cube_;
		void Reset();
		void Update();
		void DoAlgorithm();
		bool IsMoving();
		vector<Piece*> selected_;
		void SelectSide(int side[9], int type);
		int type_;
		bool isMoving_;
		void RotateSelected(float angle);
		void MakeTurn(Turn* turn);
		Algorithm currentAlgorithm_;
		bool doingAlgorithm_;
	private:
		void Mix();
		enum STATE{MIX, WAIT, TURN};
		STATE state_;
		int mixerTurn_;
		void AddToSelected(int turn[9]);
		int currentTurn_;
		bool mixing_;
};

