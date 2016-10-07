#pragma once

#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include <GL/glut.h>
#include "Mesh.h"

class MeshCube : Mesh {
	private:
		GLdouble mSize;
	public:
		MeshCube();
		MeshCube(GLdouble, Transform, Transform, Transform, bool);
		GLdouble getSize();
		void setSize(GLdouble);
		virtual void draw();
};

#endif // MESH_CUBE_H