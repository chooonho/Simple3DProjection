#pragma once

#ifndef MESH_CONE_H
#define MESH_CONE_H

#include "Mesh.h"

class MeshCone : public Mesh {
private:
	GLdouble mBase;
	GLdouble mHeight;
	GLint mSliceCount;
	GLint mStackCount;
public:
	MeshCone();
	MeshCone(GLdouble base, GLdouble height, GLint sliceCount, GLint stackCount, ColorRGB3D color,
				Transform translate,Rotate rotate, Transform scale, bool isWireFrame);
	GLdouble getBase();
	GLdouble getHeight();
	GLint getSliceCount();
	GLint getStackCount();
	void setBase(GLdouble base);
	void setHeight(GLdouble height);
	void setSliceCount(GLint sliceCount);
	void setStackCount(GLint stackCount);
	virtual void draw();
};

#endif // MESH_CONE_H
