#include "Cube.h"

#define MIXER_MAX 15

int rightTurn[9] = { R, FR, BR, RU, RD, FUR, FDR, BUR, BDR };
int middleTurn[9] = { U, F, B, D, FU, BU, FD, BD, M };
int leftTurn[9] = { L, FL, BL, LU, LD, FUL, FDL, BUL, BDL };

int upTurn[9] = { U, RU, LU, FU, BU, FUR, FUL, BUR, BUL };
int midUpTurn[9] = { F, B, R, L, FL, FR, BR, BL, M };
int downTurn[9] = { D, LD, RD, FD, BD, FDL, BDL, BDR, FDR };

int frontTurn[9] = { F, FR, FL, FU, FD, FUR, FDR, FUL, FDL };
int midFrontTurn[9] = { U, R, L, D, RU, LU, RD, LD, M };
int backTurn[9] = { B, BR, BL, BU, BD, BUR, BDR, BUL, BDL };

Cube::Cube()
{
	cube_.push_back(new Edge(mesh.ORANGE, mesh.BLUE, BD));
	cube_.push_back(new Edge(mesh.GREEN, mesh.ORANGE, BU));
	cube_.push_back(new Edge(mesh.ORANGE, mesh.WHITE, BR));
	cube_.push_back(new Edge(mesh.ORANGE, mesh.YELLOW, BL));
	cube_.push_back(new Edge(mesh.RED, mesh.BLUE, FD));
	cube_.push_back(new Edge(mesh.GREEN, mesh.RED, FU));
	cube_.push_back(new Edge(mesh.WHITE, mesh.RED, FR));
	cube_.push_back(new Edge(mesh.RED, mesh.YELLOW, FL));
	cube_.push_back(new Edge(mesh.GREEN, mesh.WHITE, RU));
	cube_.push_back(new Edge(mesh.YELLOW, mesh.BLUE, LD));
	cube_.push_back(new Edge(mesh.GREEN, mesh.YELLOW, LU));
	cube_.push_back(new Edge(mesh.WHITE, mesh.BLUE, RD));

	cube_.push_back(new Corner(mesh.YELLOW, mesh.BLUE, mesh.ORANGE, BDL));
	cube_.push_back(new Corner(mesh.YELLOW, mesh.ORANGE, mesh.GREEN, BUL));
	cube_.push_back(new Corner(mesh.WHITE, mesh.BLUE, mesh.RED, FDR));
	cube_.push_back(new Corner(mesh.BLUE, mesh.WHITE, mesh.ORANGE, BDR));
	cube_.push_back(new Corner(mesh.WHITE, mesh.GREEN, mesh.ORANGE, BUR));
	cube_.push_back(new Corner(mesh.WHITE, mesh.RED, mesh.GREEN, FUR));
	cube_.push_back(new Corner(mesh.YELLOW, mesh.GREEN, mesh.RED, FUL));
	cube_.push_back(new Corner(mesh.RED, mesh.BLUE, mesh.YELLOW, FDL));

	cube_.push_back(new Centres(mesh.YELLOW, L));
	cube_.push_back(new Centres(mesh.RED, F));
	cube_.push_back(new Centres(mesh.ORANGE, B));
	cube_.push_back(new Centres(mesh.GREEN, U));
	cube_.push_back(new Centres(mesh.BLUE, D));
	cube_.push_back(new Centres(mesh.WHITE, R));
	float turn = 90;
	int x[9];

	moves_.push_back(new Turn(rightTurn, X, -turn, right));
	moves_.push_back(new Turn(rightTurn, X, turn, rightIn));
	moves_.push_back(new Turn(middleTurn, X, -turn, mid));
	moves_.push_back(new Turn(middleTurn, X, turn, midIn));
	moves_.push_back(new Turn(leftTurn, X, -turn, left));
	moves_.push_back(new Turn(leftTurn, X, turn, leftIn));

	moves_.push_back(new Turn(upTurn, Y, -turn, up));
	moves_.push_back(new Turn(upTurn, Y, turn, upIn));
	moves_.push_back(new Turn(midUpTurn, Y, -turn, midU));
	moves_.push_back(new Turn(midUpTurn, Y, turn, midUIn));
	moves_.push_back(new Turn(downTurn, Y, -turn, down));
	moves_.push_back(new Turn(downTurn, Y, turn, downIn));

	moves_.push_back(new Turn(frontTurn, Z, -turn, front));
	moves_.push_back(new Turn(frontTurn, Z, turn, frontIn));
	moves_.push_back(new Turn(midFrontTurn, Z, -turn, midF));
	moves_.push_back(new Turn(midFrontTurn, Z, turn, midFIn));
	moves_.push_back(new Turn(backTurn, Z, -turn, back));
	moves_.push_back(new Turn(backTurn, Z, turn, backIn));
	moves_.push_back(new Turn(x, 0, 0.0f, 0));
	mixerTurn_ = 0;
	isMoving_ = false;
	currentTurn_ = 0;

	mixing_ = false;
	doingAlgorithm_ = false;
}

Cube::~Cube()
{
}

void Cube::Render()
{
	for (int i = 0; i < cube_.size(); i++)
	{
		cube_[i]->Render();
	}
}


void Cube::Reset()
{
	for (int i = 0; i < cube_.size(); i++)
	{
		cube_.at(i)->Reset();
	}
	currentTurn_ = 0;
}

void Cube::Update()
{
	if(state_ == WAIT)
	{
		if (doingAlgorithm_)
		{

		}
	}
	else if (state_ == TURN)
	{
		if (IsMoving() == false)
		{
			state_ = WAIT;
		}
	}
}

void Cube::DoAlgorithm()
{

}

bool Cube::IsMoving()
{
	for (int i = 0; i < selected_.size(); i++)
	{
		if (selected_[i]->GetAngleX() == 0.0f && selected_[i]->GetAngleY() == 0.0f && selected_[i]->GetAngleZ() == 0.0f)
		{
			return false;
		}
	}
	return isMoving_;
}

void Cube::SelectSide(int side[9], int type)
{
	selected_.clear();
	AddToSelected(side);
	type_ = type;
}

void Cube::RotateSelected(float angle)
{
	isMoving_ = true;
	for (int i = 0; i < selected_.size(); i++)
	{
		if (type_ == X)
		{
			selected_[i]->SetStartAngleX(angle);
		}
		else if (type_ == Y)
		{
			selected_[i]->SetStartAngleY(angle);
		}
		else if (type_ == Z)
		{
			selected_[i]->SetStartAngleZ(angle);
		}
	}
}

void Cube::MakeTurn(Turn* turn)
{
	SelectSide(turn->turn_, turn->type_);
	RotateSelected(turn->angle_);
	state_ = TURN;
}

void Cube::Mix()
{
	if (mixerTurn_ < MIXER_MAX)
	{
		int random = rand() % 18;
		MakeTurn(moves_[random]);
		mixerTurn_++;
	}
	else
	{
		state_ = WAIT;
		mixerTurn_ = 0;
	}
}

void Cube::AddToSelected(int turn[9])
{
	for (int i = 0; i < cube_.size(); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (cube_.at(i)->GetPosition() == turn[j])
			{
				SelectPiece(cube_.at(i));
			}
		}
	}
}

