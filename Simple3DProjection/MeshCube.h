#pragma once

#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "Mesh.h"

class MeshCube : public Mesh {
	private:
		GLdouble mSize;
	public:
		MeshCube();
		MeshCube(GLdouble, ColorRGB3F, Transform, Rotate, Transform, bool);
		GLdouble getSize();
		void setSize(GLdouble);
		virtual void draw();
};

#endif // MESH_CUBE_H