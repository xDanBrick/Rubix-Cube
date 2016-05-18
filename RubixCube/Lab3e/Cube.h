#pragma once
#include "Edge.h"
#include "Corner.h"
#include "Mesh.h"
#include "Input.h"
#include "Centres.h"
#include <vector>
#include "Piece.h"
#include "UserInput.h"
#include "Solver.h"

using std::vector;

class Cube
{
	public:
		Cube();
		~Cube();
		void Render();
		void Init(Input* in);
		Mesh mesh;
		Input* in_;
		vector<Piece*> cube;
		CubeInput* input_;
		void UpdateInput();
		void Mix();
		void Solve();
		void Manual();
		Solver* solver_;;
		UserInput* userInput_;
};

