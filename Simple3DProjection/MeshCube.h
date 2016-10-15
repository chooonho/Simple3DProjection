#pragma once

#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "Mesh.h"

class MeshCube : public Mesh {
	private:
		GLdouble mSize;
	public:
		MeshCube();
		MeshCube(GLdouble size, ColorRGB3D color, Transform translate, Rotate rotate, Transform scale, bool isWireFrame);
		GLdouble getSize();
		void setSize(GLdouble size);
		virtual void draw();
};

#endif // MESH_CUBE_H