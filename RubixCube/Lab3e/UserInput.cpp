#include "UserInput.h"

int rightTurn[9] = { R, FR, BR, RU, RD, FUR, FDR, BUR, BDR };
int middleTurn[9] = { U, F, B, D, FU, BU, FD, BD, M };
int leftTurn[9] = { L, FL, BL, LU, LD, FUL, FDL, BUL, BDL };

int upTurn[9] = { U, RU, LU, FU, BU, FUR, FUL, BUR, BUL };
int midUpTurn[9] = { F, B, R, L, FL, FR, BR, BL, M };
int downTurn[9] = { D, LD, RD, FD, BD, FDL, BDL, BDR, FDR };

int frontTurn[9] = { F, FR, FL, FU, FD, FUR, FDR, FUL, FDL };
int midFrontTurn[9] = { U, R, L, D, RU, LU, RD, LD, M };
int backTurn[9] = { B, BR, BL, BU, BD, BUR, BDR, BUL, BDL };

UserInput::UserInput(Input* input, vector<Piece*>* cube)
{
	input_ = input;
	cube_ = cube;
}

UserInput::~UserInput()
{
}

void UserInput::Solve()
{
	ChooseSide();
	//If it not currently moving
	if (selected.size() > 0)
	{
		//Normal Turn
		if (input_->isKeyDown('Z'))
		{
			RotateSelected(-turn);
			input_->SetKeyUp('Z');
		}
		//Inverted Turn
		else if (input_->isKeyDown('X'))
		{
			RotateSelected(turn);
			input_->SetKeyUp('X');
		}
	}
}

void UserInput::ChooseSide()
{
	if (IsMoving() == false)
	{
		if (selected.size() == 0)
		{
			state_ = SOLVE;
		}
		//Left Turn
		if (input_->isKeyDown('1'))
		{
			SelectSide(leftTurn, X);
		}
		//Middle Turn
		if (input_->isKeyDown('2'))
		{
			SelectSide(middleTurn, X);
		}
		//Right Turn
		if (input_->isKeyDown('3'))
		{
			SelectSide(rightTurn, X);
		}
		//Up Turn
		if (input_->isKeyDown('4'))
		{
			SelectSide(upTurn, Y);
		}
		//Mid up Turn
		if (input_->isKeyDown('5'))
		{
			SelectSide(midUpTurn, Y);
		}
		//Down Turn
		if (input_->isKeyDown('6'))
		{
			SelectSide(downTurn, Y);
		}
		if (input_->isKeyDown('7'))
		{
			SelectSide(frontTurn, Z);
		}
		if (input_->isKeyDown('8'))
		{
			SelectSide(midFrontTurn, Z);
		}
		if (input_->isKeyDown('9'))
		{
			SelectSide(backTurn, Z);
		}
	}
}



