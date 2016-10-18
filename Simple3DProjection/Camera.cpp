#include "Camera.h"

Camera::Camera()
{
	mPosition = { 0.0, 0.0, 0.0 };
}

Camera::Camera(Point3D position, Point3D lookAt)
{
	mPosition = position;
	mLookAt = lookAt;
}

Point3D Camera::getPosition()
{
	return mPosition;
}

Point3D Camera::getLookAt()
{
	return mLookAt;
}

Point3D Camera::getAngle()
{
	return mAngle;
}

GLdouble Camera::getPositionX()
{
	return mPosition.x;
}

GLdouble Camera::getPositionY()
{
	return mPosition.y;
}

GLdouble Camera::getPositionZ()
{
	return mPosition.z;
}

GLdouble Camera::getLookAtX()
{
	return mLookAt.x;
}

GLdouble Camera::getLookAtY()
{
	return mLookAt.y;
}

GLdouble Camera::getLookAtZ()
{
	return mLookAt.z;
}

GLdouble Camera::getAngleX()
{
	return mAngle.x;
}

GLdouble Camera::getAngleY()
{
	return mAngle.y;
}

GLdouble Camera::getAngleZ()
{
	return mAngle.z;
}

void Camera::setPosition(Point3D position)
{
	mPosition = position;
}

void Camera::setLookAt(Point3D lookAt)
{
	mLookAt = lookAt;
}

void Camera::setPositionX(GLdouble x)
{
	mPosition.x = x;
}

void Camera::setPositionY(GLdouble y)
{
	mPosition.y = y;
}

void Camera::setPositionZ(GLdouble z)
{
	mPosition.z = z;
}

void Camera::setLookAtX(GLdouble x)
{
	mLookAt.x = x;
}

void Camera::setLookAtY(GLdouble y)
{
	mLookAt.y = y;
}

void Camera::setLookAtZ(GLdouble z)
{
	mLookAt.z = z;
}

void Camera::setAngleX(GLdouble x)
{
	mAngle.x = x;
}

void Camera::setAngleY(GLdouble y)
{
	mAngle.y = y;
}

void Camera::setAngleZ(GLdouble z)
{
	mAngle.z = z;
}