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
		Transform(GLdouble, GLdouble, GLdouble);
		GLdouble getX();
		GLdouble getY();
		GLdouble getZ();
		void setX(GLdouble);
		void setY(GLdouble);
		void setZ(GLdouble);
		Transform& operator=(const Transform&);
};

#endif