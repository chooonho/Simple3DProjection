#include "Rotate.h"

Rotate::Rotate()
{
	mAngle = 0.0;
}

Rotate::Rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	Transform(x, y, z);
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