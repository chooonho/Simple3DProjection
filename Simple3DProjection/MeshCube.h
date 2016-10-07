#pragma once

#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include <GL/glut.h>
#include "Mesh.h"

class MeshCube : Mesh {
	private:
		GLdouble mSize;
		bool mIsWireFrame;
	public:
		MeshCube();
		virtual void draw();
};

#endif // MESH_CUBE_H