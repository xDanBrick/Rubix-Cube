#pragma once
#include "Cube.h"
#include "UserController.h"
class Application
{
	public:
		Application(Input* input);
		~Application();
		void Update();
		void Render();
		

	private:
		void HandleInput();
		Input* input_;
		Cube* cube_;
		//AIController* solver_;
		UserController* userInput_;
		Controller* controller_;
};

