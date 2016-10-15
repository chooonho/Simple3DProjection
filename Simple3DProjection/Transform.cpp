
#include "Transform.h"

Transform::Transform()
{
	mX = 0;
	mY = 0;
	mZ = 0;
}

Transform::Transform(GLdouble x, GLdouble y, GLdouble z)
{
	mX = x;
	mY = y;
	mZ = z;
}

GLdouble Transform::getX()
{
	return mX;
}

GLdouble Transform::getY()
{
	return mY;
}

GLdouble Transform::getZ()
{
	return mZ;
}

void Transform::setX(GLdouble x)
{
	mX = x;
}

void Transform::setY(GLdouble y)
{
	mY = y;
}

void Transform::setZ(GLdouble z)
{
	mZ = z;
}

Transform& Transform::operator=(const Transform& rhTransform)
{
	if (this != &rhTransform)
	{
		this->mX = rhTransform.mX;
		this->mY = rhTransform.mY;
		this->mZ = rhTransform.mZ;
	}

	return *this;
}