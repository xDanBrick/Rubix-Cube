#pragma once
#include "Mesh.h"
#include "Piece.h"

class Centres : public Piece
{
	public:
		Centres(int color, int place);
		~Centres();
		void Render();
		inline void Reset(){ position_ = startPosition_; color_ = startColor_; };

	private:
		void CheckTurn(int type, int turns);
};

