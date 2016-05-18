#pragma once

class Turn
{
	public:
		Turn(int turn[9], int type, float angle, int define);
		~Turn();
		void Move();
		int turn_[9];
		int type_;
		int define_;
		float angle_;
};

