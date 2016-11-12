#ifndef SCENE3D_H
#define SCENE3D_H

#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "Input.h"
#include "SOIL.h"
#include "Camera.h"
#include "Mesh.h"
#include "Application.h"

#define COLOUR_DEPTH 16	//Colour depth

class Scene3D
{
public:
	void Init(HWND*, Input*, Camera*);	//initialse function
	void DrawScene(float);	// render scene
	void Resize();

protected:
	bool CreatePixelFormat(HDC);
	void ResizeGLWindow(int, int);	//width and height
	void InitializeOpenGL(int, int); // width and height
	void HandleInput(float dt);

	//vars
	HWND* hwnd;
	Input* input;
	Camera* camera;
	RECT screenRect;
	HDC	hdc;
	HGLRC hrc;			//hardware RENDERING CONTEXT
	Application* application_;
	float speed, sensitivity;
};

#endif