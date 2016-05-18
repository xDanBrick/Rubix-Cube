// Input class

#include "Input.h"


void Input::SetKeyDown(WPARAM key)
{
	keys[key] = true;
}

void Input::SetKeyUp(WPARAM key)
{
	keys[key] = false;
}

bool Input::isKeyDown(int key)
{
	return keys[key];
}

void Input::setMouseX(int pos)
{
	mouse.x = pos;
}

void Input::setMouseY(int pos)
{
	mouse.y = pos;
}
void Input::setMouse(int x, int y)
{
	SetCursorPos(x, y);
}
int Input::getMouseX()
{
	return mouse.x;
}

int Input::getMouseY()
{
	return mouse.y;
}

int Input::getPreviousMouseX()
{
	return prevMouse.x;
}

int Input::getPreviousMouseY()
{
	return prevMouse.y;
}

void Input::SetPrevMouse()
{
	prevMouse.x = mouse.x;
	prevMouse.y = mouse.y;
}

