#include "MeshSphere.h"

MeshSphere::MeshSphere()
{
	mRadius = 0.0;
	mSliceCount = 0;
	mStackCount = 0;
	setIsWireFrame(false);
}

MeshSphere::MeshSphere(GLdouble radius, GLint sliceCount, GLint stackCount, ColorRGB3D color,
						Transform translate, Rotate rotate, Transform scale, bool isWireFrame)
{
	mRadius = radius;
	mSliceCount = sliceCount;
	mStackCount = stackCount;
	setColor(color);
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
	glPushMatrix();
		glColor3d(getColor().red, getColor().green, getColor().blue);
		glTranslated(getTranslateX(), getTranslateY(), getTranslateZ());
		glRotated(getRotateAngle(), getRotateX(), getRotateY(), getRotateZ());
		glScaled(getScaleX(), getScaleY(), getScaleZ());

		if (getIsWireFrame())
		{
			glutWireSphere(mRadius, mSliceCount, mStackCount);
		}
		else
		{
			glutSolidSphere(mRadius, mSliceCount, mStackCount);
		}
	glPopMatrix();
}