#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <math.h>
#include "Vec3.h"

#define PI 3.14

class Camera
{
	public:
		// Methods
		Camera();
		~Camera();
		void Init(float, float, float, float, float, float);
		void MoveCameraYaw(float move_yaw);
		inline void ChangeCameraXTo(float camX) { cameraPosition.setX(camX); };
		inline void ChangeCameraYTo(float camY) { cameraPosition.setY(camY); };
		inline void ChangeCameraZTo(float camZ) { cameraPosition.setZ(camZ); };
		
		inline void MoveCameraX(float speed)			{ cameraPosition += (right *= speed); };
		inline void MoveCameraY(float speed)			{ cameraPosition += (upwardsPoint *= speed); };
		inline void MoveCameraZ(float speed)			{ cameraPosition += (forwardPoint *= speed); };
		inline void MoveCameraPitch(float movePitch)	{ cameraRotation.setX(cameraRotation.getX() + movePitch); };
		inline void MoveCameraRoll(float moveRoll)		{ cameraRotation.setZ(cameraRotation.getZ() + moveRoll); };

		inline float GetCameraX()	{ return cameraPosition.getX(); };
		inline float GetCameraY()	{ return cameraPosition.getY(); };
		inline float GetCameraZ()	{ return cameraPosition.getZ(); };
		inline float GetRotationX() { return cameraRotation.getX(); };
		inline float GetRotationY() { return cameraRotation.getY(); };
		inline float GetRotationZ() { return cameraRotation.getZ(); };
		inline float GetLookAtX()	{ return cameraPosition.getX() + forwardPoint.getX(); };
		inline float GetLookAtY()	{ return cameraPosition.getY() + forwardPoint.getY(); };
		inline float GetLookAtZ()	{ return cameraPosition.getZ() + forwardPoint.getZ(); };
		inline float GetUpPointX()	{ return upwardsPoint.getX(); };
		inline float GetUpPointY()	{ return upwardsPoint.getY(); };
		inline float GetUpPointZ()	{ return upwardsPoint.getZ(); };
		void Update();

	private:
		// Attributes.
		float cosX, cosY, cosZ;
		float sinX, sinY, sinZ;
		Vec3 cameraPosition;
		Vec3 cameraRotation;
		Vec3 forwardPoint;
		Vec3 upwardsPoint;
		Vec3 right;
};

#endif