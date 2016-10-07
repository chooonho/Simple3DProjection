#include "MeshSphere.h"

MeshSphere::MeshSphere()
{
	mRadius = 0.0;
	mSliceCount = 0.0;
	mStackCount = 0.0;
	setIsWireFrame(false);
}

MeshSphere::MeshSphere(GLdouble radius, GLint sliceCount, GLint stackCount,
						Transform translate, Transform rotate, Transform scale, bool isWireFrame)
{
	mRadius = radius;
	mSliceCount = sliceCount;
	mStackCount = stackCount;
	setTranslate(translate);
	setRotate(rotate);
	setScale(scale);
	setIsWireFrame(isWireFrame);
}

GLdouble MeshSphere::getRadius()
{
	return mRadius;
}

GLint MeshSphere::getSliceCount()
{
	return mSliceCount;
}

GLint MeshSphere::getStackCount()
{
	return mStackCount;
}

void MeshSphere::setRadius(GLdouble radius)
{
	mRadius = radius;
}

void MeshSphere::setSliceCount(GLint sliceCount)
{
	mSliceCount = sliceCount;
}

void MeshSphere::setStackCount(GLint stackCount)
{
	mStackCount = stackCount;
}

void MeshSphere::draw()
{
	if (getIsWireFrame())
	{
		glutWireSphere(mRadius, mSliceCount, mStackCount);
	}
	else
	{
		glutSolidSphere(mRadius, mSliceCount, mStackCount);
	}
}