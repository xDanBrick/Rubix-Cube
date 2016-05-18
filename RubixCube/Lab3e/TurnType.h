#pragma once
#include "Turn.h"
#include "Piece.h"

enum TURN{
	right = 0, rightIn, mid, midIn, left, leftIn,
	up, upIn, midU, midUIn, down, downIn,
	front, frontIn, midF, midFIn, back, backIn, none
};

class TurnType
{
	public:
		TurnType();
		~TurnType();

		enum TYPE{ X, Y, Z };
		vector<Turn* > moves_;
};

