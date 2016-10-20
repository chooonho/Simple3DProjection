/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "Transform.h"

// Constructor
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

// Getter function
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

// Setter function
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

// Overloaded assignment operator to allow direct assignment of object
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