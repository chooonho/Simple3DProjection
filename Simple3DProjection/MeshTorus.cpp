/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "MeshTorus.h"

// Constructor
MeshTorus::MeshTorus()
{
	mInnerRadius = 0;
	mOuterRadius = 0;
	mNSideCount = 0;
	mRingCount = 0;
	setIsWireFrame(false);
}

MeshTorus::MeshTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nSideCount, GLint ringCount, ColorRGBA4D color,
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

// Getter function
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

// Setter function
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

// Overriden virtual draw function
void MeshTorus::draw()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, getMaterial().getAmbient());
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, getMaterial().getDiffuse());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, getMaterial().getSpecular());
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, getMaterial().getShine());
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, getMaterial().getEmission());

	glPushMatrix();
		glColor4d(getColor().red, getColor().green, getColor().blue, getColor().alpha);
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