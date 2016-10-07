#include "MeshCube.h"

MeshCube::MeshCube()
{
	mSize = 0.0;
	mIsWireFrame = false;
}

void MeshCube::draw()
{
	if (mIsWireFrame)
	{
		glutWireCube(mSize);
	}
	else
	{
		glutSolidCube(mSize);
	}
}