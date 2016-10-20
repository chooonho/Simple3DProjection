/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#define DEG_TO_RAD 0.0174533
#define MIN_MAX_ROTATE_ANGLE 45.0
#define MIN_ZOOM 0.5
#define MAX_ZOOM 1.5

#include <GL/glut.h>

// Sturcture that stores a set of values (for x, y and z)
struct Point3D
{
	GLdouble x;
	GLdouble y;
	GLdouble z;
};

class Camera
{
	private:
		// Attributes
		Point3D mInitialPosition;
		Point3D mPosition;
		Point3D mLookAt;
		Point3D mAngle;
		GLdouble mZoom;
	public:
		// Constructor
		Camera();
		Camera(Point3D position, Point3D lookAt, Point3D angle, GLdouble zoom = 1.0);
		// Getter function
		Point3D getInitialPosition();
		Point3D getPosition();
		Point3D getLookAt();
		Point3D getAngle();
		GLdouble getInitialPositionX();
		GLdouble getInitialPositionY();
		GLdouble getInitialPositionZ();
		GLdouble getPositionX();
		GLdouble getPositionY();
		GLdouble getPositionZ();
		GLdouble getLookAtX();
		GLdouble getLookAtY();
		GLdouble getLookAtZ();
		GLdouble getAngleX();
		GLdouble getAngleY();
		GLdouble getAngleZ();
		GLdouble getZoom();
		// Setter function
		void setInitialPosition(Point3D initialPosition);
		void setPosition(Point3D position);
		void setLookAt(Point3D lookAt);
		void setAngle(Point3D angle);
		void setInitialPositionX(GLdouble x);
		void setInitialPositionY(GLdouble y);
		void setInitialPositionZ(GLdouble z);
		void setPositionX(GLdouble x);
		void setPositionY(GLdouble y);
		void setPositionZ(GLdouble z);
		void setLookAtX(GLdouble x);
		void setLookAtY(GLdouble y);
		void setLookAtZ(GLdouble z);
		void setAngleX(GLdouble x);
		void setAngleY(GLdouble y);
		void setAngleZ(GLdouble z);
		// Zooming in/out function
		void zoomIn(GLdouble increment = 0.1);
		void zoomOut(GLdouble decrement = 0.1);
		// Reset position function
		void resetToInitialPosition();
		// Rotation function
		void rotateX(GLdouble angle);
		void rotateY(GLdouble angle);
};

#endif