#include "CubeInput.h"

CubeInput::CubeInput()
{
	turn = 90.0f;
	isMoving_ = false;
	currentTurn_ = 0;
	mixerTurn_ = 0;
	mixerMax_ = 15;
	state_ = WAIT;
	turnType_ = new TurnType();
}


CubeInput::~CubeInput()
{
}

void CubeInput::Mix()
{
	if (mixerTurn_ < mixerMax_)
	{
		if (IsMoving() == false)
		{
			int random = rand() % 18;
			MakeTurn(turnType_->moves_[random]);
			mixerTurn_++;
		}
	}
	else
	{
		state_ = WAIT;
		mixerTurn_ = 0;
	}
}

void CubeInput::MakeTurn(Turn* turn)
{
	SelectSide(turn->turn_, turn->type_);
	RotateSelected(turn->angle_);
}

void CubeInput::AddToSelected(int turn[9])
{
	for (int i = 0; i < cube_->size(); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (cube_->at(i)->GetPosition() == turn[j])
			{
				SelectPiece(cube_->at(i));
			}
		}
	}
}


void CubeInput::SelectSide(int side[9], int type)
{
	selected.clear();
	AddToSelected(side);
	type_ = type;
}

void CubeInput::RotateSelected(float angle)
{
	isMoving_ = true;
	for (int i = 0; i < selected.size(); i++)
	{
		if (type_ == X)
		{
			selected[i]->SetStartAngleX(angle);
		}
		else if (type_ == Y)
		{
			selected[i]->SetStartAngleY(angle);
		}
		else if (type_ == Z)
		{
			selected[i]->SetStartAngleZ(angle);
		}
	}
}

bool CubeInput::IsMoving()
{
	for (int i = 0; i < selected.size(); i++)
	{
		if (selected[i]->GetAngleX() == 0.0f && selected[i]->GetAngleY() == 0.0f && selected[i]->GetAngleZ() == 0.0f)
		{
			return false;
		}
	}
	return isMoving_;
}


void CubeInput::Update()
{
	if (input_->isKeyDown(VK_SPACE))
	{
		for (int i = 0; i < cube_->size(); i++)
		{
			cube_->at(i)->Reset();
		}
		currentTurn_ = 0;
		state_ = WAIT;
	}
	switch (state_)
	{
		case MIX: Mix(); break;
		case SOLVE: Solve(); break;
		case SEXY: Sexy(); break;
		case WAIT: Wait(); break;
	}
}

void CubeInput::Sexy()
{

}

void CubeInput::Wait()
{
	if (input_->isKeyDown('H'))
	{
		state_ = MIX;
	}
	if (input_->isKeyDown('J'))
	{
		state_ = SOLVE;
	}
	if (input_->isKeyDown('K'))
	{
		state_ = SEXY;
	}
}

