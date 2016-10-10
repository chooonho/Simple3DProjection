#pragma once

#ifndef MESH_SPHERE_H
#define MESH_SPHERE_H

#include "Mesh.h"

class MeshSphere : public Mesh {
	private:
		GLdouble mRadius;
		GLint mSliceCount;
		GLint mStackCount;
	public:
		MeshSphere();
		MeshSphere(GLdouble, GLint, GLint, ColorRGB3F, Transform, Rotate, Transform, bool);
		GLdouble getRadius();
		GLint getSliceCount();
		GLint getStackCount();
		void setRadius(GLdouble);
		void setSliceCount(GLint);
		void setStackCount(GLint);
		virtual void draw();
};

#endif // MESH_SPHERE_H