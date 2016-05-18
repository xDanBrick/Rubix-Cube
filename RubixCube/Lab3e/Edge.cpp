#include "Edge.h"

Edge::Edge(int color1, int color2, int place)
{
	color1_ = color1;
	color2_ = color2;
	position_ = place;
	startPosition_ = place;
	startColor1_ = color1;
	startColor2_ = color2;
	type_ = EDGE;
	color1Dir_ = 0;
	//facing_ = facing;
}

Edge::~Edge()
{
}

void Edge::CheckTurn(int type, int turns)
{
	if (type == XNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			int c1 = color1_;
			int c2 = color2_;
			switch (position_)
			{
				case RU: position_ = BR; break;
				case RD: position_ = FR; break;
				case FR: position_ = RU; color1_ = c2; color2_ = c1; break;
				case BR: position_ = RD; color1_ = c2; color2_ = c1; break;

				case FU: position_ = BU; color1_ = c2; color2_ = c1; break;
				case BU: position_ = BD; break;
				case BD: position_ = FD; color1_ = c2; color2_ = c1; break;
				case FD: position_ = FU; break;

				case LU: position_ = BL; break;
				case LD: position_ = FL; color1_ = c2; color2_ = c1; break;
				case FL: position_ = LU; break;
				case BL: position_ = LD; color1_ = c2; color2_ = c1; break;
			}
		}
	}
	else if (type == YNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			int c1 = color1_;
			int c2 = color2_;
			switch (position_)
			{
				case FU: position_ = LU; break;
				case RU: position_ = FU; break;
				case BU: position_ = RU; break;
				case LU: position_ = BU; break;

				case FL: position_ = BL;  color1_ = c2; color2_ = c1; break;
				case BL: position_ = BR;  color1_ = c2; color2_ = c1; break;
				case BR: position_ = FR; break;
				case FR: position_ = FL; break;

				case FD: position_ = LD; break;
				case RD: position_ = FD; break;
				case BD: position_ = RD; break;
				case LD: position_ = BD; break;
			}
		}
	}
	else 
	{
		for (int i = 0; i < turns; i++)
		{
			int c1 = color1_;
			int c2 = color2_;
			switch (position_)
			{
				case FU: position_ = FR; break;
				case FR: position_ = FD; color1_ = c2; color2_ = c1; break;
				case FD: position_ = FL; break;
				case FL: position_ = FU; color1_ = c2; color2_ = c1; break;

				case RU: position_ = RD; break;
				case RD: position_ = LD; color1_ = c2; color2_ = c1;  break;
				case LD: position_ = LU; break;
				case LU: position_ = RU; color1_ = c2; color2_ = c1; break;

				case BU: position_ = BR; color1_ = c2; color2_ = c1;  break;
				case BR: position_ = BD; break;
				case BD: position_ = BL; break;
				case BL: position_ = BU; color1_ = c2; color2_ = c1; break;
			}
		}
	}
}

void Edge::Render()
{
	Turn(Update());
	glPushMatrix();
		Rotate();
		switch (position_)
		{
			case BD:  break;
			case BU: glRotatef(90.0f, 1.0f, 0.0f, 0.0f); glTranslatef(0.0f, 0.0f, -3.0f); break;
			case BL: glRotatef(-90.0f, 0.0f, 0.0f, 1.0f); glTranslatef(-2.0f, -1.0f, 0.0f); break;
			case BR: glRotatef(90.0f, 0.0f, 0.0f, 1.0f); glTranslatef(1.0f, -2.0f, 0.0f); break; 

			case FD:  glRotatef(180.0f, 1.0f, 0.0f, 0.0f); glRotatef(180.0f, 0.0f, 0.0f, 1.0f); glTranslatef(-1.0f, 0.0f, -3.0f); break;
			case FU: glRotatef(90.0f, 1.0f, 0.0f, 0.0f); glRotatef(180.0f, 0.0f, 0.0f, 1.0f); glTranslatef(-1.0f, -3.0f, -3.0f); break;
			case FL: glRotatef(90.0f, 0.0f, 0.0f, 1.0f); glRotatef(-180.0f, 1.0f, 0.0f, 0.0f); glTranslatef(1.0f, -1.0f, -3.0f); break;
			case FR: glRotatef(90.0f, 0.0f, 0.0f, 1.0f); glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); glTranslatef(1.0f, -3.0f, -2.0f); break;

			case RU: glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); glRotatef(90.0f, 1.0f, 0.0f, 0.0f); glTranslatef(1.0f, -2.0f, -3.0f); break;
			case RD: glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); glTranslatef(1.0f, 0.0f, -2.0f); break;
			case LU: glRotatef(-90.0f, 0.0f, 0.0f, 1.0f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  glTranslatef(-2.0f, -1.0f, -3.0f); break;
			case LD: glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); glRotatef(180.0f, 0.0f, 1.0f, 0.0f); glTranslatef(-2.0f, 0.0f, -1.0f); break;
		}
		mesh.RenderQuad(color1_, mesh.front);
		mesh.RenderQuad(color2_, mesh.up);
	glPopMatrix();
}
