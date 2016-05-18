#pragma once
#include "CubeInput.h"

class UserInput : public CubeInput
{
	public:
		UserInput(Input* input, vector<Piece*>* cube);
		~UserInput();
		void ChooseSide();
		void Solve();
};

