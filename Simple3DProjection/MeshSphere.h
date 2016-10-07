#pragma once

#ifndef MESH_SPHERE_H
#define MESH_SPHERE_H

#include <GL/glut.h>
#include "Mesh.h"

class MeshSphere : Mesh {
	private:
		GLdouble mRadius;
		GLint mSliceCount;
		GLint mStackCount;
	public:
		MeshSphere();
		MeshSphere(GLdouble, GLint, GLint, ColorRGB3F, Transform, Transform, Transform, bool);
		GLdouble getRadius();
		GLint getSliceCount();
		GLint getStackCount();
		void setRadius(GLdouble);
		void setSliceCount(GLint);
		void setStackCount(GLint);
		virtual void draw();
};

#endif // MESH_SPHERE_H