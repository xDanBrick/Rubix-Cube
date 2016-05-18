#include "Piece.h"

Piece::Piece()
{
	isSelected = false;
	angleX_ = 0.0f;
	angleY_ = 0.0f;
	angleZ_ = 0.0f;
	startAngleX_ = 0.0f;
	startAngleY_ = 0.0f;
	startAngleZ_ = 0.0f;
	turnCounter_ = 0;
	speed_ = 0.0f;
	solved_ = false;
	flipped_ = false;
	beingSolved = false;	
	stuckPosition_ = 0;
}

void Piece::Turn(int type)
{
	switch (type)
	{
		case XNORMAL: CheckTurn(XNORMAL, 1); break;
		case YNORMAL: CheckTurn(YNORMAL, 1); break;
		case ZNORMAL: CheckTurn(ZNORMAL, 1); break;
		case XINVERTED: CheckTurn(XNORMAL, 3); break;
		case YINVERTED: CheckTurn(YNORMAL, 3); break;
		case ZINVERTED: CheckTurn(ZNORMAL, 3); break;
	}
}

Piece::~Piece()
{
}

void Piece::Rotate()
{
	glTranslatef(0.0f, 1.5f, 1.5f);
	glRotatef(angleX_, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -1.5f, -1.5f);

	glTranslatef(0.5f, 0.0f, 1.5f);
	glRotatef(angleY_, 0.0f, 1.0f, 0.0f);
	glTranslatef(-0.5f, 0.0f, -1.5f);

	glTranslatef(0.5f, 1.5f, 0.0f);
	glRotatef(angleZ_, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.5f, -1.5f, 0.0f);
}

bool Piece::IsSolved()
{
	if (position_ == startPosition_ && color1_ == startColor1_ && color2_ == startColor2_)
	{
		return true;
	}
	else return false;
}

void Piece::FlipPosition()
{

}

int Piece::Update()
{
	if (angleX_ > startAngleX_)
	{
		angleX_ -= speed_;
		if (angleX_ == startAngleX_)
		{
			startAngleX_ = 0.0f;
			angleX_ = 0.0f;
			return XNORMAL;
		}
	}
	else if (angleY_ > startAngleY_)
	{
		angleY_ -= speed_;
		if (angleY_ == startAngleY_)
		{
			startAngleY_ = 0.0f;
			angleY_ = 0.0f;
			return YNORMAL;
		}
	}
	else if (angleZ_ > startAngleZ_)
	{
		angleZ_ -= speed_;
		if (angleZ_ == startAngleZ_)
		{
			startAngleZ_ = 0.0f;
			angleZ_ = 0.0f;
			return ZNORMAL;
		}
	}
	else if (angleX_ < startAngleX_)
	{
		angleX_ += speed_;
		if (angleX_ == startAngleX_)
		{
			startAngleX_ = 0.0f;
			angleX_ = 0.0f;
			return XINVERTED;
		}
	}
	else if (angleY_ < startAngleY_)
	{
		angleY_ += speed_;
		if (angleY_ == startAngleY_)
		{
			startAngleY_ = 0.0f;
			angleY_ = 0.0f;
			return YINVERTED;
		}
	}
	else if (angleZ_ < startAngleZ_)
	{
		angleZ_ += speed_;
		if (angleZ_ == startAngleZ_)
		{
			startAngleZ_ = 0.0f;
			angleZ_ = 0.0f;
			return ZINVERTED;
		}
	}
	return 50;
}