/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "MeshSphere.h"

// Constructor
MeshSphere::MeshSphere()
{
	mRadius = 0.0;
	mSliceCount = 0;
	mStackCount = 0;
	setIsWireFrame(false);
}

MeshSphere::MeshSphere(GLdouble radius, GLint sliceCount, GLint stackCount, ColorRGBA4D color,
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

// Getter function
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

// Setter function
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

// Overloaded virtual draw function
void MeshSphere::draw()
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
			glutWireSphere(mRadius, mSliceCount, mStackCount);
		}
		else
		{
			glutSolidSphere(mRadius, mSliceCount, mStackCount);
		}
	glPopMatrix();
}