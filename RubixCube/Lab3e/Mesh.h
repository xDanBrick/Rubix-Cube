#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>

#define PI 3.14

class Mesh
{
	public:
		Mesh();
		void RenderQuad(int color, int rot);
		void RenderSkyQuad(float x, float y, float z, GLuint texture, int rot, float tx, float ty);
		enum Rot{ front, up, right, diagonal, flipped, down, left, back};
		enum COLORS{RED, GREEN, ORANGE, YELLOW, WHITE, BLUE};

	private:
		float quadWidth;
};

