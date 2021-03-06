/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "MeshCone.h"

// Constructor
MeshCone::MeshCone()
{
	mBase = 0;
	mHeight = 0;
	mSliceCount = 0;
	mStackCount = 0;
	setIsWireFrame(false);
}

MeshCone::MeshCone(GLdouble base, GLdouble height, GLint sliceCount, GLint stackCount, ColorRGBA4D color,
					Transform translate, Rotate rotate, Transform scale, bool isWireFrame)
{
	mBase = base;
	mHeight = height;
	mSliceCount = sliceCount;
	mStackCount = stackCount;
	setColor(color);
	setTranslate(translate);
	setRotate(rotate);
	setScale(scale);
	setIsWireFrame(isWireFrame);
}

// Getter function
GLdouble MeshCone::getBase()
{
	return mBase;
}

GLdouble MeshCone::getHeight()
{
	return mHeight;
}

GLint MeshCone::getSliceCount()
{
	return mSliceCount;
}

GLint MeshCone::getStackCount()
{
	return mStackCount;
}

// Setter function
void MeshCone::setBase(GLdouble base)
{
	mBase = base;
}

void MeshCone::setHeight(GLdouble height)
{
	mHeight = height;
}

void MeshCone::setSliceCount(GLint sliceCount)
{
	mSliceCount = sliceCount;
}

void MeshCone::setStackCount(GLint stackCount)
{
	mStackCount = stackCount;
}

// Overriden virtual draw function
void MeshCone::draw()
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
			glutWireCone(mBase, mHeight, mSliceCount, mStackCount);
		}
		else
		{
			glutSolidCone(mBase, mHeight, mSliceCount, mStackCount);
		}
	glPopMatrix();
}