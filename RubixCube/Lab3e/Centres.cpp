#include "Centres.h"

Centres::Centres(int color, int place)
{
	position_ = place;
	color_ = color;
	startPosition_ = place;
	startColor_ = color;
	type_ = CENTRE;
}

Centres::~Centres()
{
}

void Centres::CheckTurn(int type, int turns)
{
	if (type == XNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			switch (position_)
			{
				case F: position_ = U; break;
				case U: position_ = B; break;
				case B: position_ = D; break;
				case D: position_ = F; break;
			}
		}
	}
	else if (type == YNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			switch (position_)
			{
				case F: position_ = L; break;
				case L: position_ = B; break;
				case B: position_ = R; break;
				case R: position_ = F; break;
			}
		}
	}
	else if (type == ZNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			switch (position_)
			{
				case U: position_ = R; break;
				case R: position_ = D; break;
				case D: position_ = L; break;
				case L: position_ = U; break;
			}
		}
	}
}

void Centres::Render()
{
	int place = 0;
	Turn(Update());
	glPushMatrix();
		Rotate();
		switch (position_)
		{
			case U:  glTranslatef(0.0f, 3.0f, 1.0f); place = mesh.up; break;
			case D:  glTranslatef(0.0f, 0.0f, 1.0f); place = mesh.up;  break;
			case L:  glTranslatef(-1.0f, 1.0f, 2.0f); place = mesh.right;  break;
			case R: glTranslatef(2.0f, 1.0f, 2.0f); place = mesh.right;  break;
			case F: glTranslatef(0.0f, 1.0f, 3.0f); place = mesh.front;  break;
			case B: glTranslatef(0.0f, 1.0f, 0.0f); place = mesh.front;  break;
		}
		mesh.RenderQuad(color_, place);
	glPopMatrix();
}
