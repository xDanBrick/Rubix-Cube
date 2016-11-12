#pragma once
#include "Controller.h"
#include "Input.h"

class UserController : public Controller
{
	public:
		UserController(Input* input, Cube* cube);
		~UserController();
		
		void Update();
	private:
		Input* input_;
		void ChooseSide();

};

