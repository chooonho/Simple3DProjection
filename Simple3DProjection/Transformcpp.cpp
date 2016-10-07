
#include "Transform.h"

Transform::Transform()
{
	mX = 0;
	mY = 0;
	mZ = 0;
}

Transform::Transform(double x, double y, double z)
{
	mX = x;
	mY = y;
	mZ = z;
}

double Transform::getX()
{
	return mX;
}

double Transform::getY()
{
	return mY;
}

double Transform::getZ()
{
	return mZ;
}

void Transform::setX(double x)
{
	mX = x;
}

void Transform::setY(double y)
{
	mY = y;
}

void Transform::setZ(double z)
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