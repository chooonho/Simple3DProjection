#include "MeshCube.h"

MeshCube::MeshCube()
{
	mSize = 0.0;
	setIsWireFrame(false);
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