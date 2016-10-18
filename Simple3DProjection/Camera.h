#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>

struct Point3D
{
	GLdouble x;
	GLdouble y;
	GLdouble z;
};

class Camera
{
	private:
		Point3D mPosition;
		Point3D mLookAt;
		Point3D mAngle;
	public:
		Camera();
		Camera(Point3D position, Point3D lookAt);
		Point3D getPosition();
		Point3D getLookAt();
		Point3D getAngle();
		GLdouble getPositionX();
		GLdouble getPositionY();
		GLdouble getPositionZ();
		GLdouble getLookAtX();
		GLdouble getLookAtY();
		GLdouble getLookAtZ();
		GLdouble getAngleX();
		GLdouble getAngleY();
		GLdouble getAngleZ();
		void setPosition(Point3D position);
		void setLookAt(Point3D lookAt);
		void setPositionX(GLdouble x);
		void setPositionY(GLdouble y);
		void setPositionZ(GLdouble z);
		void setLookAtX(GLdouble x);
		void setLookAtY(GLdouble y);
		void setLookAtZ(GLdouble z);
		void setAngleX(GLdouble x);
		void setAngleY(GLdouble y);
		void setAngleZ(GLdouble z);
};

#endif