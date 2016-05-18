#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Init(float cam_x, float cam_y, float cam_z, float x_rot, float y_rot, float z_rot)
{
	cameraPosition.set(cam_x, cam_y, cam_z);
	cameraRotation.set(x_rot, y_rot, z_rot);
}

void Camera::MoveCameraYaw(float moveYaw)		
{
	cameraRotation.setY(cameraRotation.getY() + moveYaw); 
};
void Camera::Update()
{
	cosX = cosf(cameraRotation.getX() * PI / 180.0f);
	cosY = cosf(cameraRotation.getY() * PI / 180.0f);
	cosZ = cosf(cameraRotation.getZ() * PI / 180.0f);

	sinX = sinf(cameraRotation.getX() * PI / 180.0f);
	sinY = sinf(cameraRotation.getY()* PI / 180.0f);
	sinZ = sinf(cameraRotation.getZ() * PI / 180.0f);

	// Forward vector.
	forwardPoint.setX(sinY * cosX);
	forwardPoint.setY(sinX);
	forwardPoint.setZ(cosX * -cosY);

	// Up vector.
	upwardsPoint.setX(-cosY * sinZ - sinY * sinX * cosZ);
	upwardsPoint.setY(cosX * cosZ);
	upwardsPoint.setZ(-sinY * sinZ - sinX * cosZ * -cosY);

	// Cross product of up.
	right = forwardPoint.cross(upwardsPoint);
}