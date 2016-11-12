#pragma once
#include "Controller.h"
#include "Turn.h"
#include "CrossState.h"

class AIController : public Controller
{
	public:
		AIController(Input* input, Cube* cube);
		~AIController();
		void Solve();
		SolveState* currentState_;
		void Update() {};
};

