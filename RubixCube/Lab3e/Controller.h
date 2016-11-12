#pragma once
#include <vector>
#include "Piece.h"
#include "Turn.h"
#include "Cube.h"

using std::vector;

class Controller
{
	public:
		Controller(Cube* cube);
		~Controller();
		Cube* cube_;
		virtual void Update() = 0;

	private:
		
};

