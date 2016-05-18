// 3D Example Application
// Paul Robertson 2014


//Include
#include <windows.h>
#include <stdio.h>
#include "Input.h"
#include <mmsystem.h>
#include <math.h>
#include "Scene3D.h"
#include "timerclass.h"
#include "Camera.h"

//Globals
HWND hwnd; 
Input myInput;
Scene3D myScene;
TimerClass timer;
Camera myCamera;

//Prototypes
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
BOOL WaitFor(unsigned long delay);


//code
void RegisterMyWindow(HINSTANCE hInstance)
{
    WNDCLASSEX  wcex;									

    wcex.cbSize        = sizeof (wcex);				
    wcex.style         = CS_HREDRAW | CS_VREDRAW;		
    wcex.lpfnWndProc   = WndProc;						
    wcex.cbClsExtra    = 0;								
    wcex.cbWndExtra    = 0;								
    wcex.hInstance     = hInstance;						
    wcex.hIcon         = 0; 
    wcex.hCursor       = LoadCursor (NULL, IDC_ARROW);	
															
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
    wcex.lpszMenuName  = NULL;							
    wcex.lpszClassName = "FirstWindowClass";				
    wcex.hIconSm       = 0; 

	RegisterClassEx (&wcex);							
}


BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
  
   hwnd = CreateWindow ("FirstWindowClass",					
						 "Warehouse",		  	
						 WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME,	
						 CW_USEDEFAULT,			
						 CW_USEDEFAULT,			
						 1200,			
						 800,			
						 NULL,					
						 NULL,					
						 hInstance,				
						 NULL);								
	if (!hwnd)
	{
		return FALSE;
	}

    ShowWindow (hwnd, nCmdShow);						
    UpdateWindow (hwnd);									
	return TRUE;

}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)			
{									
    MSG         msg;	

	RegisterMyWindow(hInstance);

   	if (!InitialiseMyWindow(hInstance, nCmdShow))
	return FALSE;

	myScene.Init(&hwnd, &myInput, &myCamera);
	timer.Initialize();
	
	while (TRUE)					
    {							
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
		    if (msg.message==WM_QUIT)
				break;
			TranslateMessage (&msg);							
			DispatchMessage (&msg);
		}
		else
		{	
			timer.Frame();
			if(myInput.isKeyDown(VK_ESCAPE))
			{
				break;
			}
			
			myScene.DrawScene(timer.GetTime());
		}
    }
  
	return msg.wParam ;										
}

				
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)											
    {														
		case WM_CREATE:		
			break;

		case WM_SIZE:
			myScene.Resize();
			break;	

		case WM_KEYDOWN:
			myInput.SetKeyDown(wParam);
			break;

		case WM_KEYUP:
			myInput.SetKeyUp(wParam);
			break;

		case WM_MOUSEMOVE:
			myInput.setMouseX(LOWORD (lParam));
			myInput.setMouseY(HIWORD (lParam));
			break;

		case WM_LBUTTONDOWN:	
			break;

		case WM_PAINT:
		    break;		

		case WM_DESTROY:	
			
			PostQuitMessage(0);	
								
			break;				
	}													

	return DefWindowProc (hwnd, message, wParam, lParam);		
															
}

