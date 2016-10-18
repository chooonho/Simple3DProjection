#include "Camera.h"
#include <math.h>

Camera::Camera()
{
	mInitialPosition = { 0.0, 0.0, 0.0 };
	mPosition = { 0.0, 0.0, 0.0 };
	mLookAt = { 0.0, 0.0, 0.0 };
	mAngle = { 0.0, 0.0, 0.0 };
	mZoom = 1.0;
}

Camera::Camera(Point3D position, Point3D lookAt, Point3D angle, GLdouble zoom)
{
	mInitialPosition = position;
	mPosition = position;
	mLookAt = lookAt;
	mAngle = angle;
	mZoom = zoom;
}

Point3D Camera::getInitialPosition()
{
	return mInitialPosition;
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

GLdouble Camera::getInitialPositionX()
{
	return mInitialPosition.x;
}

GLdouble Camera::getInitialPositionY()
{
	return mInitialPosition.y;
}

GLdouble Camera::getInitialPositionZ()
{
	return mInitialPosition.z;
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

GLdouble Camera::getZoom()
{
	return mZoom;
}

void Camera::setInitialPosition(Point3D initialPosition)
{
	mInitialPosition = initialPosition;
}

void Camera::setPosition(Point3D position)
{
	mPosition = position;
}

void Camera::setLookAt(Point3D lookAt)
{
	mLookAt = lookAt;
}

void Camera::setAngle(Point3D angle)
{
	mAngle = angle;
}

void Camera::setInitialPositionX(GLdouble x)
{
	mInitialPosition.x = x;
}

void Camera::setInitialPositionY(GLdouble y)
{
	mInitialPosition.y = y;
}

void Camera::setInitialPositionZ(GLdouble z)
{
	mInitialPosition.z = z;
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

void Camera::zoomIn(GLdouble increment)
{
	if ((mZoom - increment) <= MIN_ZOOM)
	{
		return;
	}

	mZoom -= increment;

	mPosition.x = (mInitialPosition.z * sin(DEG_TO_RAD * mAngle.x)) * mZoom;
	mPosition.y = (mInitialPosition.y + mInitialPosition.z * sin(DEG_TO_RAD * mAngle.y)) * mZoom;
	mPosition.z = ((mInitialPosition.z * cos(DEG_TO_RAD * mAngle.x)) * cos(DEG_TO_RAD * mAngle.y)) * mZoom;
}

void Camera::zoomOut(GLdouble decrement)
{
	if ((mZoom + decrement) >= MAX_ZOOM)
	{
		return;
	}

	mZoom += decrement;

	mPosition.x = (mInitialPosition.z * sin(DEG_TO_RAD * mAngle.x)) * mZoom;
	mPosition.y = (mInitialPosition.y + mInitialPosition.z * sin(DEG_TO_RAD * mAngle.y)) * mZoom;
	mPosition.z = ((mInitialPosition.z * cos(DEG_TO_RAD * mAngle.x)) * cos(DEG_TO_RAD * mAngle.y)) * mZoom;
}

void Camera::resetToInitialPosition()
{
	mPosition = mInitialPosition;
}

// Rotate with angle x
void Camera::rotateX(GLdouble angle)
{
	if (angle <= -(MIN_MAX_ROTATE_ANGLE) || angle >= MIN_MAX_ROTATE_ANGLE)
	{
		return;
	}

	mAngle.x = angle;

	mPosition.x = (mInitialPosition.z * sin(DEG_TO_RAD * angle)) * mZoom;
	mPosition.z = ((mInitialPosition.z * cos(DEG_TO_RAD * mAngle.y)) * cos(DEG_TO_RAD * angle)) * mZoom;
}

// Rotate with angle y
void Camera::rotateY(GLdouble angle)
{
	if (angle <= -(MIN_MAX_ROTATE_ANGLE) || angle >= MIN_MAX_ROTATE_ANGLE)
	{
		return;
	}

	mAngle.y = angle;

	mPosition.y = (mInitialPosition.y + mInitialPosition.z * sin(DEG_TO_RAD * angle)) * mZoom;
	mPosition.z = ((mInitialPosition.z * cos(DEG_TO_RAD * mAngle.x)) * cos(DEG_TO_RAD * angle)) * mZoom;
}