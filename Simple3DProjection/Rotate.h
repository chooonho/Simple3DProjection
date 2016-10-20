/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef ROTATE_H
#define ROTATE_H

#include <GL/glut.h>
#include "Transform.h"

class Rotate : public Transform
{
	private:
		// Attribute
		GLdouble mAngle;
	public:
		// Constructor
		Rotate();
		Rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
		// Getter function
		GLdouble getAngle();
		// Setter function
		void setAngle(GLdouble angle);
		// Overloaded assignment operator to allow direct assignment of object
		Rotate& operator=(const Rotate& rhRotate);
};

#endif
