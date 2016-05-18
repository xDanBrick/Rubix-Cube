#include "Mesh.h"

Mesh::Mesh()
{
	quadWidth = 10.0f;
}


//Standard quad using vetex arrays
void Mesh::RenderQuad(int color, int rot)
{
	
	switch (color)
	{
		case BLUE: glColor3f(0.0f, 0.0f, 1.0f); break;
		case GREEN: glColor3f(0.0f, 1.0f, 0.0f); break;
		case WHITE: glColor3f(1.0f, 1.0f, 1.0f); break;
		case YELLOW: glColor3f(1.0f, 1.0f, 0.0f); break;
		case RED: glColor3f(1.0f, 0.0f, 0.0f); break;
		case ORANGE: glColor3f(1.0f, 0.5f, 0.0f); break;
	}
	glPushMatrix();
			switch (rot)
			{
				case front:
				{
					glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
					break;
				}
				case right:
				{
					glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
					break;
				}
				case up:
				{
					glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
					break;
				}
			}
			glBegin(GL_TRIANGLES);
			glVertex3f(0.0f, 0.0f, 0.0f);

			glVertex3f(0.0f, 1.0f, 0.0f);

			glVertex3f(1.0f, 0.0f, 0.0f);

			glVertex3f(1.0f, 1.0f, 0.0f);

			glVertex3f(1.0f, 0.0f, 0.0f);

			glVertex3f(0.0f, 1.0f, 0.0f);
			glEnd();
		glPopMatrix();
	
}

//Renders a quads used for the skybox
void Mesh::RenderSkyQuad(float x, float y, float z, GLuint texture, int rot, float tx, float ty)
{
	//Size of each skybox square
	float texSize = 0.25;
	glPushMatrix();
		glTranslatef(x, y, z);
		//Depemding on the rotation
		switch (rot)
		{
			case front:
			{
				glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
				break;
			}
			case right:
			{
				glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
				break;
			}
			case up:
			{
				glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				break;
			}
		}
		//Draws the quad
		glBegin(GL_TRIANGLES);
			glTexCoord2f(tx, ty);
			glVertex3f(0.0f, 0.0f, 0.0f);

			glTexCoord2f(tx, ty + texSize);
			glVertex3f(0.0f, 1.0f, 0.0f);

			glTexCoord2f(tx + texSize, ty);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glTexCoord2f(tx + texSize, ty + texSize);
			glVertex3f(1.0f, 1.0f, 0.0f);

			glTexCoord2f(tx + texSize, ty);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glTexCoord2f(tx, ty+texSize);
			glVertex3f(0.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
}