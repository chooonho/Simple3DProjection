#include "MeshCube.h"

MeshCube::MeshCube()
{
	mSize = 0.0;
	setIsWireFrame(false);
}

MeshCube::MeshCube(GLdouble size, ColorRGB3F color, Transform translate, Rotate rotate, Transform scale, bool isWireFrame)
{
	mSize = size;
	setColor(color);
	setTranslate(translate);
	setRotate(rotate);
	setScale(scale);
	setIsWireFrame(isWireFrame);
}

GLdouble MeshCube::getSize()
{
	return mSize;
}

void MeshCube::setSize(GLdouble size)
{
	mSize = size;
}

void MeshCube::draw()
{
	glPushMatrix();
		glColor3f(getColor().red, getColor().green, getColor().blue);
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