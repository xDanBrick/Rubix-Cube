#include "Scene3D.h"

bool Scene3D::CreatePixelFormat(HDC hdc) 
{ 
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    int pixelformat; 

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);	// Set the size of the structure
    pfd.nVersion = 1;							// Always set this to 1
	// Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;			// standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;				// RGB and Alpha pixel type
    pfd.cColorBits = COLOUR_DEPTH;				// Here we use our #define for the color bits
    pfd.cDepthBits = COLOUR_DEPTH;				// Ignored for RBA
    pfd.cAccumBits = 0;							// nothing for accumulation
    pfd.cStencilBits = COLOUR_DEPTH;						// nothing for stencil
 
	//Gets a best match on the pixel format as passed in from device
    if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == false ) 
    { 
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
	//sets the pixel format if its ok. 
    if (SetPixelFormat(hdc, pixelformat, &pfd) == false) 
    { 
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
    return true;
}

void Scene3D::ResizeGLWindow(int width, int height)// Initialize The GL Window
{
	if (height==0)// Prevent A Divide By Zero error
	{
		height=1;// Make the Height Equal One
	}
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//calculate aspect ratio
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 1 ,150.0f);

	glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
	glLoadIdentity();// Reset The Modelview Matrix
}

void Scene3D::InitializeOpenGL(int width, int height) 
{  
    hdc = GetDC(*hwnd);//  sets  global HDC

    if (!CreatePixelFormat(hdc))//  sets  pixel format
        PostQuitMessage (0);

    hrc = wglCreateContext(hdc);	//  creates  rendering context from  hdc
    wglMakeCurrent(hdc, hrc);		//	Use this HRC.

	ResizeGLWindow(width, height);	// Setup the Screen
}

void Scene3D::Init(HWND* wnd, Input* in, Camera* cam)
{
	hwnd = wnd;
	input = in;
	//Camera
	camera = cam;
	camera->Init(0.0f, 4.0f, 7.0f, 0.0f, 0.0f, 0.0f);
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations#
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	speed = 4.0f;
	sensitivity = 10.0f;
	GetClientRect(*hwnd, &screenRect);	//get rect into our handy global rect
	InitializeOpenGL(screenRect.right, screenRect.bottom); // initialise openGL
	application_ = new Application(in);
}



void Scene3D::DrawScene(float dt) 
{
	HandleInput(dt);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);// Clear The Screen And The Depth Buffer
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();// load Identity Matrix

	//Sets the camera to look at the current camera
	gluLookAt(camera->GetCameraX(), camera->GetCameraY(), camera->GetCameraZ(),
		camera->GetLookAtX(), camera->GetLookAtY(), camera->GetLookAtZ(),
		camera->GetUpPointX(), camera->GetUpPointY(), camera->GetUpPointZ());
	application_->Update();
	application_->Render();
	SwapBuffers(hdc);// Swap the frame buffers.
}		



void Scene3D::Resize()
{
	if(hwnd == NULL)
		return;

	GetClientRect(*hwnd, &screenRect);	
	ResizeGLWindow(screenRect.right, screenRect.bottom);	
}

void Scene3D::HandleInput(float dt)
{
	//For the main camera
	// Moving the camera up and down.
	if (input->isKeyDown(VK_UP))
	{
		camera->MoveCameraY(dt * speed);
	}
	if (input->isKeyDown(VK_DOWN))
	{
		camera->MoveCameraY(dt * -speed);
	}
	// Moving the camera forwards and backwards.
	if (input->isKeyDown('W'))
	{
		camera->MoveCameraZ(dt * speed);
	}
	if (input->isKeyDown('S'))
	{
		camera->MoveCameraZ(dt * -speed);
	}
	//Moving the camera left and right
	if (input->isKeyDown('A'))
	{
		camera->MoveCameraX(dt * -speed);
	}
	if (input->isKeyDown('D'))
	{
		camera->MoveCameraX(dt * speed);
	}
	int xDis, yDis;
	POINT windowCentre;
	windowCentre.x = screenRect.right * 0.5;
	windowCentre.y = screenRect.bottom * 0.5;
	//Distance the mouse has moved in the x-axis
	if (input->getMouseX() != windowCentre.x)
	{
		xDis = (input->getMouseX() - windowCentre.x);
		camera->MoveCameraYaw(dt * (sensitivity * xDis));
	}
	//Distance the mouse has moved in the y-axis
	if (input->getPreviousMouseY() != windowCentre.y)
	{
		yDis = (windowCentre.y - input->getMouseY());
		camera->MoveCameraPitch(dt * (sensitivity * yDis));
	}
	ClientToScreen(*hwnd, &windowCentre);
	//Resets the mouse to the centre
	SetCursorPos(windowCentre.x, windowCentre.y);
	camera->Update();
}
