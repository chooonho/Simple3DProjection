#include "MeshTeapot.h"

MeshTeapot::MeshTeapot()
{
	mSize = 0.0;
	setIsWireFrame(false);
}

MeshTeapot::MeshTeapot(GLdouble size, ColorRGBA4D color, Transform translate, Rotate rotate, Transform scale, bool isWireFrame)
{
	mSize = size;
	setColor(color);
	setTranslate(translate);
	setRotate(rotate);
	setScale(scale);
	setIsWireFrame(isWireFrame);
}

GLdouble MeshTeapot::getSize()
{
	return mSize;
}

void MeshTeapot::setSize(GLdouble size)
{
	mSize = size;
}

void MeshTeapot::draw()
{
	glPushMatrix();
		glColor4d(getColor().red, getColor().green, getColor().blue, getColor().alpha);
		glTranslated(getTranslateX(), getTranslateY(), getTranslateZ());
		glRotated(getRotateAngle(), getRotateX(), getRotateY(), getRotateZ());
		glScaled(getScaleX(), getScaleY(), getScaleZ());

		if (getIsWireFrame())
		{
			glutWireTeapot(mSize);
		}
		else
		{
			glutSolidTeapot(mSize);
		}
	glPopMatrix();
}