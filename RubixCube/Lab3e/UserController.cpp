#include "UserController.h"

int rightTurn1[9] = { R, FR, BR, RU, RD, FUR, FDR, BUR, BDR };
int middleTurn1[9] = { U, F, B, D, FU, BU, FD, BD, M };
int leftTurn1[9] = { L, FL, BL, LU, LD, FUL, FDL, BUL, BDL };

int upTurn1[9] = { U, RU, LU, FU, BU, FUR, FUL, BUR, BUL };
int midUpTurn1[9] = { F, B, R, L, FL, FR, BR, BL, M };
int downTurn1[9] = { D, LD, RD, FD, BD, FDL, BDL, BDR, FDR };

int frontTurn1[9] = { F, FR, FL, FU, FD, FUR, FDR, FUL, FDL };
int midFrontTurn1[9] = { U, R, L, D, RU, LU, RD, LD, M };
int backTurn1[9] = { B, BR, BL, BU, BD, BUR, BDR, BUL, BDL };

UserController::UserController(Input* input, Cube* cube) : Controller(cube)
{
	input_ = input;
}

UserController::~UserController()
{
}

void UserController::Update()
{
	ChooseSide();
	if (cube_->selected_.size() > 0)
	{
		//Normal Turn
		if (input_->isKeyDown('Z'))
		{
			cube_->RotateSelected(-90.0f);
			input_->SetKeyUp('Z');
		}
		//Inverted Turn
		else if (input_->isKeyDown('X'))
		{
			cube_->RotateSelected(90.0f);
			input_->SetKeyUp('X');
		}
	}
}

void UserController::ChooseSide()
{
	if (cube_->IsMoving() == false)
	{
		//Left Turn
		if (input_->isKeyDown('1'))
		{
			cube_->SelectSide(leftTurn1, X);
		}
		//Middle Turn
		if (input_->isKeyDown('2'))
		{
			cube_->SelectSide(middleTurn1, X);
		}
		//Right Turn
		if (input_->isKeyDown('3'))
		{
			cube_->SelectSide(rightTurn1, X);
		}
		//Up Turn
		if (input_->isKeyDown('4'))
		{
			cube_->SelectSide(upTurn1, Y);
		}
		//Mid up Turn
		if (input_->isKeyDown('5'))
		{
			cube_->SelectSide(midUpTurn1, Y);
		}
		//Down Turn
		if (input_->isKeyDown('6'))
		{
			cube_->SelectSide(downTurn1, Y);
		}
		if (input_->isKeyDown('7'))
		{
			cube_->SelectSide(frontTurn1, Z);
		}
		if (input_->isKeyDown('8'))
		{
			cube_->SelectSide(midFrontTurn1, Z);
		}
		if (input_->isKeyDown('9'))
		{
			cube_->SelectSide(backTurn1, Z);
		}
	}
}



