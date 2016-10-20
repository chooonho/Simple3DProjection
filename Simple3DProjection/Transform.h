/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glut.h>

class Transform
{
	protected:
		// Attributes
		GLdouble mX;
		GLdouble mY;
		GLdouble mZ;
	public:
		// Constructor
		Transform();
		Transform(GLdouble x, GLdouble y, GLdouble z);
		// Getter function
		GLdouble getX();
		GLdouble getY();
		GLdouble getZ();
		// Setter function
		void setX(GLdouble x);
		void setY(GLdouble y);
		void setZ(GLdouble z);
		// Overloaded assignment operator to allow direct assignment of object
		Transform& operator=(const Transform& rhTransform);
};

#endif