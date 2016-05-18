#include "Cube.h"

Cube::Cube()
{
}

Cube::~Cube()
{
}

void Cube::Init(Input* in)
{
	in_ = in;
	cube.push_back(new Edge(mesh.ORANGE, mesh.BLUE, BD));
	cube.push_back(new Edge(mesh.GREEN, mesh.ORANGE, BU));
	cube.push_back(new Edge(mesh.ORANGE, mesh.WHITE, BR));
	cube.push_back(new Edge(mesh.ORANGE, mesh.YELLOW, BL));
	cube.push_back(new Edge(mesh.RED, mesh.BLUE, FD));
	cube.push_back(new Edge(mesh.GREEN, mesh.RED, FU));
	cube.push_back(new Edge(mesh.WHITE, mesh.RED, FR));
	cube.push_back(new Edge(mesh.RED, mesh.YELLOW, FL));
	cube.push_back(new Edge(mesh.GREEN, mesh.WHITE, RU));
	cube.push_back(new Edge(mesh.YELLOW, mesh.BLUE, LD));
	cube.push_back(new Edge(mesh.GREEN, mesh.YELLOW, LU));
	cube.push_back(new Edge(mesh.WHITE, mesh.BLUE, RD));

	cube.push_back(new Corner(mesh.YELLOW, mesh.BLUE, mesh.ORANGE, BDL));
	cube.push_back(new Corner(mesh.YELLOW, mesh.ORANGE, mesh.GREEN, BUL));
	cube.push_back(new Corner(mesh.WHITE, mesh.BLUE, mesh.RED, FDR));
	cube.push_back(new Corner(mesh.BLUE, mesh.WHITE, mesh.ORANGE, BDR));
	cube.push_back(new Corner(mesh.WHITE, mesh.GREEN, mesh.ORANGE, BUR));
	cube.push_back(new Corner(mesh.WHITE, mesh.RED, mesh.GREEN, FUR));
	cube.push_back(new Corner(mesh.YELLOW, mesh.GREEN, mesh.RED, FUL));
	cube.push_back(new Corner(mesh.RED, mesh.BLUE, mesh.YELLOW, FDL));

	cube.push_back(new Centres(mesh.YELLOW, L));
	cube.push_back(new Centres(mesh.RED, F));
	cube.push_back(new Centres(mesh.ORANGE, B));
	cube.push_back(new Centres(mesh.GREEN, U));
	cube.push_back(new Centres(mesh.BLUE, D));
	cube.push_back(new Centres(mesh.WHITE, R));

	solver_ = new Solver(in_, &cube);
	userInput_ = new UserInput(in_, &cube);
	input_ = userInput_;
}

void Cube::Render()
{
	UpdateInput();
	input_->Update();
	for (int i = 0; i < cube.size(); i++)
	{
		cube[i]->Render();
	}
}

void Cube::UpdateInput()
{
	if (in_->isKeyDown(VK_RIGHT))
	{
		input_ = solver_;
	}
	if (in_->isKeyDown(VK_LEFT))
	{
		input_ = userInput_;
	}
}
