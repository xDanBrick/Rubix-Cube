#pragma once
#include "Mesh.h"
#include <vector>

using std::vector;
enum PLACE{ F = 0, R, U, D, L, B, FU, FD, FL, FR, BU, BD, BL, BR, RU, RD, LU, LD, FUR, FUL, FDR, FDL, BUR, BUL, BDR, BDL, M};
enum TYPE{ XNORMAL, YNORMAL, ZNORMAL, XINVERTED, YINVERTED, ZINVERTED};
enum PIECETYPE{CENTRE, EDGE, CORNER};

class Piece
{
	public:
		Piece();
		~Piece();
		virtual void Render() = 0;
		virtual void Reset() = 0;
		bool IsSolved();
		inline void SetStartAngleX(float angle){ startAngleX_ = angle; };
		inline void SetStartAngleY(float angle){ startAngleY_ = angle; };
		inline void SetStartAngleZ(float angle){ startAngleZ_ = angle; };
		inline float GetAngleX(){ return angleX_; };
		inline float GetAngleY(){ return angleY_; };
		inline float GetAngleZ(){ return angleZ_; };
		inline int GetPosition(){ return position_; };
		inline int GetStartPosition(){ return startPosition_; };
		inline void SelectPiece(){ isSelected = true; };
		inline bool InStartingPosition(){ if (position_ == startPosition_ && color1_ == startColor1_ && color2_ == startColor2_){ return true; }; return false; };
		int color1_, color2_, color3_;
		int color1Dir_;
		int startColor1_, startColor2_, startColor3_;
		int color_;
		int startColor_;
		int type_;
		bool solved_;
		bool flipped_;
		bool beingSolved;
		int stuckPosition_;
		inline bool IsFlipped(){ if (position_ == startPosition_ && color1_ != startColor1_){ return true; } return false; };
		int topColor_;
		bool facing_;
		void FlipPosition();

	protected:
		void Rotate();
		float speed_;
		float angleX_, angleY_, angleZ_;
		int turnCounter_;
		float startAngleX_, startAngleY_, startAngleZ_;
		int startPosition_;
		int position_;
		bool isSelected;
		virtual void CheckTurn(int type, int turns) = 0;
		void Turn(int type);
		int Update();
		Mesh mesh;
};

