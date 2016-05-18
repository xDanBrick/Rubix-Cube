#ifndef _SHAPE_H
#define _SHAPE_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>
#include "Mesh.h"
#include "Camera.h"

#define PI 3.14

class Shape
{
	public:
		Shape();
		void RenderCube(float x, float y, float z, float width, float height, float depth, GLuint texture);
		void RenderSphere(float x, float y, float z, int segments);
		void RenderCylinder(float x, float y, float z, int segments, float width, float height, GLuint texture, int rot);
		void RenderSkyBox(GLuint texture, Camera* camera);
		void RenderPallet(float x, float y, float z, float width, float height, float depth, GLuint texture, int rot);

		enum Type{skybox, crate};
		enum Rot{front, up, right};
		Mesh mesh;
		GLuint skyBox;

};
#endif 
