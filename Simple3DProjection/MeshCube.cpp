/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "MeshCube.h"

// Constructor
MeshCube::MeshCube()
{
	mSize = 0.0;
	setIsWireFrame(false);
}

MeshCube::MeshCube(GLdouble size, ColorRGBA4D color, Transform translate, Rotate rotate, Transform scale, bool isWireFrame)
{
	mSize = size;
	setColor(color);
	setTranslate(translate);
	setRotate(rotate);
	setScale(scale);
	setIsWireFrame(isWireFrame);
}

// Getter function
GLdouble MeshCube::getSize()
{
	return mSize;
}

// Setter function
void MeshCube::setSize(GLdouble size)
{
	mSize = size;
}

// Overriden virtual draw function
void MeshCube::draw()
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
			glutWireCube(mSize);
		}
		else
		{
			glutSolidCube(mSize);
		}
	glPopMatrix();
}