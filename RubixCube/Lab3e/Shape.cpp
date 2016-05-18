#include "Shape.h"

Shape::Shape()
{
}

void Shape::RenderCube(float x, float y, float z, float width, float height, float depth, GLuint texture)
{
}

void Shape::RenderSkyBox(GLuint texture, Camera* camera)
{	
	//Puts it into a dlist
	skyBox = glGenLists(1);
	glNewList(skyBox, GL_COMPILE);
			glBindTexture(GL_TEXTURE_2D, texture);	//tells opengl which texture to use
			glPushMatrix();
				glScalef(3.0f, 3.0f, 3.0f);
				glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
				glDisable(GL_DEPTH_TEST);
					mesh.RenderSkyQuad(0.0f, 0.0f, 0.0f, texture, mesh.front, 0.0f, 0.25f);
					mesh.RenderSkyQuad(0.0f, 0.0f, -1.0f, texture, mesh.front, 0.5f, 0.25f);
					mesh.RenderSkyQuad(0.0f, 0.0f, 0.0f, texture, mesh.right, 0.25f, 0.25f);
					mesh.RenderSkyQuad(1.0f, 0.0f, 0.0f, texture, mesh.right, 0.75f, 0.25f);
					mesh.RenderSkyQuad(0.0f, 0.0f, -1.0f, texture, mesh.up, 0.25f, 0.0f);
					mesh.RenderSkyQuad(0.0f, 1.0f, -1.0f, texture, mesh.up, 0.25f, 0.5f);
			glPopMatrix();
		glEnable(GL_DEPTH_TEST);

	glEndList();
}

