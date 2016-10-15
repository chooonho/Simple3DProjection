#include "MeshTorus.h"

MeshTorus::MeshTorus()
{
	mInnerRadius = 0;
	mOuterRadius = 0;
	mNSideCount = 0;
	mRingCount = 0;
	setIsWireFrame(false);
}

MeshTorus::MeshTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nSideCount, GLint ringCount, ColorRGB3F color,
						Transform translate, Rotate rotate, Transform scale, bool isWireFrame)
{
	mInnerRadius = innerRadius;
	mOuterRadius = outerRadius;
	mNSideCount = nSideCount;
	mRingCount = ringCount;
	setColor(color);
	setTranslate(translate);
	setRotate(rotate);
	setScale(scale);
	setIsWireFrame(isWireFrame);
}

GLdouble MeshTorus::getInnerRadius()
{
	return mInnerRadius;
}

GLdouble MeshTorus::getOuterRadius()
{
	return mOuterRadius;
}

GLint MeshTorus::getNSideCount()
{
	return mNSideCount;
}

GLint MeshTorus::getRingCount()
{
	return mRingCount;
}

void MeshTorus::setInnerRadius(GLdouble innerRadius)
{
	mInnerRadius = innerRadius;
}

void MeshTorus::setOuterRadius(GLdouble outerRadius)
{
	mOuterRadius = outerRadius;
}

void MeshTorus::setNSideCount(GLint nSideCount)
{
	mNSideCount = nSideCount;
}

void MeshTorus::setRingCount(GLint ringCount)
{
	mRingCount = ringCount;
}

void MeshTorus::draw()
{
	glPushMatrix();
		glColor3f(getColor().red, getColor().green, getColor().blue);
		glTranslated(getTranslateX(), getTranslateY(), getTranslateZ());
		glRotated(getRotateAngle(), getRotateX(), getRotateY(), getRotateZ());
		glScaled(getScaleX(), getScaleY(), getScaleZ());

		if (getIsWireFrame())
		{
			glutWireTorus(mInnerRadius, mOuterRadius, mNSideCount, mRingCount);
		}
		else
		{
			glutSolidTorus(mInnerRadius, mOuterRadius, mNSideCount, mRingCount);
		}
	glPopMatrix();
}