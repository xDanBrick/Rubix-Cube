#include "TurnType.h"

int rightTurn1[9] = { R, FR, BR, RU, RD, FUR, FDR, BUR, BDR };
int middleTurn1[9] = { U, F, B, D, FU, BU, FD, BD, M };
int leftTurn1[9] = { L, FL, BL, LU, LD, FUL, FDL, BUL, BDL };

int upTurn1[9] = { U, RU, LU, FU, BU, FUR, FUL, BUR, BUL };
int midUpTurn1[9] = { F, B, R, L, FL, FR, BR, BL, M };
int downTurn1[9] = { D, LD, RD, FD, BD, FDL, BDL, BDR, FDR };

int frontTurn1[9] = { F, FR, FL, FU, FD, FUR, FDR, FUL, FDL };
int midFrontTurn1[9] = { U, R, L, D, RU, LU, RD, LD, M };
int backTurn1[9] = { B, BR, BL, BU, BD, BUR, BDR, BUL, BDL };

TurnType::TurnType()
{
	float turn = 90;
	int x[9];
	moves_.push_back(new Turn(rightTurn1, X, -turn, right));
	moves_.push_back(new Turn(rightTurn1, X, turn, rightIn));
	moves_.push_back(new Turn(middleTurn1, X, -turn, mid));
	moves_.push_back(new Turn(middleTurn1, X, turn, midIn));
	moves_.push_back(new Turn(leftTurn1, X, -turn, left));
	moves_.push_back(new Turn(leftTurn1, X, turn, leftIn));

	moves_.push_back(new Turn(upTurn1, Y, -turn, up));
	moves_.push_back(new Turn(upTurn1, Y, turn, upIn));
	moves_.push_back(new Turn(midUpTurn1, Y, -turn, midU));
	moves_.push_back(new Turn(midUpTurn1, Y, turn, midUIn));
	moves_.push_back(new Turn(downTurn1, Y, -turn, down));
	moves_.push_back(new Turn(downTurn1, Y, turn, downIn));

	moves_.push_back(new Turn(frontTurn1, Z, -turn, front));
	moves_.push_back(new Turn(frontTurn1, Z, turn, frontIn));
	moves_.push_back(new Turn(midFrontTurn1, Z, -turn, midF));
	moves_.push_back(new Turn(midFrontTurn1, Z, turn, midFIn));
	moves_.push_back(new Turn(backTurn1, Z, -turn, back));
	moves_.push_back(new Turn(backTurn1, Z, turn, backIn));
	moves_.push_back(new Turn(x, 0, 0.0f, 0));
}


TurnType::~TurnType()
{
}
