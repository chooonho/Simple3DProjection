#include "MeshCube.h"

MeshCube::MeshCube()
{
	mSize = 0.0;
	setIsWireFrame(false);
}

MeshCube::MeshCube(GLdouble size, Transform translate, Transform rotate, Transform scale, bool isWireFrame)
{
	mSize = size;
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
	if (getIsWireFrame())
	{
		glutWireCube(mSize);
	}
	else
	{
		glutSolidCube(mSize);
	}
}