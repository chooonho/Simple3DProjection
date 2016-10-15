#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glut.h>

class Transform
{
	protected:
		GLdouble mX;
		GLdouble mY;
		GLdouble mZ;
	public:
		Transform();
		Transform(GLdouble x, GLdouble y, GLdouble z);
		GLdouble getX();
		GLdouble getY();
		GLdouble getZ();
		void setX(GLdouble x);
		void setY(GLdouble y);
		void setZ(GLdouble z);
		Transform& operator=(const Transform& rhTransform);
};

#endif