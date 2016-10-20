/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "Rotate.h"

// Constructor
Rotate::Rotate()
{
	mAngle = 0.0;
}

Rotate::Rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) : Transform(x, y, z)
{
	mAngle = angle;
}

// Getter function
GLdouble Rotate::getAngle()
{
	return mAngle;
}

// Setter function
void Rotate::setAngle(GLdouble angle)
{
	mAngle = angle;
}

// Overloaded assignment operator to allow direct assignment of object
Rotate& Rotate::operator=(const Rotate& rhRotate)
{
	if (this != &rhRotate)
	{
		this->mX = rhRotate.mX;
		this->mY = rhRotate.mY;
		this->mZ = rhRotate.mZ;
		this->mAngle = rhRotate.mAngle;
	}

	return *this;
}