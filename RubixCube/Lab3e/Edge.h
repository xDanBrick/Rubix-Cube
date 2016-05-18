#pragma once
#include "Mesh.h"
#include "Piece.h"

class Edge : public Piece
{
	public:
		Edge(int color1, int color2, int place);
		~Edge();
		void Render();
		inline void Reset(){ position_ = startPosition_; color1_ = startColor1_; color2_ = startColor2_; }
		void CheckTurn(int type, int turns);
	private:
};

