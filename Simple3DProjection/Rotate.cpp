#include "Rotate.h"

Rotate::Rotate()
{
	mAngle = 0.0;
}

Rotate::Rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) : Transform(x, y, z)
{
	mAngle = angle;
}

GLdouble Rotate::getAngle()
{
	return mAngle;
}

void Rotate::setAngle(GLdouble angle)
{
	mAngle = angle;
}

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