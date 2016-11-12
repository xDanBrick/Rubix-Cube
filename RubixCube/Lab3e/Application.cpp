#include "Application.h"

Application::Application(Input* input)
{
	input_ = input;
	cube_ = new Cube();
	//solver_ = new AIController(input, &cube_);
	userInput_ = new UserController(input, cube_);
	controller_ = userInput_;
}


Application::~Application()
{
	
}

void Application::Update()
{
	HandleInput();
	controller_->Update();
	cube_->Update();
}

void Application::Render()
{
	cube_->Render();
}

void Application::HandleInput()
{
	if (input_->isKeyDown('M'))
	{
		cube_->MixCube();
	}
	if (input_->isKeyDown('R'))
	{
		cube_->Reset();
	}
}
