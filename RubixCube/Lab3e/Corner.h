#pragma once
#include "Mesh.h"
#include "Piece.h"

class Corner : public Piece
{
	public:
		Corner(int color1, int color2, int color3, int piece);
		~Corner();
		void Render();
		inline void Reset(){ position_ = startPosition_; color1_ = startColor1_; color2_ = startColor2_; color3_ = startColor3_; };

	private:
		void CheckTurn(int type, int turns);
};

