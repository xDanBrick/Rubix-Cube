#include "Corner.h"

Corner::Corner(int color1, int color2, int color3, int piece)
{
	color1_ = color1;
	color2_ = color2;
	color3_ = color3;
	position_  = piece;
	startPosition_ = piece;
	startColor1_ = color1;
	startColor2_ = color2;
	startColor3_ = color3;
	type_ = CORNER;
}

Corner::~Corner()
{
}

void Corner::CheckTurn(int type, int turns)
{
	if (type == XNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			int c1 = color1_;
			int c2 = color2_;
			int c3 = color3_;
			switch (position_)
			{
				case FDR: position_ = FUR; color2_ = c2; color3_ = c3; break;
				case FUR: position_ = BUR; color2_ = c2; color3_ = c3; break;
				case BDR: position_ = FDR; color1_ = c2; color2_ = c3; color3_ = c1; break;
				case BUR: position_ = BDR; color1_ = c3; color2_ = c1; color3_ = c2; break;

				case FDL: position_ = FUL; color1_ = c3; color2_ = c1; color3_ = c2; break;
				case FUL: position_ = BUL; break;
				case BDL: position_ = FDL; color1_ = c2; color2_ = c3; color3_ = c1; break;
				case BUL: position_ = BDL;  break;
			}
		}
	}
	else if(type == YNORMAL)
	{
		for (int i = 0; i < turns; i++)
		{
			int c1 = color1_;
			int c2 = color2_;
			int c3 = color3_;
			switch (position_)
			{
				case FUL: position_ = BUL; color1_ = c3; color2_ = c1; color3_ = c2; break;
				case FUR: position_ = FUL; color1_ = c2; color2_ = c3; color3_ = c1; break;
				case BUL: position_ = BUR; color1_ = c2; color2_ = c3; color3_ = c1; break;
				case BUR: position_ = FUR; color1_ = c3; color2_ = c1; color3_ = c2; break;

				case FDL: position_ = BDL;  break;
				case FDR: position_ = FDL; break;
				case BDL: position_ = BDR; color1_ = c2; color2_ = c3; color3_ = c1; break;
				case BDR: position_ = FDR; color1_ = c3; color2_ = c1; color3_ = c2; break;
			}
		}
	}
	else
	{
		for (int i = 0; i < turns; i++)
		{
			int c1 = color1_;
			int c2 = color2_;
			int c3 = color3_;
			switch (position_)
			{
				case FUL: position_ = FUR; color1_ = c2; color2_ = c3; color3_ = c1; break;
				case FUR: position_ = FDR; color1_ = c3; color2_ = c1; color3_ = c2; break;
				case FDR: position_ = FDL; color1_ = c3; color2_ = c1; color3_ = c2; break;
				case FDL: position_ = FUL; color1_ = c2; color2_ = c3; color3_ = c1; break;

				case BUL: position_ = BUR; color1_ = c3; color2_ = c1; color3_ = c2; break;
				case BUR: position_ = BDR; break;
				case BDR: position_ = BDL; break;
				case BDL: position_ = BUL; color1_ = c2; color2_ = c3; color3_ = c1; break;
			}
		}
	}
}

void Corner::Render()
{
	Turn(Update());
	glPushMatrix();
		Rotate();
		switch (position_)
		{
			case FUR: glRotatef(180.0f, 0.0f, 1.0f, 0.0f); glRotatef(90.0f, 1.0f, 0.0f, 0.0f); glTranslatef(-2.0f, -3.0f, -3.0f); break;
			case FDR: glRotatef(180.0f, 0.0f, 1.0f, 0.0f); glTranslatef(-2.0f, 0.0f, -3.0f); break;
			case BUR: glRotatef(180.0f, 0.0f, 0.0f, 1.0f); glTranslatef(-2.0f, -3.0f, 0.0f); break; 
			case FUL: glRotatef(180.0f, 1.0f, 0.0f, 0.0f); glTranslatef(-1.0f, -3.0f, -3.0f); break;

			case FDL:  glRotatef(90.0f, 0.0f, 1.0f, 0.0f); glTranslatef(-3.0f, 0.0f, -1.0f); break;
			case BDL:  glTranslatef(-1.0f, 0.0f, 0.0f); break;
			case BDR: glRotatef(90.0f, 0.0f, 0.0f, 1.0f); glTranslatef(0.0f, -2.0f, 0.0f); break;
			case BUL: glRotatef(90.0f, 1.0f, 0.0f, 0.0f); glTranslatef(-1.0f, 0.0f, -3.0f); break;
		}
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, 1.0f);
			mesh.RenderQuad(color1_, mesh.right);
		glPopMatrix();
		mesh.RenderQuad(color2_, mesh.up);
		mesh.RenderQuad(color3_, mesh.front);
	glPopMatrix();
}
