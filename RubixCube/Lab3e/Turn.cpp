#include "Turn.h"

Turn::Turn(int turn[9], int type, float angle, int define)
{
	for (int i = 0; i < 9; i++)
	{
		turn_[i] = turn[i];
	}
	type_ = type;
	angle_ = angle;
	define_ = define;
}

Turn::~Turn()
{
}

void Turn::Move()
{

}